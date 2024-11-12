#pragma once
#include <list>
#include <random>
#include <iostream>
#include "Particle.h"
#include "GravityForceGenerator.h"


class ParticleSys {
protected:
	std::list<Particle*> particleList;
	std::list<Particle*> particleListToDelete;

	//std::uniform_real_distribution<double> d(0,1);
	std::default_random_engine generator;


	double timeElapsed;
	double cooldown;

	Vector3 v;
	Vector3 a;
	Vector4 c;

	int var, med;

	Vector3 offset;


	Vector3 g;		// gravedad

	// fuerzas
	GravityForceGenerator* gfGen;

public:
	ParticleSys(Vector3 _v, Vector3 _a, Vector4 _c, Vector3 o_, int _med, int _var);
	~ParticleSys();


	void update(double t);

	virtual Particle* generateParticle();

	void destroyParticles();

	void countCooldown();  

	void applyGravity(Particle* p);

	void addParticle(Particle* p);

	void setGravity(Vector3 g_) { g = g_; }



};