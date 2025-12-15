#include "include.h"

uint8_t buff[10];

void logger_init(void)
{
    software_timer_start(&tim1, 10);
}

void logger_task(void) 
{
    if(adc_flag) {
        logger_t *pck = (logger_t*)buff;
        pck->illum = logger.illum;
        pck->temp = logger.temp;

        if(software_timer(&tim1))
            write(sck_2, (char*)buff, sizeof(logger_t));
    }
}