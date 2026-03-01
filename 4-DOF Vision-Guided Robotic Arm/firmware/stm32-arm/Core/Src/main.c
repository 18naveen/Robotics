
void RobotApp_Run(void); 

int main(void) {
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_ADC1_Init();

  RobotApp_Run(); 

  while (1) {
  }
}