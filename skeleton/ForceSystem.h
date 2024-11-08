#pragma once

#include <PxPhysicsAPI.h>
#include "ParticleSys.h"
#include "core.hpp"


class ForceSystem
{
private:
	// area a la que afecta
	RenderItem* zone;

	// fuerza (vector)
	Vector3 force;

	// vector de particulas afectadas
	std::list<Particle*> particleList;


public:
	ForceSystem(Vector3 force_, RenderItem* zone_);

	~ForceSystem();



	bool enterZone(Particle* p);
	void exitZone(Particle* p);
	void applyForce();


};

