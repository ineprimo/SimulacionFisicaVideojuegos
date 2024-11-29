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
}

void BuoyancyScene::setScene()
{

	std::vector<Particle*> part_vec;

	int n = 10;
	for (int i = 0; i < n; i++) {
		Particle* part = new Particle({ 0,20,0 }, { 0,0,0 }, { 0,0,0 }, { 0.87, 0.34, 0.57, 1.0 });
		part->setVisibility(false);
		part->setMass(1);
		
		part_vec.push_back(part);
	}

	BuoyancyParticleSystem* aux = new BuoyancyParticleSystem(part_vec);
	//BuoyancyForceGenerator* force = new BuoyancyForceGenerator({0,0,0}, 1.0f, 1.0f, 2.0f);
	//aux->addForceGeneratorToAll(force);

	systems.push_back(aux);


}

void BuoyancyScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{


}
