#pragma once
#include "ParticleSys.h"

class SprinklerSystem : public ParticleSys
{
private:
	float pi = 3.1415;
	int alpha = 0, beta = 0, delta = 0;

	int cooldown;
	int counter = 0;

	int particlenum;
	int particlecount = 0;

	int anglesum;


public:
	SprinklerSystem(physx::PxVec3 _v, physx::PxVec3 _a, physx::PxVec4 _c, physx::PxVec3 o_, int _med, int _var, int pnum, int cd, int angles);
	~SprinklerSystem();



	std::vector<Particle*> generateParticle() override;


	void setCD(int c);
	void setPartNum(int p);

};

