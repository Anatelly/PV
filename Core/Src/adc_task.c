#include "include.h"

uint16_t adcData[ADC_CHANNELS_NUM];
float adcVoltage[ADC_CHANNELS_NUM];

void adc_task(void)
{
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adcData, ADC_CHANNELS_NUM);
}


void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
  if(hadc->Instance == ADC1)
  {
    logger.temp = adcData[0] * 3.3 / 4095; //записываем данные с канала температуры
    logger.illum = adcData[1] * 3.3 / 4095; //записываем данные с канала освещенности
  }
}