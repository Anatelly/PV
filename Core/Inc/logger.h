#ifndef _LOGGER_H_
#define _LOGGER_H_

typedef struct
{
    uint16_t temp;
    uint16_t illum;
    
} logger_t;

void logger_init(void);
void logger_task(void);

#endif /* _LOGGER_H_ */