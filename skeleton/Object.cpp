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
	// particula
	const PxTransform* p_pos = _item->transform;

	// obj
	const Vector3 b_pos = b->Position();


	// posicion en el mundo del objeto 
	const std::pair<float, float> px = { p_pos->p.x - bb.minX, p_pos->p.x + bb.maxX};
	const std::pair<float, float> py = { p_pos->p.y - bb.minY, p_pos->p.y + bb.maxY};
	const std::pair<float, float> pz = { p_pos->p.z - bb.minZ, p_pos->p.z + bb.maxZ};

	// posicion del objeto dado
	const std::pair<float, float> ox = { b_pos.x - b->BB().minX, b_pos.x + b->BB().maxX};
	const std::pair<float, float> oy = { b_pos.y - b->BB().minY, b_pos.y + b->BB().maxY };
	const std::pair<float, float> oz = { b_pos.z - b->BB().minZ, b_pos.z + b->BB().maxZ };

	// esta asi por comodidad para debugear
	const bool x1 = ox.first <= px.first && px.first <= ox.second;
	const bool x2 = ox.first <= px.second && px.second <= ox.second;
	const bool x = x1 || x2;

	const bool y1 = oy.first <= py.first && py.first <= oy.second;
	const bool y2 = oy.first <= py.second && py.second <= oy.second;
	const bool y = y1 || y2;

	const bool z1 = oz.first <= pz.first && pz.first <= oz.second;
	const bool z2 = oz.first <= pz.second && pz.second <= oz.second;
	const bool z = z1 || z2;

	return	x && y && z;
}

