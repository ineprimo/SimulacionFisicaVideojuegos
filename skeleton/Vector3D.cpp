#include "Vector3D.h"
#include <cmath>

Vector3D Vector3D::normalize(Vector3D vector)
{
    // vector / modulo

    double mod = module(vector);

    Vector3D vec = { vector.getX()/mod, vector.getY()/mod, vector.getZ()/mod };

    return vec;
}

double Vector3D::module(Vector3D vector)
{
    double in = pow(vector.getX(), 2) + pow(vector.getY(), 2) + pow(vector.getZ(), 2);
    double mod = sqrt(in);
    return mod;
}


