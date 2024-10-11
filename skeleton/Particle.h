#pragma once


#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "RenderUtils.hpp"
#include <cmath>


// clase particle

class Particle {
public: 

	Particle(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_);
	Particle(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_, double d_);
	Particle(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_, double d_, float r_);
	~Particle();


	void setMaxTime(double t_) { maxt = t_; }
	void setMaxPos(Vector3 mp_) { maxp = mp_; }


	bool integrate(double t);

private:

	Vector3 vel;	// vel
	Vector3 a;		// aceleracion
	double dump = 0.98;		// dumping, [0,1]
	float rad = 5;			// radio de la particula
	physx::PxTransform pose;	// posicion
	RenderItem* renderItem;		// para verlo

	double maxt;
	Vector3 maxp;


};