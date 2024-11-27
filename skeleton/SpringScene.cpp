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
	Particle* anchor = new Particle({ 200,0,0 }, { 0,0,0 }, { 0,0,0 }, { 1,0,0,1 });
	Particle* part = new Particle({ 200,0,0 }, { 0,0,0 }, { 0,0,0 }, { 1,0,0,1 });

	SpringSystem* sys = new SpringSystem(anchor, part);

	// 

	// TO DO
	SpringForceGenerator* aux = new SpringForceGenerator(1, 1, anchor);
	gen = aux;

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
