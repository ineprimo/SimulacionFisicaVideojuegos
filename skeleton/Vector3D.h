#pragma once

#include <cmath>

// ho-ho-hola de nuevo vector3d
class Vector3D {

private:
	float x, y, z;

public:
	Vector3D() :
		x(0.0), y(0.0), z(0.0) {};

	Vector3D(float x_, float y_, float z_) 
		: x(x_), y(y_), z(z_) {};

	~Vector3D();
	

	// ------------ GETTERS Y SETTERS --------- //

	float x() { return x; }
	float y() { return y; }
	float z() { return z; }

	void setX(float x_) { x = x_; }
	void setY(float y_) { y = y_; }
	void setZ(float z_) { z = z_; }

	// ------------ METODOS ------------- //

	// NORMALIZAR
	Vector3D normalize(Vector3D vector);

	// MODULO
	float module(Vector3D vector);



	Vector3D operator+(Vector3D& v)
	{
		return Vector3D(x + v.x, y + v.y, z + v.z);

	}
	
	Vector3D operator-(Vector3D& v)
	{
		return Vector3D(x -v.x, y - v.y, z-v.z);

	}



	//Producto escalar
	double operator*(Vector3D& vec) {

		return x * vec.x + y * vec.y + z * vec.z;
	}

	//Por un escalar
	double operator*(double escalar) {

		return x * escalar + y * escalar + z * escalar;
	}


	bool operator==(Vector3D& v) {

		return x == v.x && y == v.y && z == v.z;
	}

	Vector3D operator=(Vector3D& v) {
		x = v.x;
		y = v.y;
		z = v.z;
	}





};