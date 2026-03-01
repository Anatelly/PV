#ifndef __LOW_LEVEL_H
#define __LOW_LEVEL_H

// UART
#define PIN_UART2_RX                     GPIO_PIN_3             
#define PIN_UART2_TX                     GPIO_PIN_2                   	    

// ADC
#define PIN_ADC_IN3                      GPIO_PIN_6                  
#define PIN_ADC_IN4                      GPIO_PIN_4   
#define PIN_ADC_IN5                      GPIO_PIN_1                       

// DAC
#define PIN_DAC1_OUT1                    GPIO_PIN_4  
#define PIN_DAC1_OUT2                    GPIO_PIN_5 

// UART
#define PIN_I2C_SDA                      GPIO_PIN_7             
#define PIN_I2C_SCL                      GPIO_PIN_6 

// SPI
#define PIN_SPI_MOSI                     GPIO_PIN_7                  
#define PIN_SPI_SCK                      GPIO_PIN_3   
#define PIN_SPI_MISO                     GPIO_PIN_4                  
#define PIN_SPI_CS                       GPIO_PIN_6   

#define PIN_SPI_CS_PORT                  GPIOD   

void SystemClock_Config(void);
void init_task(void);

#endif /* __LOW_LEVEL_H */