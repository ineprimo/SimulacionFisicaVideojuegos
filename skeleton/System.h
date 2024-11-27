#pragma once
#include "Particle.h"
#include <list>


class System
{
public:
	System() {};
	~System() {};

	virtual void update(double t) {};


	void hide();
	void show();

	void addParticle(Particle* p);


protected:


	std::list<Particle*> particles;

};

