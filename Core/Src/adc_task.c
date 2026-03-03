#include "include.h"

static uint16_t adcData[ADC_CHANNELS_NUM];
static uint8_t curr_buf = 0;

void adc_start(void)
{
      if(HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adcData, ADC_CHANNELS_NUM) != HAL_OK) {
        Error_Handler();
      }
}

/**
  * @brief Callback при полном завершении передачи DMA
  */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
    // adc_flag = 1;
    // adc_voltage[ILLUM_CHANNEL] = adcData[ILLUM_CHANNEL] * 3.3 / 65535; //напряжение на фоторезисторе

}

// Callback при ошибке
void HAL_ADC_ErrorCallback(ADC_HandleTypeDef* hadc) 
{
  if (hadc->Instance == ADC1) {
      Error_Handler();
  }
}