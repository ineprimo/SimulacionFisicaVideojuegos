#pragma once
#include "ForceGen.h"
class WindForceGenerator : public ForceGen
{
public:
	WindForceGenerator(Vector3 v_);
	~WindForceGenerator();

	void updateForce(double t, Particle* p) override;
	Vector3 force(Particle* p) override;



private:
	Vector3 v = { 0,0,0 };

	// rozamientos
	float k1 = 10;
	Vector3 k2 = { 0,0,0 };
};

