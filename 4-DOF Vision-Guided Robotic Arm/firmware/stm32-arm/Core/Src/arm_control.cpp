#include "arm_control.hpp"

HeraControl::HeraControl() : _state(RobotState::IDLE), _target_x(0), _target_y(0), _target_z(0) {}

void HeraControl::Update() {
    switch (_state) {
        case RobotState::IDLE:
            HandleIdle();
            break;

        case RobotState::INIT:
            _hardware.Initialize();
            _state = RobotState::IDLE;
            break;

        case RobotState::MOVING:
            HandleMoving();
            break;

        case RobotState::EMERGENCY_STOP:
            // Force all PWM to safe neutral or zero
            for(int i = 1; i <= 6; i++) _hardware.WritePulse(i, 1500);
            break;
    }
}

void HeraControl::SetTarget(float x, float y, float z) {
    _target_x = x;
    _target_y = y;
    _target_z = z;
    _state = RobotState::MOVING;
}

void HeraControl::HandleIdle() {
 

void HeraControl::HandleMoving() {
    float joints[6];
    
     _kinematics.ComputeFK(joints);

   if (fabs(_kinematics.GetX() - _target_x) < 0.1f) {
        _state = RobotState::IDLE;
    }

     for(int i = 1; i <= 6; i++) {
        _hardware.WritePulse(i, 1500); // Placeholder for PID output
    }
}