#ifndef _LOGGER_H_
#define _LOGGER_H_

typedef struct
{
    uint8_t temp;
    uint8_t illum;
    
} logger_t;

void logger_init(void);
void logger_task(void);

#endif /* _LOGGER_H_ */