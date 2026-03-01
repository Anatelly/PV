#include "include.h"

/**
  * @brief Функция чтения значения температуры с PmodTIMP3
  * @note 11-битное значение + 1бит знака. 1 единица = 0.0625гр.C
  */
float PmodTIMP3_Read_temp(void)
{
    uint8_t rx_data[2];        // Буфер для приема 16 бит
    uint16_t raw_val;
    
    if(HAL_I2C_Master_Receive(&hi2c1, PMODTIMP3_ADDRES_SLAVE<<1, rx_data, 2, HAL_MAX_DELAY) != HAL_OK) {
      // Error_Handler();
    }
    
    raw_val = ((rx_data[0] << 8) | rx_data[1]); //объеденияем msb и lsb

    if((raw_val>>15)) { //если отрицательное значение
        raw_val = (raw_val >> 4) & 0x7FF;
        return (float)(raw_val*TEMP_STEP*(-1));

    } else { //если положительное
        raw_val = (raw_val >> 4) & 0x7FF;
        return (float)(raw_val*TEMP_STEP);
    }
}