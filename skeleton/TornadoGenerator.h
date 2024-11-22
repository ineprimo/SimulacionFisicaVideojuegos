#pragma once
#include "WindForceGenerator.h"


class TornadoGenerator : public WindForceGenerator
{
public:
	TornadoGenerator(Vector3 v_, float k1_, Vector3 k2_, float k_);
	~TornadoGenerator ();

	void updateForce(double t, Particle* p) override;
	Vector3 force(double t, Particle* p) override;

private:

	float k = 10;
};

