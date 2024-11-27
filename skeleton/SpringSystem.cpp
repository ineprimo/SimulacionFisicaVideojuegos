#include "SpringSystem.h"

SpringSystem::SpringSystem(Particle* anchor_, Particle* particle_) 
	: anchor(anchor_), particle(particle_), System()
{


	particles.push_back(anchor);
	particles.push_back(particle);

}

SpringSystem::~SpringSystem()
{

}

//
//Particle* SpringSystem::generateParticle()
//{
//	const Vector3 u = {0,0,0};//GetCamera()->getTransform().p;// { 0,0,0 };
//	const Vector3 p = { u.x + offset.x,
//						u.y + offset.y,
//						u.z + offset.z }; // 
//
//	Particle* pr;
//
//	pr = new Particle(p, {0,0,0}, g, c);
//	particleList.push_back(pr);
//
//	return nullptr;
//}
