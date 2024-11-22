#pragma once
#include "ForceGen.h"


class SpringForceGenerator : public ForceGen
{
public:
	SpringForceGenerator(float k_, double rest_, Particle* p_);
	~SpringForceGenerator();

	void updateForce(double t, Particle* p) override;
	Vector3 force(double t, Particle* p) override;


private:

	float k = 1;		// constant
	double rest = 0;	// resisting length
	Particle* anchor = nullptr;
};

