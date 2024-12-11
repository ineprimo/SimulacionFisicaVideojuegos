#pragma once
#include "ParticleSys.h"
class BombSys :
    public ParticleSys
{
private:

    bool exploded = false;
    int partnum;
    float pi = 3.1415;



    int cooldown = 3;
    int count = 0;

public:


    BombSys(physx::PxVec3 _v, physx::PxVec3 _a, physx::PxVec4 _c, physx::PxVec3 _o, int p);
    ~BombSys();

    std::vector<Particle*> generateParticle() override;

};

