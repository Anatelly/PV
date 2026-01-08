#include "include.h"

static uint16_t adcData[ADC_CHANNELS_NUM];

void adc_task(void)
{
    if(software_timer(&tim2)) {
      adc_flag = 0;
      HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adcData, ADC_CHANNELS_NUM);
    }
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
  if(hadc->Instance == ADC1)
  {
    adc_flag = 1;
    adc_voltage[1] = adcData[1] * 3.3 / 4095; //напряжение на термисторе
    adc_voltage[0] = adcData[0] * 3.3 / 4095; //напряжение на фоторезисторе
  }
}