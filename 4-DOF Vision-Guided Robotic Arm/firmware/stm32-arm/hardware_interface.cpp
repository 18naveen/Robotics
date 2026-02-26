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

void RobotArm::SetJointAngle(uint8_t joint_id, float angle) {
    if (angle < 0) angle = 0;
    if (angle > 180) angle = 180;
    
    uint32_t pulse = (uint32_t)(500 + (angle / 180.0f) * 2000);

    switch(joint_id) {
        case 1: __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, pulse); break;
        case 2: __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, pulse); break;
        case 3: __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, pulse); break;
        case 4: __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, pulse); break;
        case 5: __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pulse); break;
        case 6: __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, pulse); break;
    }
}