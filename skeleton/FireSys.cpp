#include "FireSys.h"

FireSys::FireSys(physx::PxVec3 _v, physx::PxVec3 _a, physx::PxVec4 _c, physx::PxVec3 _o, int p)
	: ParticleSys(_v, _a, _c, _o, 0,0), partnum(p)
{
}

FireSys::~FireSys()
{
}

void FireSys::generateParticle()
{





}
