#pragma once
#include "ForceGen.h"

class BuoyancyForceGenerator : public ForceGen
{
public:
	BuoyancyForceGenerator(Vector3 pos,float density, float volume, float height);
	~BuoyancyForceGenerator();

	void updateForce(double t, Particle* p) override;
	Vector3 force(double t, Particle* p) override;


private:
	double immersed;
	float _height;
	float h0, h;

	float _liquid_density; 
	float _volume;

	Vector3 position;

	 
};

