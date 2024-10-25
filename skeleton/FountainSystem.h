#pragma once
#include "ParticleSys.h"

class FountainSystem : public ParticleSys
{
public:
	FountainSystem(physx::PxVec3 _v, physx::PxVec3 _a, physx::PxVec4 _c, physx::PxVec3 o_, int _med, int _var);
	~FountainSystem();

	void generateParticle() override;
};

