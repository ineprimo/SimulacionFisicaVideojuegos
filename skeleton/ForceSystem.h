#pragma once

#include <PxPhysicsAPI.h>
#include "ParticleSys.h"
#include "core.hpp"
#include <cmath>

class ForceSystem
{
private:
	// area a la que afecta
	RenderItem* zone;

	// radio de la zona
	int radio;

	// fuerza (vector)
	Vector3 force;

	// vector de particulas afectadas
	std::list<Particle*> particleList;




public:
	ForceSystem(Vector3 force_, RenderItem* zone_);
	ForceSystem(Vector3 force_, RenderItem* zone_, Vector3 pos_, int rad, Vector4 col_);

	~ForceSystem();



	bool enterZone(Particle* p);
	void exitZone(Particle* p);
	void applyForce();


};

