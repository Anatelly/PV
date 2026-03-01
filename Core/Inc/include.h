#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "stm32h7xx_hal.h"

#include "low_level.h"
#include "stm32h7xx_it.h"
#include "main.h"
#include "adc_task.h"
#include "logger.h"
#include "converter.h"
#include "software_timer.h"
#include "crc8.h"
#include "temp_sens.h"
#include "illum_sens.h"

#include "var.h"

#define VOLTAGE_CHANNEL            0
#define ILLUM_CHANNEL              1
#define CURRENT_CHANNEL            2

#endif /* _INCLUDE_H_ */
