#include "PID.hpp"

PID::PID(float kp, float ki, float kd, float min_out, float max_out)
    : _kp(kp), _ki(ki), _kd(kd), _min_out(min_out), _max_out(max_out), 
      _integral(0.0f), _prev_error(0.0f) {}

float PID::Compute(float setpoint, float current_val, float dt) {
    float error = setpoint - current_val;
    
    _integral += error * dt;
    
    if (_integral > 100.0f) _integral = 100.0f;
    else if (_integral < -100.0f) _integral = -100.0f;

    float derivative = (error - _prev_error) / dt;
    float output = (_kp * error) + (_ki * _integral) + (_kd * derivative);
    
    _prev_error = error;

    if (output > _max_out) return _max_out;
    if (output < _min_out) return _min_out;
    
    return output;
}

void PID::Reset() {
    _integral = 0.0f;
    _prev_error = 0.0f;
}