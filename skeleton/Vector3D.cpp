#include "Vector3D.h"
#include <cmath>

Vector3D Vector3D::normalize(Vector3D vector)
{
    // vector / modulo

    float mod = module(vector);

    Vector3D vec = { vector.x()/mod, vector.y()/mod, vector.z()/mod };

    return vec;
}

float Vector3D::module(Vector3D vector)
{
    float in = pow(vector.x(), 2) + pow(vector.y(), 2) + pow(vector.z(), 2);
    float mod = sqrt(in);
    return mod;
}

Vector3D& Vector3D::operator*(Vector3D& vec)
{
    // TODO: Insertar una instrucción "return" aquí
}

float& Vector3D::operator*(float& a)
{

}

float& Vector3D::operator*(Vector3D& vec) const
{
    // TODO: Insertar una instrucción "return" aquí
    float a = vec.x() * x();
    return (vec.x() + vec.y());
}


