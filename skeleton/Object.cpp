#include "Object.h"
#include <cmath>

Object::Object(bool v, bool a, Vector3 p)
{
}

bool Object::update(double t)
{
	return false;
}

bool Object::collides(Object* o)
{
	return false;
}

bool Object::isInside(Object* b)
{
	// posicion en el mundo del objeto 
	std::pair<float, float> px = {position.x - bb.minX, position.x + bb.maxX};
	std::pair<float, float> py = {position.y - bb.minY, position.y + bb.maxY};
	std::pair<float, float> pz = {position.z - bb.minZ, position.z + bb.maxZ};

	// posicion del objeto dado
	std::pair<float, float> ox = { position.x - bb.minX, position.x + bb.maxX };
	std::pair<float, float> oy = { position.y - bb.minY, position.y + bb.maxY };
	std::pair<float, float> oz = { position.z - bb.minZ, position.z + bb.maxZ };

	// distancia entre ambos (por eje)
	float dx = abs(position.x - b->position.x);
	float dy = abs(position.y - b->position.y);
	float dz = abs(position.z - b->position.z);

	// para simplificar, suponemos que son bb cuadradas, asi que min y max 
	// lo tratamos igual
	float rx = abs(px.first - ox.first);
	float ry = abs(py.first - oy.first);
	float rz = abs(pz.first - oz.first);

	if (dx - rx <= 0 && dy <= ry && dz <= rz)
		return true;

	return false;
}


