#include "include.h"

static uint16_t volt_to_illum(uint16_t volt); 
static uint16_t volt_to_temp(uint16_t volt);
static void set_value_dac(uint16_t value);
static double volt_illum_func(double x);

/**
 * @brief Преобразовывает считанную освещенность и температуру в выходное напряжение (значение для ЦАП)
 */
void convert_task(void)
{
    set_value_dac(1922);
}

/**
 * @brief Преобразовывает напряжение с ацп в освещенность в Вт/м2
 */
static uint16_t volt_to_illum(uint16_t volt) 
{
    uint16_t resist = 10000.0 * adc_voltage[ILLUM_CHANNEL] / (3.3 - adc_voltage[ILLUM_CHANNEL]); //сопротивление фоторезистора в Ом

    return resist;
}

/**
 * @brief Преобразовывает напряжение с ацп в температуру в гр. С
 */
static uint16_t volt_to_temp(uint16_t volt) 
{
    uint16_t resist = 10000.0 * adc_voltage[TEMP_CHANNEL] / (3.3 - adc_voltage[TEMP_CHANNEL]); //сопротивление термистора в Ом

    return resist;
}

/**
 * @brief установка знчения в цап
 */
static void set_value_dac(uint16_t value) 
{
    if(HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, (uint32_t)value) != HAL_OK) {
        Error_Handler();
    }
}

/**
 * @brief Зависимость напряжения от освещенности. Аппроксимация полиномом 10й степени
 * @param x - освещенность W/m2
 * @note На выходе получается напряжение в В для PV
 */
static double volt_illum_func(double x)
{
    double voltage = -1.4161664835639534 + 0.4973725819227123*x + -0.022539956113439615*x*x + 0.0005107168227857588*x*x*x + -6.551716589662537e-06*x*x*x*x + 5.170169386359444e-08*x*x*x*x*x + -2.5976993176473945e-10*x*x*x*x*x*x + 8.330210752860122e-13*x*x*x*x*x*x*x + -1.6501463235380724e-15*x*x*x*x*x*x*x*x + 1.83936948637939e-18*x*x*x*x*x*x*x*x*x + -8.821975832278624e-22*x*x*x*x*x*x*x*x*x*x;

    return voltage;
}