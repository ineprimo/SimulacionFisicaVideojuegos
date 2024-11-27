#include "SpringForceGenerator.h"
#include "Particle.h"


SpringForceGenerator::SpringForceGenerator(float k_, double rest_, Particle* p_)
	: ForceGen(), k(k_), rest(rest_), anchor(p_)
{
}

SpringForceGenerator::~SpringForceGenerator()
{


}

void SpringForceGenerator::updateForce(double t, Particle* p)
{
	Vector3 f = { 0,0,0 };

	if (active) {

		f = force(t, p);
		p->addForce(f);

	}
}

Vector3 SpringForceGenerator::force(double t, Particle* p)
{
	Vector3 f = { 0,0,0 };

	// distancia
	Vector3 d = anchor->getPosition() - p->getPosition();

	const float delta = d.normalize() - rest;

	f = -k * delta * d;

	return f;
}
