#pragma once
#include "System.h"
#include "Particle.h"

#include <vector>

using namespace std;

class SpringSystem : public System
{
public:


	SpringSystem(Particle* anchor_, Particle* particle_);
	~SpringSystem();

	virtual void affectParticles(vector<Particle*>& particles, double t) {}

private:

	Particle* anchor;
	Particle* particle;


};

