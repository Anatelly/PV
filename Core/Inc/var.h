#ifndef _VAR_H_
#define _VAR_H_

#ifdef MAIN
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;
DAC_HandleTypeDef hdac1;
DMA_HandleTypeDef hdma_dac1_ch1;
UART_HandleTypeDef huart2;
logger_t logger;
uint8_t adc_flag = 0;
timeout_t tim1;
timeout_t tim2;
double adc_voltage[ADC_CHANNELS_NUM];


#else
extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;
extern DAC_HandleTypeDef hdac1;
extern DMA_HandleTypeDef hdma_dac1_ch1;
extern UART_HandleTypeDef huart2;
extern logger_t logger;
extern uint8_t adc_flag;
extern timeout_t tim1;
extern timeout_t tim2;
extern double adc_voltage[ADC_CHANNELS_NUM];

#endif /* MAIN */

#endif /* _VAR_H_ */