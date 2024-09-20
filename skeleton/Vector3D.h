#pragma once


// ho-ho-hola de nuevo vector3d
class Vector3D {

	float x, y, z;

	Vector3D() :
		x(0.0), y(0.0), z(0.0) {};

	Vector3D(float x_, float y_, float z_) 
		: x(x_), y(y_), z(z_) {};

	

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


	// ---------- OPERACIONES ------------ //
	//

	// sobrecargar esto tmbbbbbbbb omfg
	// PRODUCTO ESCALAR
	Vector3D product(Vector3D v1, Vector3D v2);

	// VECTOR X ESCALAR
	Vector3D product(Vector3D vec, float esc);

	// ---------- SOBRECARGAS ------------- //




};