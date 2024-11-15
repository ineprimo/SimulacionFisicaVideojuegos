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

	std::cout << t << std::endl;
	f = force(t, p);

	p->addForce(f);
}

Vector3 ExplosionGenerator::force(double t, Particle* p)
{
	Vector3 f(0, 0, 0);

	std::cout << t << std::endl;


	if (time < 0 || time >= 4 * t) return f;

	std::cout << "bomba" << std::endl;
	// distancia al centro de la explosion
	float dist = (p->getPosition() - position).magnitude();
	// si la distancia es menor que el radio la fuerza es 0
	if (dist >= radio) return f; 

	f = ((k / pow(dist, 2)) * (p->getPosition() - position)) * exp(-time / tau);

	return f;
}
