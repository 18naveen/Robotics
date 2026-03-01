#include "kinematics.hpp"

Kinematics::Kinematics() : _x(0), _y(0), _z(0) {}

void Kinematics::ComputeFK(const float angles[6]) {
    DHParameter dh[6] = {
        {0.0f,  1.57f, 0.1f,  angles[0]}, // 1
        {0.2f,  0.0f,  0.0f,  angles[1]}, // 2
        {0.15f, 0.0f,  0.0f,  angles[2]}, // 3
        {0.0f,  1.57f, 0.0f,  angles[3]}, // 4
        {0.0f, -1.57f, 0.0f,  angles[4]}, // 5
        {0.0f,  0.0f,  0.05f, angles[5]}  // 6
    };

      _x = dh[1].a * cosf(angles[1]) + dh[2].a * cosf(angles[1] + angles[2]);
    _z = dh[0].d + dh[1].a * sinf(angles[1]) + dh[2].a * sinf(angles[1] + angles[2]);
    _y = _x * sinf(angles[0]);
    _x = _x * cosf(angles[0]);
}