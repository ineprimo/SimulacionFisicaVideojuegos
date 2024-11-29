#include "BuoyancyForceGenerator.h"
#include "Particle.h"

BuoyancyForceGenerator::BuoyancyForceGenerator(Vector3 pos, float density, float volume, float h)
	: position(pos), _liquid_density(density), _volume(volume), _height(h)
{
	immersed = 0;
}


BuoyancyForceGenerator::~BuoyancyForceGenerator()
{
}

void BuoyancyForceGenerator::updateForce(double t, Particle* p)
{
	Vector3 f = { 0,0,0 };

	if (active) {

		f = force(t, p);
		p->addForce(f);

	}

}

Vector3 BuoyancyForceGenerator::force(double t, Particle* p)
{
	Vector3 f = {0,0,0};

	float h = p->getPosition().y;
	float h0 = position.y;	


	if (h - h0 > _height * 0.5) {
		immersed = 0.0;
	}
	else if (h0 - h > _height * 0.5) {
		immersed = 1;
	}
	else {

		immersed = (h0 - h) / _height + 0.5;
	}
	 
	f.y = _liquid_density * _volume * immersed * 9.8;

	return f; 
}
