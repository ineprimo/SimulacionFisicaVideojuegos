#include "BuoyancyParticleSystem.h"

BuoyancyParticleSystem::BuoyancyParticleSystem(std::vector<Particle*> part)
{
	//Particle* part = new Particle({ 0,20,0 }, { 0,0,0 }, { 0,0,0 }, { 0.87, 0.34, 0.57, 1.0 });
	for (auto p : part)
		particles.push_back(p);
}

BuoyancyParticleSystem::~BuoyancyParticleSystem()
{


}
