#pragma once
#include "System.h"
#include <random>
#include "GravityForceGenerator.h"
#include "WindForceGenerator.h"
#include "TornadoGenerator.h"
#include "ExplosionGenerator.h"
#include "SpringForceGenerator.h"

class SolidoRigido;

class Particle;


class SolidoRigidoSystem : public System
{

private:

	int partcant = 5;

	float volume = 1;

	double timeElapsed = 0;
	double cooldown = 300;

	std::vector<SolidoRigido*> solidos;

	PxScene* scene;
	PxPhysics* physics;
	PxTransform position;

	std::default_random_engine generator;

	GravityForceGenerator* gfGen = nullptr;
	WindForceGenerator* wGen = nullptr;
	TornadoGenerator* tGen = nullptr;
	ExplosionGenerator* eGen = nullptr;
	SpringForceGenerator* sGen = nullptr;


public:
	SolidoRigidoSystem(PxScene* _scene, PxPhysics* _physics, PxTransform pos);
	~SolidoRigidoSystem();


	std::vector<SolidoRigido*> generateSolids();

	void update(double t) override;

	void addSolid();

	void wait();


};

