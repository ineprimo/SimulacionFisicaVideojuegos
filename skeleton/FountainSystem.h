#pragma once
#include "ParticleSys.h"

class FountainSystem : public ParticleSys
{

private:

	int partcant = 20;
public:
	FountainSystem(physx::PxVec3 _v, physx::PxVec3 _a, physx::PxVec4 _c, physx::PxVec3 o_);
	~FountainSystem();

	void generateParticle() override;
};

