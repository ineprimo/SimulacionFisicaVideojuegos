#include "SpringScene.h"

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

	Vector3 v = { 10, 0,10 };
	Vector3 offset = { 0, 0, 0 };
	Vector3 a = { 0,2,0 };
	Vector4 c = { 0.0, 1.0, 0.9, 1.0 };
	ParticleSys* sys = new ParticleSys(v, a, c, offset, 3, 1);
	sys->setMass(1);



	// TO DO
	/*SpringForceGenerator* aux = new SpringForceGenerator();
	gen = aux;
	sys->setTornadoGen(aux);
*/

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
