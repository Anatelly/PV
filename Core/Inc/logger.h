#ifndef _LOGGER_H_
#define _LOGGER_H_

#pragma pack (push, 1)

typedef struct
{
    uint8_t prxA;
    uint8_t prxB;
    float temp;
    float illum;
    uint8_t crc;
    
} logger_t;

#pragma pack (pop)

void logger_task(void);

#endif /* _LOGGER_H_ */