#include "include.h"

static const float mu_cc = 0.00159636f;
static const float I_0 = 2.3808e-10f;
static const float V_d = 0.7f;
static const float k = 1.3806e-23f;
static const float q = 1.6022e-19f;
static const float nI = 0.99673f;
static const uint8_t Ncell = 48;
static const float Rsh = 78.6558f;

static void set_value_dac(uint16_t value);
static float current_math_model(float E, float E_ref, float T, float T_ref, float I_ref);

/**
 * @brief Преобразовывает считанную освещенность и температуру в выходное напряжение (значение для ЦАП)
 */
void convert_task(void)
{
    set_value_dac(1922);
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
 * @brief Мат модель выходного тока
 * @param E - освещенность в W/m2
 * @param E_ref - опорная освещенность в W/m2
 * @param T - температура в гр. С
 * @param T_ref - опорная температруа в гр.С
 * @param I_ref - выходной ток в опорной точке в A
 * @return На выходе получается выходной ток в A
 */
static float current_math_model(float E, float E_ref, float T, float T_ref, float I_ref)
{
    float Iph, Vt, Id, I;

    T = T + TEMP_CONV_COEFF;
    T_ref = T_ref + TEMP_CONV_COEFF;

    Iph = (E / E_ref) * (I_ref + mu_cc * (T - T_ref));
    Vt = (k * T / q) * nI * Ncell;
    Id = I_0 * ((float)(exp(V_d / Vt)) - 1);
    I = Iph - Id - V_d / Rsh;

    return I;
}