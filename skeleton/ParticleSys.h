#pragma once
#include <list>
#include "Particle.h"


class ParticleSys {
private:
	std::list<Particle*> particleList;
	std::list<Particle*> particleListToDelete;

	// std::uniform_real_distribution<double> d(0,1);


	double timeElapsed;
	double cooldown;

public:
	ParticleSys();
	~ParticleSys();


	void update(double t);

	void generateParticle();

	void destroyParticles();

	void countCooldown();



};