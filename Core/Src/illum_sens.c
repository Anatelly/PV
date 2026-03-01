#include "include.h"

/**
  * @brief Функция чтения значения освещенности с PmodALS
  * @return 8-битное значение освещенности (0-255)
  */
uint8_t PmodALS_Read_illum(void)
{
    uint8_t tx_data[2] = {0x00, 0x00};  // Передаем пустые байты для генерации тактов
    uint8_t rx_data[2] = {0, 0};        // Буфер для приема 16 бит
    uint16_t raw_value = 0;
    uint8_t light_value = 0;
    
    // Устанавливаем CS в 0 (активируем датчик)
    HAL_GPIO_WritePin(PIN_SPI_CS_PORT, PIN_SPI_CS, GPIO_PIN_RESET);
    
    // Небольшая задержка для стабилизации (опционально)
    // HAL_Delay(1);
    
    // Выполняем обмен данными - отправляем 2 пустых байта, принимаем 2 байта
    if (HAL_SPI_TransmitReceive(&hspi1, tx_data, rx_data, 2, HAL_MAX_DELAY) != HAL_OK)
    {
        // Обработка ошибки SPI
        Error_Handler();
    }
    HAL_Delay(5);
    // Устанавливаем CS в 1 (деактивируем датчик)
    HAL_GPIO_WritePin(PIN_SPI_CS_PORT, PIN_SPI_CS, GPIO_PIN_SET);
    
    // Объединяем полученные байты в 16-битное значение
    // raw_value = (rx_data[0] << 8) | rx_data[1];
    raw_value = (rx_data[0] << 8) | rx_data[1];
    
    // Согласно документации PmodALS:
    // - Первые 3 бита - нули
    // - Следующие 8 бит - данные освещенности (MSB first)
    // - Оставшиеся биты - нули
    // Поэтому сдвигаем на 5 бит вправо (3 + 2 отступа) или на 7 бит влево
    // illum_t = (raw_value >> 5) & 0xFF;  // Альтернатива: (raw_value >> 5) & 0xFF
    
    return light_value;
}