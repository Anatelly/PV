#ifndef __TEMP_SENS_H
#define __TEMP_SENS_H

#define PMODTIMP3_ADDRES_SLAVE            0x48
#define TEMP_STEP                         ((float)0.0625)

float PmodTIMP3_Read_temp(void);

#endif /* __TEMP_SENS_H */