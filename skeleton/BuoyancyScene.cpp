#include "BuoyancyScene.h"
#include "BuoyancyParticleSystem.h"
#include "BuoyancyForceGenerator.h"

BuoyancyScene::BuoyancyScene()
{
	setScene();
}

BuoyancyScene::~BuoyancyScene()
{
}

void BuoyancyScene::update(float t)
{
	Scene::update(t);
}

void BuoyancyScene::setScene()
{

	std::vector<Particle*> part_vec;

	BuoyancyParticleSystem* sys = new BuoyancyParticleSystem(part_vec);

	GravityForceGenerator* gravity = new GravityForceGenerator({ 0, -9.8, 0 });
	BuoyancyForceGenerator* bouyancy_force = new BuoyancyForceGenerator({ 0,0,0 }, 1, 5, 5);

	float posx = 0;
	float posy = 0;

	int n = 10;
	for (int i = 0; i < n; i++) {
		Particle* part = new Particle({ posx, posy, 0 }, { 0,0,0 }, { 0,0,0 }, { 0.87, 0.34, 0.57, 1.0 });
		part->setVisibility(false);
		part->setMass(1);
		part_vec.push_back(part);

		posx += 5;
		posy += 5;

	}

	sys->setParticles(part_vec);

	sys->addForceGeneratorToAll(gravity);
	sys->addForceGeneratorToAll(bouyancy_force);

	Particle* part = new Particle({ -5, 0, 0 }, { 0,0,0 }, { 0,0,0 }, { 0.87, 0.34, 0.57, 1.0 });
	part->setVisibility(false);
	part->setMass(1);
	sys->addParticle(part);

	systems.push_back(sys);
}

void BuoyancyScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{


}
