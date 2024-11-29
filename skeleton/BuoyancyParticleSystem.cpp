#include "BuoyancyParticleSystem.h"

BuoyancyParticleSystem::BuoyancyParticleSystem()
{
	Particle* part = new Particle({ 0,50,0 }, { 0,0,0 }, { 0,0,0 }, { 0.87, 0.34, 0.57, 1.0 });

	part->setMass(2);
	part->setVisibility(false);
	particles.push_back(part);
}

BuoyancyParticleSystem::~BuoyancyParticleSystem()
{
}
