#pragma once

class Particle;
#include <PxPhysicsAPI.h>
#include "core.hpp"
#include <cmath>
#include <iostream>


class ForceGen
{
public:

	ForceGen();

	virtual void updateForce(double t, Particle* p);

	bool enterZone(Particle* p);
	void exitZone(Particle* p);
	void applyForce();
	bool isInside(Vector3 pos);

};

