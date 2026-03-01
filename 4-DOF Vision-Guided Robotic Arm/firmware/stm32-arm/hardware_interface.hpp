#ifndef HARDWARE_INTERFACE_HPP
#define HARDWARE_INTERFACE_HPP

#include <cstdint>

class RobotArm {
public:
    void Initialize();
    void WritePulse(uint8_t joint_id, uint32_t pulse);
};

#endif