#include "WindForceGenerator.h"
#include "Particle.h"

WindForceGenerator::WindForceGenerator(Vector3 v_)
	: v(v_)
{

}

WindForceGenerator::~WindForceGenerator()
{

}

void WindForceGenerator::updateForce(double t, Particle* p)
{

	Vector3 f(0, 0, 0);
	// calculo de la fuerza en un viento no turbulento
	f = k1 * (v - p->getVelocity()) + k2;

	p->applyInstForce(f);

}
