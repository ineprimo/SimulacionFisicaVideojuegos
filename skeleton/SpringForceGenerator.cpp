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

	//
	float length = relative_pos.magnitude();
	relative_pos.normalize();

	const float delta = length - rest;
	//std::cout << "delta: " << delta << std::endl;
	//std::cout << "length: " << length << std::endl;

	//const float delta = max(0.0f, d.normalize() - rest);

	// direccion, distancia y constante
	f = relative_pos * delta * k;


	//std::cout << "holaaaaaaaa " << relative_pos.y << " " << delta << std::endl;

	if (p != anchor)
		//std::cout << "FUERZA: " << f.y << std::endl;

	return f;
}
