#include "WindForceGenerator.h"
#include "Particle.h"
#include <math.h>

WindForceGenerator::WindForceGenerator(Vector3 v_, float k1_, Vector3 k2_)
	: v(v_), k1(k1_), k2(k2_)
{

}

WindForceGenerator::~WindForceGenerator()
{

}

void WindForceGenerator::updateForce(double t, Particle* p)
{

	Vector3 f = force(t, p);

	//p->addForce(f);
	p->applyInstForce(f);

}

Vector3 WindForceGenerator::force(double t, Particle* p)
{
	Vector3 f(0, 0, 0);
	Vector3 aux = (v - p->getVelocity());
	// calculo de la fuerza en un viento no turbulento
	f = k1 * aux  + k2; // k2 es 0 asi que obvio el resto de la formula

	//std::cout << k1 << " " << (p->getVelocity()).z << " " << (p->getVelocity()).y << " " << (p->getVelocity()).z << std::endl;
	//std::cout << f.x << " " << f.y << " " << " " << f.z << std::endl;
	return f;
}
