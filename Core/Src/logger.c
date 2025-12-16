#include "include.h"

uint8_t buff[20];

void logger_task(void) 
{
    if(adc_flag) {
        logger_t *pck = (logger_t*)buff;
        pck->prxA = 0x01;
        pck->prxB = 0x02;
        pck->illum = 10000.0 * adc_voltage[0] / (3.3 - adc_voltage[0]);
        pck->temp = 10000.0 * adc_voltage[1] / (3.3 - adc_voltage[1]);

        if(software_timer(&tim1))
            write(sck_2, (char*)buff, sizeof(logger_t));
    }
}