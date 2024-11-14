#pragma once
#include "ForceGen.h"
class WindForceGenerator : public ForceGen
{
public:
	WindForceGenerator(Vector3 v_);
	~WindForceGenerator();

	void updateForce(double t, Particle* p) override;



private:
	Vector3 v = { 0,0,0 };

	// rozamientos
	float k1 = 10;
	Vector3 k2 = { -10,0,0 };
};

