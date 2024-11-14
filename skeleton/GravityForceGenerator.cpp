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

void GravityForceGenerator::updateGravityForce(double t, Particle* p)
{
	// llama al metodo de la particula ??¿?¿?¿
	// f = m*a => 
	//std::cout << "fuerza/ masa " << gravity.y << "/" << p->getMass() << " = " << gravity.y * p->getMass() << std::endl;
	p->applyInstForce(gravity * t * p->getMass());

}
