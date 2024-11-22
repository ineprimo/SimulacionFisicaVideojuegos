#include "GravityForceGenerator.h"
#include "Particle.h"


GravityForceGenerator::GravityForceGenerator()
	: gravity({0,0,0})
{

}

GravityForceGenerator::GravityForceGenerator(Vector3 g)
	: gravity(g)
{

}

GravityForceGenerator::~GravityForceGenerator()
{

}

void GravityForceGenerator::updateForce(double t, Particle* p)
{
	// llama al metodo de la particula ??¿?¿?¿
	// f = m*a => 
	//std::cout << "fuerza/ masa " << gravity.y << "/" << p->getMass() << " = " << gravity.y * p->getMass() << std::endl;
	Vector3 f = force(t, p);
	p->addForce(f);

	//p->applyInstForce(f);

}

Vector3 GravityForceGenerator::force(double t, Particle* p)
{
	Vector3 f = gravity * p->getMass();
	return f;
}
