#include "FountainSystem.h"

FountainSystem::FountainSystem(physx::PxVec3 _v, physx::PxVec3 _a, physx::PxVec4 _c, physx::PxVec3 o_)
	: ParticleSys(_v, _a, _c, o_, 0,0)
{

}

FountainSystem::~FountainSystem()
{
}

Particle* FountainSystem::generateParticle()
{
	// settea randoms


	const Vector3 u = GetCamera()->getTransform().p;// { 0,0,0 };
	const Vector3 p = { u.x + offset.x,
						u.y + offset.y,
						u.z + offset.z}; // 


	std::normal_distribution<double> rand(3.0, 1.0);
	Particle* pr;

	for (int i = 0; i < partcant; i++) {

		int randx = rand(generator);
		int randy = rand(generator);
		int randz = rand(generator);

		const Vector3 auxv = { randx * v.x, randy * v.y, randz * v.z };

		pr = new Particle(p, auxv, g, c);
		particles.push_back(pr);
	}

	return pr;
}
