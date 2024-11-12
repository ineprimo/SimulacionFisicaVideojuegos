#include "ForceSystem.h"

ForceSystem::ForceSystem()
	: force(0), zone(nullptr), radio(0)
{
}

ForceSystem::ForceSystem(Vector3 force_, RenderItem* zone_)
	: force(force_), zone(zone_), radio(10)
{
}

ForceSystem::ForceSystem(Vector3 force_, RenderItem* zone_, Vector3 pos_, int rad, Vector4 col_)
	: force(force_), zone(zone_), radio(rad)
{
	physx::PxTransform pose = physx::PxTransform(pos_);	// posicion

	zone = new RenderItem(CreateShape(physx::PxSphereGeometry(rad)), &pose, col_);

}

ForceSystem::~ForceSystem()
{
}

void ForceSystem::updateGravityForce(double t, Particle* p)
{

}

bool ForceSystem::enterZone(Particle* p)
{
	// si esta dentro de la zona
	if (isInside(p->getPosition())) {
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

bool ForceSystem::isInside(Vector3 pos)
{
	return {pos.x - radio > 0 &&
			pos.y - radio > 0 &&
			pos.z - radio > 0};
}
