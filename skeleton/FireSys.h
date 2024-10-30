#pragma once
#include "ParticleSys.h"
class FireSys :
    public ParticleSys
{
private:
    int partnum;

public:


    FireSys(physx::PxVec3 _v, physx::PxVec3 _a, physx::PxVec4 _c, physx::PxVec3 _o, int p);
    ~FireSys();


    void generateParticle() override;


};

