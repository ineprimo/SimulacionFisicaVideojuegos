#pragma once
#include <list>
#include "Particle.h"


class ParticleSys {
private:
	std::list<Particle*> particleList;

	// std::uniform_real_distribution<double> d(0,1);

public:
	ParticleSys();
	~ParticleSys();


	void update(double t);

	void generateParticle();

	void destroyParticle();

};