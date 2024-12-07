#include "GameScene.h"
#include "SolidoRigido.h"

GameScene::GameScene(PxScene* scene_, PxPhysics* phisics_)
	: _scene(scene_), _phisics(phisics_)
{
	prepareColors();
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


	/*auto* suelo = new SolidoRigido();
	suelo->StaticRigidSolid(_scene, _phisics, {0,0,0}, {10,0.2,10}, {0,1,0,1});
	suelo->Static()->setGlobalPose({0,-10, 0});

	objects.push_back(suelo);*/
	createFloor(10,10);


	//GetCamera()->getTransform().p = {0,50,50};
	//GetCamera()->getDir() = {0,-0.5,-1};
}

void GameScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
}

void GameScene::createFloor(int l, int w)
{
	float posx = (float)- l;
	float posz = (float)- w;
	int color = 0;

	std::vector<Block> aux;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) {

			auto* block = new SolidoRigido();
			block->StaticRigidSolid(_scene, _phisics, { 0,0,0 }, { 2,1,2 }, colors[color]);
			block->Static()->setGlobalPose({ posx,-15, posz });

			Block b = Block();
			b.solid = block;
			b.state = DirtState::UNREADY;

			aux.push_back(b);

			color++;
			if (color == 4)
				color = 0;
			posx += 4;
			

		}
		posz += 4;
		posx = (float)-w;

		flooring.push_back(aux);
		aux.clear();
	}
}

void GameScene::updateDirt()
{
	for (int i = 0; i < flooring.size(); i++) {
		for (int j = 0; j < flooring.size(); j++) {
			// TO DO
		}
	}
}

void GameScene::prepareColors()
{
	colors.push_back({ 0.678,0.631,0.482,1 });
	colors.push_back({ 0.541,0.333,0.267,1 });
	colors.push_back({ 0.365,0.4,0.286,1 });
	colors.push_back({ 0.502,0.62,0.204,1 });
}
