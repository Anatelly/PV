#ifndef _ADC_TASK_H_
#define _ADC_TASK_H_

// Буфер для DMA (должен быть в некэшируемой памяти для H7)

#define ADC_CHANNELS_NUM                2

void adc_start(void);

#endif /* _ADC_TASK_H_ */