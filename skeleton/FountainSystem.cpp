#include "FountainSystem.h"

FountainSystem::FountainSystem(physx::PxVec3 _v, physx::PxVec3 _a, physx::PxVec4 _c, physx::PxVec3 o_, int _med, int _var)
	: ParticleSys(_v, _a, _c, o_, _med, _var)
{

}

FountainSystem::~FountainSystem()
{
}

void FountainSystem::generateParticle()
{

}
