#ifndef _VAR_H_
#define _VAR_H_

#ifdef MAIN
int sck_2;
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;
logger_t logger;
uint8_t adc_flag = 0;
timeout_t tim1;


#else
extern int sck_2;
extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;
extern logger_t logger;
extern uint8_t adc_flag;
extern timeout_t tim1;

#endif /* MAIN */

#endif /* _VAR_H_ */