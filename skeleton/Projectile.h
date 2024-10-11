#pragma once

#include "Particle.h"

class Projectile : public Particle {
public:

	Projectile();
	Projectile(Particle* p);	// WIP
	Projectile(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_);
	Projectile(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_, double d_);
	Projectile(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_, double d_, float r_);
	~Projectile();

	void setGravity(Vector3 g) { gravity = g; };
	void setForce(Vector3 f) { force = f; };
	void setMasa(float m) { masa = m; };

	bool update(double t) override;


private:

	// F = ma;
	Vector3 force;	// en N
	float masa;		// en kg
	Vector3 a;		// en m/s

	// ----------
	Vector3 gravity = {0, -9.8, 0};	//


};