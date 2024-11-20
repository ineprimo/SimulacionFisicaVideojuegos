#pragma once


#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "RenderUtils.hpp"
#include <cmath>

class ForceGen;

// clase particle

class Particle {
public: 

	Particle(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_);
	Particle(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_, double d_);
	Particle(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_, double d_, float r_);
	~Particle();


	void setMaxTime(double t_) { maxt = t_; }
	void setMaxPos(Vector3 mp_) { maxp = mp_; }
	RenderItem* getRenderItem() { return renderItem; }
	void setMass(float m) { mass = m; }
	float getMass() { return mass; }
	Vector3 getAcceleration() { return a; }
	void setAcceleration(Vector3 a_) { a = a_; }
	Vector3 getVelocity() { return vel; }
	void setVelocity(Vector3 v_) { vel = v_; }

	Vector3 getPosition() { return pose.p; }

	bool integrate(double t);

	virtual bool update(double t);

	void applyForce();
	void addForce(Vector3 f);
	void addForceGen(ForceGen* f);
	void applyContForce(Vector3 f);
	void applyInstForce(Vector3 f);


	void setVisibility(bool a);

private:

	Vector3 vel;	// vel
	Vector3 a;		// aceleracion
	double dump = 0.98;		// dumping, [0,1]
	float rad = 5;			// radio de la particula
	physx::PxTransform pose;	// posicion
	RenderItem* renderItem;		// para verlo

	double maxt;
	Vector3 maxp;

	float mass;


	std::vector<ForceGen*> forceGens;
	std::vector<Vector3> forces;

};