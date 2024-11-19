#include "ExplosionGenerator.h"
#include "Particle.h"

ExplosionGenerator::ExplosionGenerator(Vector3 pos_)
{
}

ExplosionGenerator::~ExplosionGenerator()
{
}

void ExplosionGenerator::updateForce(double t, Particle* p)
{
	Vector3 f = { 0,0,0 };

	if (active) {

		f = force(t, p);
		p->addForce(f);

	}
}

Vector3 ExplosionGenerator::force(double t, Particle* p)
{
	Vector3 f(0, 0, 0);

	// distancia al centro de la explosion
	float dist = (p->getPosition() - position).magnitude();
	// si la distancia es menor que el radio la fuerza es 0
	//if (dist >= radio) return f; 
	//std::cout << "bomba" << std::endl;

	f = ((k / radio* radio) * (p->getPosition() - position)) * exp(-t / tau);
	//f = ((k / radio * radio) * (p->getPosition() - position)) * exp(-t / tau);
	return f;
}
