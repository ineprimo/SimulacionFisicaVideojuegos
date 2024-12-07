#include "GameScene.h"
#include "SolidoRigido.h"

GameScene::GameScene(PxScene* scene_, PxPhysics* phisics_)
	: _scene(scene_), _phisics(phisics_)
{
	setScene();
}

GameScene::~GameScene()
{
}

void GameScene::update(float t)
{
}

void GameScene::setScene()
{
	// PxScene* _scene, PxPhysics* _physics, 
	// PxTransform ori, Vector3 vel, Vector3 ang_vel, 
	// Vector3 size, float density, Vector4 color
	auto* solid = new SolidoRigido(_scene, _phisics, {0,0,0}, {0,0,0}, {0,0,0}, {1,1,1}, 2, {1,0,0,1});
	objects.push_back(solid);


	auto* suelo = new SolidoRigido();
	suelo->StaticRigidSolid(_scene, _phisics, {0,0,0}, {10,0.2,10}, {0,1,0,1});
	suelo->Static()->setGlobalPose({0,-10, 0});

	objects.push_back(suelo);


	//GetCamera()->getTransform().p = {0,50,50};
	//GetCamera()->getDir() = {0,-0.5,-1};
}

void GameScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
}
