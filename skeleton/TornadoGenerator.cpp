#include "TornadoGenerator.h"
#include "Particle.h"

TornadoGenerator::TornadoGenerator(Vector3 v_)
	: WindForceGenerator(v_)
{
}
TornadoGenerator::~TornadoGenerator()
{
}

void TornadoGenerator::updateForce(double t, Particle* p)
{
	Vector3 f = force(p);

	p->addForce(f);
}

Vector3 TornadoGenerator::force(Particle* p)
{
	
	Vector3 force(0, 0, 0);

	force = k * Vector3(-(p->getPosition().z - position.z), 
					50 - (p->getPosition().y - position.y), 
						p->getPosition().x - position.x);

	//force -= p->getVelocity();

	return force;
}
