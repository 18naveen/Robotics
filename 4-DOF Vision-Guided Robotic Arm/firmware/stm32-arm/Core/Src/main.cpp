extern "C" {
    #include "main.h"
}
#include "hardware_interface.hpp"

RobotArm aria;

int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_TIM3_Init();
    MX_TIM4_Init();

    aria.Initialize();

    while (1) {
        for(int i = 1; i <= 6; i++) {
            aria.SetJointAngle(i, 90.0f);
        }
        HAL_Delay(2000);

        for(int joint = 1; joint <= 6; joint++) {
            aria.SetJointAngle(joint, 0.0f);
            HAL_Delay(500);
            aria.SetJointAngle(joint, 180.0f);
            HAL_Delay(500);
            aria.SetJointAngle(joint, 90.0f);
                 }
    }
}