#include "GravityForceGenerator.h"



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
	p->applyInstForce(gravity * t * p->getMass());

}
