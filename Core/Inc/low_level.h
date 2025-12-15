#ifndef __LOW_LEVEL_H
#define __LOW_LEVEL_H


#define PIN_UART2_RX                    A,3,L,ALT_OUTPUT_PUSH_PULL,SPEED_50MHZ           // uart RX
#define PIN_UART2_TX                    A,2,L,ALT_OUTPUT_PUSH_PULL,SPEED_50MHZ    // uart debug     TX 115200-8-n-1

// Светодиоды
#define PIN_BLINK_GREEN_LED     	    A,5,L,OUTPUT_PUSH_PULL,SPEED_2MHZ

//кнопка
#define PIN_BUTTON               	    C,13,L,INPUT_FLOATING,SPEED_2MHZ

// SPI
#define ADC1_IN0                        A,0,L,ANALOG,SPEED_100MHZ
#define ADC1_IN1                        A,1,L, ANALOG,SPEED_100MHZ

void init_task(void);

#endif /* __LOW_LEVEL_H */