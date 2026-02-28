#ifndef HERA_CONTROL_HPP
#define HERA_CONTROL_HPP

#include <cmath>
#include "hardware_interface.hpp"
#include "kinematics.hpp"

/**
 * @brief System states for the Finite State Machine (FSM)
 */
enum class RobotState {
    INIT,
    IDLE,
    MOVING,
    ERROR,
    EMERGENCY_STOP
};

class HeraControl {
public:
    HeraControl();

    /**
     * @brief Main execution step. Should be called at a fixed frequency (e.g., 100Hz).
     */
    void Update();

    /**
     * @brief Sets a new cartesian target for the end-effector.
     */
    void SetTarget(float x, float y, float z);

    /**
     * @brief Triggers immediate system-wide stop.
     */
    void EmergencyStop() { _state = RobotState::EMERGENCY_STOP; }

private:
    // Internal state management
    RobotState _state;

    // Sub-system instances (Composition)
    RobotArm   _hardware;
    Kinematics _kinematics;

    // Navigation targets
    float _target_x;
    float _target_y;
    float _target_z;

    // Private state handlers to keep Update() clean
    void HandleIdle();
    void HandleMoving();
    void HandleError();
};

#endif