#include "WindScene.h"

WindScene::WindScene() : Scene()
{
	setScene();

}

WindScene::~WindScene()
{
}

void WindScene::update(float t)
{
	Scene::update(t);

}

void WindScene::setScene()
{
	Vector3 v = { 0, 0,0 };
	Vector3 offset = { 0, 0, 0 };
	Vector3 a = { 0,2,0 };
	Vector4 c = { 0.0, 1.0, 0.9, 1.0 };
	ParticleSys* sys = new ParticleSys(v, a, c, offset, 3, 1);
	sys->setMass(1);
	WindForceGenerator* aux = new WindForceGenerator({10,10, -10});
	gen = aux;
	sys->setWindForgeGen(aux);

	systems.push_back(sys);

}

void WindScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
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
