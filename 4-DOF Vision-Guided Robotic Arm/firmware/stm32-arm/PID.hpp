#ifndef PID_CONTROLLER_HPP
#define PID_CONTROLLER_HPP

class PID {
public:
    PID(float kp, float ki, float kd, float min_out, float max_out);
    float Compute(float setpoint, float current_val, float dt);
    void Reset();

private:
    float _kp, _ki, _kd;
    float _min_out, _max_out;
    float _integral;
    float _prev_error;
};

#endif