#include "hardware_interface.hpp"

extern "C" {
    #include "main.h"
    #include "tim.h"
}

void RobotArm::Initialize() {
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);
    
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
}

void RobotArm::WritePulse(uint8_t joint_id, uint32_t pulse) {
    if (pulse < 500)  pulse = 500;
    if (pulse > 2500) pulse = 2500;

    switch(joint_id) {
        case 1: htim4.Instance->CCR1 = pulse; break;
        case 2: htim4.Instance->CCR2 = pulse; break;
        case 3: htim4.Instance->CCR3 = pulse; break;
        case 4: htim4.Instance->CCR4 = pulse; break;
        case 5: htim3.Instance->CCR1 = pulse; break;
        case 6: htim3.Instance->CCR2 = pulse; break;
    }
}