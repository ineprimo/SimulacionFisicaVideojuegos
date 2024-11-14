#pragma once

class Particle;
#include <PxPhysicsAPI.h>
#include "core.hpp"
#include <cmath>

class ForceGen
{
public:

	ForceGen();

	virtual void updateGravityForce(double t, Particle* p);

	bool enterZone(Particle* p);
	void exitZone(Particle* p);
	void applyForce();
	bool isInside(Vector3 pos);

};

