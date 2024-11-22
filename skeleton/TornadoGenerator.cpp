#include "TornadoGenerator.h"
#include "Particle.h"

TornadoGenerator::TornadoGenerator(Vector3 v_, float k1_, Vector3 k2_, float k_)
	: WindForceGenerator(v_, k1_, k2_), k(k_)
{
}
TornadoGenerator::~TornadoGenerator()
{
}

void TornadoGenerator::updateForce(double t, Particle* p)
{
	Vector3 f = force(t, p);

	p->addForce(f);
}

Vector3 TornadoGenerator::force(double t, Particle* p)
{
	
	Vector3 force(0, 0, 0);

	force = k * Vector3(-(p->getPosition().z - position.z), 
					50 - (p->getPosition().y - position.y), 
						p->getPosition().x - position.x);

	//force -= p->getVelocity();

	return force;
}
