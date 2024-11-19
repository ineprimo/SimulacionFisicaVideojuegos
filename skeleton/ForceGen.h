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
	virtual Vector3 force(double t, Particle* p);


	bool enterZone(Particle* p);
	void exitZone(Particle* p);
	void applyForce();
	bool isInside(Vector3 pos);


	void Activate(bool a) { active = a; }
	bool isActive() { return active; }

protected:

	bool active = true;

};

