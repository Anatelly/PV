#define MAIN

#include "include.h"

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  init_task();

  // HAL_DAC_Start(&hdac1, DAC_CHANNEL_1);
  // adc_start();
  
  while (1)
  {
    logger_task();
    convert_task();
  }
}