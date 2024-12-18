#pragma once

#include "Object.h"
#include <cmath>

class ForceGen;

// clase particle

class Particle : public Object {
public: 

	Particle(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_);
	Particle(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_, double d_);
	Particle(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_, double d_, float r_);
	~Particle();


	void setMaxTime(double t_) { maxt = t_; }
	void setMaxPos(Vector3 mp_) { maxp = mp_; }
	void setMass(float m) { mass = m; }
	float getMass() { return mass; }
	Vector3 getAcceleration() { return a; }
	void setAcceleration(Vector3 a_) { a = a_; }
	Vector3 getVelocity() { return vel; }
	void setVelocity(Vector3 v_) { vel = v_; }
	void setDumping(float d) { dump = d; };

	void setVolume(float vol) { _volume = vol; };
	float getVolume() { return _volume; };

	Vector3 getPosition() { return pose.p; }

	bool integrate(double t);

	virtual bool update(double t) override;

	void applyForce();
	void addForce(Vector3 f);
	void addForceGen(ForceGen* f);
	void applyContForce(Vector3 f);
	void applyInstForce(Vector3 f);

	void setType(int i) { type = i; }

	bool collides();

	void setVisibility(bool a) override;


	void HasBuoyancy(bool a) { hasBuoyancy = a; };
	bool HasBuoyancy() { return hasBuoyancy; };

private:

	Vector3 vel;	// vel
	Vector3 a;		// aceleracion
	double dump = 0.98;		// dumping, [0,1]
	float rad = 1;			// radio de la particula
	physx::PxTransform pose;	// posicion
	double maxt;
	Vector3 maxp;

	float _volume;
	float mass;

	int type = -1;

	std::vector<ForceGen*> forceGens;
	std::vector<Vector3> forces;


	// guarrada pero bueno
	bool hasBuoyancy = false;

};