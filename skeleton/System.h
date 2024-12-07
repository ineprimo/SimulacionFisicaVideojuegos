#pragma once
#include "Particle.h"
#include <list>


class System
{
public:
	System() {};
	~System() {};

	virtual void update(double t);


	void hide();
	void show();

	void addParticle(Particle* p);

	void addForceGenerator(ForceGen* f, Particle* p);
	void addForceGeneratorToAll(ForceGen* f);

protected:


	std::list<Particle*> particles;

};

