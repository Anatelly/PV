#include "include.h"

uint8_t buff[20];

void logger_task(void) 
{
    // if(adc_flag) {
        logger_t *pck = (logger_t*)buff;
        pck->prxA = 'a';
        pck->prxB = 'b';
        // pck->temp = 10000.0 * adc_voltage[TEMP_CHANNEL] / (3.3 - adc_voltage[TEMP_CHANNEL]); //сопротивление термистора в Ом
        pck->temp = PmodTIMP3_Read_temp();
        
        pck->illum = 10000.0 * adc_voltage[ILLUM_CHANNEL] / (3.3 - adc_voltage[ILLUM_CHANNEL]); //сопротивление фоторезистора в Ом

        pck->crc = crc8(&pck->temp, sizeof(logger_t) - 3); //кс для всего кроме префикса(2) и самой кс(1)

        if(software_timer(&tim1))
           HAL_UART_Transmit(&huart2, buff, sizeof(logger_t), HAL_MAX_DELAY);
    // }
}