#pragma once
#include "System.h"


class BuoyancyParticleSystem : public System
{
public:
	BuoyancyParticleSystem(std::vector<Particle*> part);
	~BuoyancyParticleSystem();


	void setParticles(std::vector<Particle*> part);

private:

};

