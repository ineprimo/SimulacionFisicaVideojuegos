#include "Object.h"
#include <cmath>

Object::Object(bool v, bool a, Vector3 p)
	: position(p), visible(v), active(a), _item(new RenderItem())
{
}

Object::Object(bool v, bool a, Vector3 p, RenderItem* it)
	: position(p), visible(v), active(a), _item(it)
{

}
Object::Object(bool v, bool a, Vector3 p, PxShape* s, Vector4 color)
	: position(p), visible(v), active(a), _item(new RenderItem(s, new PxTransform(p), color))
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

bool Object::isInsideStatic(Object* b)
{
	const PxTransform* p_pos = _item->transform;
	Vector3 b_pos = b->Position();

	// posicion en el mundo del objeto 
	std::pair<float, float> px = { p_pos->p.x - bb.minX, p_pos->p.x + bb.maxX};
	std::pair<float, float> py = { p_pos->p.y - bb.minY, p_pos->p.y + bb.maxY};
	std::pair<float, float> pz = { p_pos->p.z - bb.minZ, p_pos->p.z + bb.maxZ};

	// posicion del objeto dado
	std::pair<float, float> ox = { b_pos.x - b->BB().minX, b_pos.x + b->BB().maxX};
	std::pair<float, float> oy = { b_pos.y - b->BB().minY, b_pos.y + b->BB().maxY };
	std::pair<float, float> oz = { b_pos.z - b->BB().minZ, b_pos.z + b->BB().maxZ };

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


