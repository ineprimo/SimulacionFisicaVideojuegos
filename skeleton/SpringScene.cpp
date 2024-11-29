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
	Particle* anchor = new Particle({ 0,20,0 }, { 0,0,0 }, { 0,0,0 }, { 0.87, 0.34, 0.57, 1.0 });
	Particle* part = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,0,0 }, { 0.87, 0, 0, 1.0 }, 0.5);

	anchor->setMass(1);
	part->setMass(1);

	anchor->setVisibility(false);
	part->setVisibility(false);

	SpringSystem* sys = new SpringSystem(anchor, part);

	// 

	// TO DO
	SpringForceGenerator* aux = new SpringForceGenerator(20, 15, anchor);
	gen = aux;
	sys->addForceGeneratorToAll(aux);

	GravityForceGenerator* gravity = new GravityForceGenerator({0, -9.8, 0});
	sys->addForceGenerator(gravity, part);

	systems.push_back(sys);


	// ---------------------------------- EJERCICIO DOS
	// particula anchor
	Particle* anchor2 = new Particle({ 10,40,0 }, { 0,0,0 }, { 0,0,0 }, { 0.87, 0.34, 0.57, 1.0 });
	Particle* part2 = new Particle({ 10,20,0 }, { 0,0,0 }, { 0,0,0 }, { 0.87, 0, 0, 1.0 }, 0.5);
	Particle* part3 = new Particle({ 10,0,0 }, { 0,0,0 }, { 0,0,0 }, { 0, 0.87, 0, 1.0 }, 0.5);
	Particle* part4 = new Particle({ 10,-20,0 }, { 0,0,0 }, { 0,0,0 }, { 0, 0, 0.87, 1.0 }, 0.5);
	anchor2->setMass(1);
	part2->setMass(1);
	part3->setMass(1);
	part4->setMass(1);

	anchor2->setVisibility(false);
	part2->setVisibility(false);
	part3->setVisibility(false);
	part4->setVisibility(false);

	SpringSystem* sys2 = new SpringSystem(anchor2, part2);
	SpringSystem* sys3 = new SpringSystem(part2, part3);
	SpringSystem* sys4 = new SpringSystem(part3, part4);

	// 

	// TO DO
	SpringForceGenerator* aux2 = new SpringForceGenerator(20, 15, anchor2);
	SpringForceGenerator* aux3 = new SpringForceGenerator(20, 15, part2);
	SpringForceGenerator* aux4 = new SpringForceGenerator(20, 15, part3);
	//gen = aux2;
	sys2->addForceGeneratorToAll(aux2);
	sys3->addForceGeneratorToAll(aux3);
	sys4->addForceGeneratorToAll(aux4);

	sys2->addForceGenerator(gravity, part2);
	sys3->addForceGenerator(gravity, part3);
	sys4->addForceGenerator(gravity, part4);

	systems.push_back(sys2);
	systems.push_back(sys3);
	systems.push_back(sys4);



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
