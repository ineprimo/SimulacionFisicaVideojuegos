#pragma once
#include "ForceGen.h"
class ExplosionGenerator : public ForceGen
{
public:
	ExplosionGenerator(Vector3 pos_);
	~ExplosionGenerator();


	void updateForce(double t, Particle* p) override;
	Vector3 force(double t, Particle* p) override;

	void setAll(float _k, float _tau, float _ve, float _time, float _radio);

private:
	float k = 100;
	float tau = 0.05;
	float ve = 125; 
	float time = 10;
	float radio = 100;

	Vector3 position = {0,0,0};


};

