#pragma once
#include <list>
#include <random>
#include "Particle.h"


class ParticleSys {
private:
	std::list<Particle*> particleList;
	std::list<Particle*> particleListToDelete;

	//std::uniform_real_distribution<double> d(0,1);
	std::default_random_engine generator;


	double timeElapsed;
	double cooldown;


	Vector3 g;		// gravedad

public:
	ParticleSys();
	~ParticleSys();


	void update(double t);

	void generateParticle();

	void destroyParticles();

	void countCooldown();  

	void applyGravity(Particle* p);



};