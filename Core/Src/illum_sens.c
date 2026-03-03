#include "include.h"

/**
  * @brief Функция чтения значения освещенности с PmodALS
  * @return 8-битное значение освещенности (0-255)
  */
float PmodALS_Read_illum(void)
{
    uint8_t tx_data[2] = {0x00, 0x00};  // Передаем пустые байты для генерации тактов
    uint8_t rx_data[2];        // Буфер для приема 16 бит
    uint16_t raw_value;
    float illum_lux;
    
    // Устанавливаем CS в 0 (активируем датчик)
    HAL_GPIO_WritePin(PIN_SPI_CS_PORT, PIN_SPI_CS, GPIO_PIN_RESET);
    
    // Выполняем обмен данными - отправляем 2 пустых байта, принимаем 2 байта
    if (HAL_SPI_TransmitReceive(&hspi1, tx_data, rx_data, 2, HAL_MAX_DELAY) != HAL_OK)
    {
        // Обработка ошибки SPI
        Error_Handler();
    }
    // Устанавливаем CS в 1 (деактивируем датчик)
    HAL_GPIO_WritePin(PIN_SPI_CS_PORT, PIN_SPI_CS, GPIO_PIN_SET);
    
    // Объединяем полученные байты в 16-битное значение
    raw_value = (rx_data[0] << 8) | rx_data[1];
    
    // Согласно документации PmodALS:
    // - Первые 3 бита - нули
    // - Следующие 8 бит - данные освещенности (MSB first)
    // - последние 4 бита - нули
    raw_value = (raw_value >> 4) & 0xFF;  // Альтернатива: (raw_value >> 5) & 0xFF

    illum_lux = (raw_value * REF_VOLTAGE / 255.0f); //напряжение на нагрузочном резисторе ацп
    illum_lux = illum_lux * 1000000.0f / RESIST_LOAD; //фототок в мкА 
    illum_lux = illum_lux / 0.5f; //освещенность в люксах

    return illum_lux;
}