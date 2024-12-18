#pragma once
#include "ParticleSys.h"

class FountainSystem : public ParticleSys
{

private:

	int partcant = 50;

	float volume = 1;;
public:
	FountainSystem(physx::PxVec3 _v, physx::PxVec3 _a, physx::PxVec4 _c, physx::PxVec3 o_);
	FountainSystem(physx::PxVec3 _v, physx::PxVec3 _a, physx::PxVec4 _c, physx::PxVec3 o_, float vol, int mas);
	~FountainSystem();

	std::vector<Particle*> generateParticle() override;
};

