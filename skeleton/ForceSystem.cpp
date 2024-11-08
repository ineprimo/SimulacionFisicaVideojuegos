#include "ForceSystem.h"

ForceSystem::ForceSystem(Vector3 force_, RenderItem* zone_)
	: force(force_), zone(zone_)
{
}

ForceSystem::~ForceSystem()
{
}

bool ForceSystem::enterZone(Particle* p)
{
	// si esta dentro de la zona
	if (true) {
		particleList.push_back(p);

		return true;
	}

	return false;
}

void ForceSystem::exitZone(Particle* p)
{
	particleList.remove(p);
}

void ForceSystem::applyForce()
{
	for (auto p : particleList) {
		float m = p->getMass();
		Vector3 a = { force.x / m, force.y / m, force.z / m };

		p->setAcceleration(a);
	}

}
