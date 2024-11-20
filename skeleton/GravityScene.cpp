#include "GravityScene.h"

GravityScene::GravityScene() : Scene()
{
	setScene();

}

GravityScene::~GravityScene()
{
}

void GravityScene::update(float t)
{
	Scene::update(t);

}

void GravityScene::setScene()
{
	Vector3 p = {0,0,0};
	Vector3 v = {0,2,0};
	Vector3 a = {0,2,0};
	Vector3 offset = { 0, 0, 0 };
	Vector4 c = { 0.0, 1.0, 0.9, 1.0 };


	v = { 0, 0,0 };
	offset = { 0, 0, 0 };
	ParticleSys* sys = new ParticleSys(v, a, c, offset, 3, 1);
	sys->setMass(1);
	GravityForceGenerator* aux = new GravityForceGenerator({0,-9.8, 0});
	sys->setGravForgeGen(aux);
	offset = { -200, 0, 200 };


	c = { 1.0, 0.0, 0.0, 1.0 };
	ParticleSys* sys2 = new ParticleSys(v, a, c, offset, 3, 1);
	sys2->setMass(1000);
	aux = new GravityForceGenerator({ 0,-9.8, 0 });
	gen2 = aux;
	sys2->setGravForgeGen(aux);

	systems.push_back(sys);
	systems.push_back(sys2);

}

void GravityScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
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
