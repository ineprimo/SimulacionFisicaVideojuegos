#include "Object.h"
#include <cmath>

Object::Object(bool v, bool a, Vector3 p)
	: position(p), visible(v), active(a)
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
	std::pair<float, float> ox = { b->position.x - b->BB().minX, b->position.x + b->BB().maxX};
	std::pair<float, float> oy = { b->position.y - b->BB().minY, b->position.y + b->BB().maxY };
	std::pair<float, float> oz = { b->position.z - b->BB().minZ, b->position.z + b->BB().maxZ };

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
		return false;

	return true;
}


