#pragma once
#include "WindForceGenerator.h"


class TornadoGenerator : public WindForceGenerator
{
public:
	TornadoGenerator(Vector3 v_);
	~TornadoGenerator ();

	void updateForce(double t, Particle* p) override;
	Vector3 force(Particle* p) override;

private:

	float k = 10;
};

