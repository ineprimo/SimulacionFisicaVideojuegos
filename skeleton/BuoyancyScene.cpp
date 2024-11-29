#include "BuoyancyScene.h"
#include "BuoyancyParticleSystem.h"
#include "BuoyancyForceGenerator.h"

BuoyancyScene::BuoyancyScene()
{
}

BuoyancyScene::~BuoyancyScene()
{
}

void BuoyancyScene::update(float t)
{
}

void BuoyancyScene::setScene()
{

	BuoyancyParticleSystem* aux = new BuoyancyParticleSystem();
	//BuoyancyForceGenerator* force = new BuoyancyForceGenerator({0,0,0}, 1.0f, 1.0f, 2.0f);
	//aux->addForceGeneratorToAll(force);


}

void BuoyancyScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
}
