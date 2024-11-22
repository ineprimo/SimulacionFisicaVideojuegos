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
