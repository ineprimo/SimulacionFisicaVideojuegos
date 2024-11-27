#include "SpringScene.h"
#include "SpringSystem.h"

SpringScene::SpringScene()
	: Scene()
{
	setScene();

}

SpringScene::~SpringScene()
{


}

void SpringScene::update(float t)
{
	Scene::update(t);


}

void SpringScene::setScene()
{
	// particula anchor
	Particle* anchor = new Particle({ 0,50,0 }, { 0,0,0 }, { 0,0,0 }, { 0.87, 0.34, 0.57, 1.0 });
	Particle* part = new Particle({ 0,30,0 }, { 0,0,0 }, { 0,0,0 }, { 0.87, 0, 0, 1.0 });

	anchor->setMass(1);
	part->setMass(2);

	anchor->setVisibility(false);
	part->setVisibility(false);

	SpringSystem* sys = new SpringSystem(anchor, part);

	// 

	// TO DO
	SpringForceGenerator* aux = new SpringForceGenerator(50, 1, anchor);
	gen = aux;
	sys->addForceGeneratorToAll(aux);

	systems.push_back(sys);
}

void SpringScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	PX_UNUSED(camera);

	switch (toupper(key))
	{
	case 'B':
	{
		{
		}

		break;
	}
	default:
		break;
	}

}
