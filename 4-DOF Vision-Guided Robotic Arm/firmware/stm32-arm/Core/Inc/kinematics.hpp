#ifndef KINEMATICS_HPP
#define KINEMATICS_HPP

#include <cmath>
#include <vector>

/
struct DHParameter {
    float a;
    float alpha;
    float d;
    float theta;
};

class Kinematics {
public:
    Kinematics();

    void ComputeFK(const float joint_angles[6]);

    float GetX() const { return _x; }
    float GetY() const { return _y; }
    float GetZ() const { return _z; }

private:
    float _x, _y, _z;
    
    void MultiplyMatrices(float A[4][4], float B[4][4], float Result[4][4]);
};

#endif