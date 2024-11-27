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

		if(p != anchor)
			f = force(t, p);
		p->addForce(f);

	}
}

Vector3 SpringForceGenerator::force(double t, Particle* p)
{
	Vector3 f = { 0,0,0 };

	// distancia
	Vector3 relative_pos = anchor->getPosition() - p->getPosition();

	float length = relative_pos.normalize();
	const float delta = length - rest;
	//const float delta = max(0.0f, d.normalize() - rest);

	f = relative_pos * delta * k;

	if (p != anchor)
		std::cout << f.y << std::endl;

	return f;
}
