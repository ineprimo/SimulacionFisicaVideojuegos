#include "GameScene.h"
#include "SolidoRigido.h"
#include "SprinklerSystem.h"
#include "GravityForceGenerator.h"

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
	for (auto d : debug)
		d->update(t);

	updateSprinkler(direction);

	Scene::update(t);

	checkCollisions();

	dircd -= 1;
}


void GameScene::createSprinkler(Vector3 pos)
{
	// ------------------  ASPERSOR
	Vector3 v = { 5,0,5 };
	sprinkler = new SprinklerSystem(v, { 0,0,0 }, { 0,0,1,1 }, pos, 3, 1, 5, 2, 5);
	systems.push_back(sprinkler);

}
void GameScene::setScene()
{
	// PxScene* _scene, PxPhysics* _physics, 
	// PxTransform ori, Vector3 vel, Vector3 ang_vel, 
	// Vector3 size, float density, Vector4 color
	auto* solid = new SolidoRigido(_scene, _phisics, {0,0,0}, {0,0,0}, {0,0,0}, {1,1,1}, 2, {1,0,0,1});
	objects.push_back(solid);

	// suelo (tierra)
	createFloor(10,10);

	// aspersor
	createSprinkler({ 0,-10,0 });
	
	prepareCollisionDebug();

	// settea la gravedad
	gravity = new GravityForceGenerator({0,-9.8,0});
	//sprinkler->addForceGeneratorToAll(gravity);
	sprinkler->setGravForgeGen(gravity);

	//GetCamera()->getTransform().p = {0,50,50};
	//GetCamera()->getDir() = {0,-0.5,-1};
}

void GameScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	PX_UNUSED(camera);

	switch (toupper(key))
	{
	case 'J':
	{
		{
			if (dircd <= 0) {
				direction = {1,0,0};
			}
		}

		break;
	}
	case 'L':
	{
		{
			if (dircd <= 0) {
				direction = {-1,0,0};
			}
		}

		break;
	}
	case 'I':
	{
		{
			if (dircd <= 0) {
				direction = { 0,0,1 };
			}
		}

		break;
	}
	case 'K':
	{
		{
			if (dircd <= 0) {
				direction = { 0,0,-1 };
			}
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

void GameScene::createFloor(int l, int w)
{
	float posx = (float)- l;
	float posz = (float)- w;
	int color = 0;
	

	std::vector<Block> aux;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) {

			auto* block = new SolidoRigido();
			block->StaticRigidSolid(_scene, _phisics, { posx,-15, posz }, { 2,1,2 }, colors[color]);
			//block->Static()->setGlobalPose({  });

			Block b = Block();
			b.solid = block;
			b.state = DirtState::UNREADY;
			b.cd = 10;

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



void GameScene::prepareCollisionDebug()
{
	// particula como sprinkler
	sprinkler->Active(false);
	//sprinkler->setCD(0);
	//sprinkler->addParticle();

	auto pr = new Particle({ 0,0,0 }, { 0,-5,0 }, { 0,0,0 }, { 1,0,0,1 });
	debug.push_back(pr);

}

void GameScene::updateSprinkler(Vector3 dir)
{
	// movimiento
	if (dir.x == 1) {
		sprinkler->setOffset({sprinkler->getOffset().x + 4, sprinkler->getOffset().y, sprinkler->getOffset().z});
	}
	else if (dir.z == 1) {
		sprinkler->setOffset({ sprinkler->getOffset().x, sprinkler->getOffset().y, sprinkler->getOffset().z + 4 });

	}
	else if (dir.x == -1) {
		sprinkler->setOffset({ sprinkler->getOffset().x - 4, sprinkler->getOffset().y, sprinkler->getOffset().z });

	}
	else if (dir.z == -1) {
		sprinkler->setOffset({ sprinkler->getOffset().x, sprinkler->getOffset().y, sprinkler->getOffset().z -4 });

	}
}

void GameScene::checkCollisions()
{
	// miki no veas esto
	// lia cuando veas esto quiero que sepas que esto realmente es una guarrada
	// pero no se como hacer colisiones si no
	auto p = sprinkler->getParticles();

	for (auto a : flooring) {
		for (auto b : a) {
			for (auto part : debug) {
				if (part->isInsideStatic(b.solid)) {
					std::cout << "COLISIONAAAAA" << std::endl;

					//std::cout << b.solid->Position().z << std::endl;
					if (b.cd < b.timer) {
						// cambia de estado
						b.Next();
						b.UpdateColor(this);
						b.timer = 0;
					}
					else
						b.timer++;
				}
			}

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

void GameScene::Block::Next()
{
	switch (state) {
	case 0:
		state = DirtState::INPROGRESS;
		break;
	case 1:
		state = DirtState::READY;
		break;
	case 2:
		state = DirtState::DONE;
		break;
	case 3:
		state = DirtState::UNREADY;
		break;
	}
}

void GameScene::Block::UpdateColor(GameScene* s)
{
	solid->Color(s->colors[(int)state]);

}
