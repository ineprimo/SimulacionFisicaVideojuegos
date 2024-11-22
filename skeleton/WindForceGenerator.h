#pragma once
#include "ForceGen.h"
class WindForceGenerator : public ForceGen
{
public:
	WindForceGenerator(Vector3 v_, float k1_, Vector3 k2_);
	~WindForceGenerator();

	void updateForce(double t, Particle* p) override;
	virtual Vector3 force(double t, Particle* p) override;



protected:
	Vector3 v = { 0,0,0 };
	Vector3 position = { 0,0,0 };

	// rozamientos
	float k1 = 10;
	Vector3 k2 = { 0,0,0 };
};

