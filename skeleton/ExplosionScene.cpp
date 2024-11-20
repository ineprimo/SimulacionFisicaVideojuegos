#include "ExplosionScene.h"

ExplosionScene::ExplosionScene() : Scene()
{
	setScene();

}

ExplosionScene::~ExplosionScene()
{


}

void ExplosionScene::update(float t)
{
	Scene::update(t);

}

void ExplosionScene::setScene()
{

	Vector3 v = { 0, 0,0 };
	Vector3 offset = { 0, 0, 0 };
	Vector3 a = {0,2,0};
	Vector4 c = { 0.0, 1.0, 0.9, 1.0 };

	ParticleSys* sys = new ParticleSys(v, a, c, offset, 3, 1);
	sys->setMass(1);
	ExplosionGenerator* aux = new ExplosionGenerator({ 0,0, 0 });
	gen = aux;
	sys->setExplosionGen(aux);
	sys->getExplosionGen()->Activate(false);


	systems.push_back(sys);
}

void ExplosionScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	PX_UNUSED(camera);

	switch (toupper(key))
	{
	case 'B':
	{
		{
			gen->Activate(!gen->isActive());
		}

		break;
	}
	case ' ':
	{
		break;
	}
	default:
		break;
	}

}
