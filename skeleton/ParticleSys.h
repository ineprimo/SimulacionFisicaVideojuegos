#pragma once
#include <list>
#include <random>
#include <iostream>
#include "Particle.h"
#include "System.h"
#include "GravityForceGenerator.h"
#include "WindForceGenerator.h"
#include "TornadoGenerator.h"
#include "ExplosionGenerator.h"
#include "SpringForceGenerator.h"


class ParticleSys : public System {
protected:
	std::list<Particle*> particleList;
	std::list<Particle*> particleListToDelete;

	//std::uniform_real_distribution<double> d(0,1);
	std::default_random_engine generator;


	double timeElapsed;
	double cooldown = 300;

	Vector3 v;
	Vector3 a;
	Vector4 c;

	int var, med;

	Vector3 offset;
	int mass;


	Vector3 g;		// gravedad

	// fuerzas
	GravityForceGenerator* gfGen = nullptr;
	WindForceGenerator* wGen = nullptr;
	TornadoGenerator* tGen = nullptr;
	ExplosionGenerator* eGen = nullptr;
	SpringForceGenerator* sGen = nullptr;

public:
	ParticleSys(Vector3 _v, Vector3 _a, Vector4 _c, Vector3 o_, int _med, int _var);
	~ParticleSys();


	void update(double t) override;

	virtual Particle* generateParticle();

	void destroyParticles();

	void countCooldown();  

	void addParticle();

	void setGravity(Vector3 g_) { g = g_; }

	void setGravForgeGen(GravityForceGenerator* g) { gfGen = g; };
	void setWindForgeGen(WindForceGenerator* g) { wGen = g; };
	void setTornadoGen(TornadoGenerator* g) { tGen = g; };
	void setExplosionGen(ExplosionGenerator* g) { eGen = g; };
	void setSpringGen(SpringForceGenerator* g) { sGen = g; };

	ForceGen* getGravForgeGen() { return gfGen; };
	ForceGen* getWindForgeGen() { return wGen; };
	ForceGen* getTornadoGen() { return tGen; };
	ForceGen* getExplosionGen() { return eGen; };
	ForceGen* getSpringGen() { return sGen; };



	void setMass(int m_) { mass = m_; }


	void hide();
	void show();

};