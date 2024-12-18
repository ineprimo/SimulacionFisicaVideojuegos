#include "GameScene.h"
#include "SolidoRigido.h"
#include "SprinklerSystem.h"
#include "GravityForceGenerator.h"
#include "ExplosionGenerator.h"
#include "BombSys.h"
#include "FountainSystem.h"
#include "BuoyancyForceGenerator.h"

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

	updateFlooring();

	checkCollisions();

	if (!ended && isComplete()) {

		celebrate();
		std::cout << "WELL DONE!" << std::endl;
		ended = true;
	}

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
	createFloor(10, 10);

	// aspersor
	createSprinkler({ 0,10,0 });

	//
	setManure();

	// 
	prepareSea();
	
	//prepareCollisionDebug();

	// settea la gravedad
	gravity = new GravityForceGenerator({0,-9.8,0});
	explosion = new ExplosionGenerator({0,0,0});
	buoyancy = new BuoyancyForceGenerator({0,0,0}, 998, 10, 4); // kg/m^3
	explosion->Activate(false);
	sprinkler->setGravForgeGen(gravity);
	manure->setGravForgeGen(gravity);
	sprinkler->setExplosionGen(explosion);
	manure->setExplosionGen(explosion);

	//GetCamera()->getTransform().p = {0,50,50};
	//GetCamera()->getDir() = {0,-0.5,-1};

	current_sys = sprinkler;
}

void GameScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	PX_UNUSED(camera);

	switch (toupper(key))
	{
	case 'J':
	{
		{
			if(current_sys->getOffset().x > -stage_bounds.x)
				current_sys->setOffset({ current_sys->getOffset().x - 1, current_sys->getOffset().y, current_sys->getOffset().z });
		}

		break;
	}
	case 'L':
	{
		{
			if (current_sys->getOffset().x < stage_bounds.x)
				current_sys->setOffset({ current_sys->getOffset().x + 1, current_sys->getOffset().y, current_sys->getOffset().z });

		}

		break;
	}
	case 'I':
	{
		{
			if (current_sys->getOffset().z > -stage_bounds.z)
				current_sys->setOffset({ current_sys->getOffset().x, current_sys->getOffset().y, current_sys->getOffset().z - 1});

		}

		break;
	}
	case 'K':
	{
		{
			if (current_sys->getOffset().z < stage_bounds.z)
				current_sys->setOffset({ current_sys->getOffset().x, current_sys->getOffset().y, current_sys->getOffset().z + 1});
		}

		break;
	}
	case 'P':
	{
		{
			manure->Active(!manure->Active());
		}

		break;
	}
	case 'U':
	{
		{
			current_sys->setMass(current_sys->getMass() + 1);
			std::cout << current_sys->getMass() << std::endl;
		}

		break;
	}	
	case 'O':
	{
		{
			if(current_sys->getMass() > 1)
				current_sys->setMass(current_sys->getMass() - 1);
			std::cout << current_sys->getMass() << std::endl;

		}

		break;
	}

	case 'B':
	{
		{
			// bomba
			std::cout << "BOMBA" << std::endl;
			explosion->Activate(!explosion->isActive());

		}

		break;
	}
	case '1':
	{
		{
			current_sys = sprinkler;
		}

		break;
	}
	case '2':
	{
		{
			current_sys = manure;
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
	stage_bounds = {((float)l/2)*4, 1, ((float)w/2) *4};

	float posx = (float)- l/2;
	posx *= 4;
	float posz = (float)- w/2;
	posz *= 4;
	int color = 0;
	

	std::vector<Block*> aux;
	std::vector<bool> comp;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) {

			auto* block = new SolidoRigido();
			block->StaticRigidSolid(_scene, _phisics, { posx,5, posz }, { 2,1,2 }, colors[color]);
			//block->Static()->setGlobalPose({  });

			Block* b = new Block();
			b->solid = block;
			b->state = DirtState::UNREADY;
			b->cd = 100;
			b->timer = 100;

			aux.push_back(b);

			color++;
			if (color == 4)
				color = 0;
			posx += 4;
			
			comp.push_back(false);

		}
		posz += 4;
		posx = (float)-w/2;
		posx *= 4;


		flooring.push_back(aux);
		complete.push_back(comp);
		aux.clear();
		comp.clear();
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
	//if (dir.x == 1) {
	//	sprinkler->setOffset({sprinkler->getOffset().x + 4, sprinkler->getOffset().y, sprinkler->getOffset().z});
	//}
	//else if (dir.z == 1) {
	//	sprinkler->setOffset({ sprinkler->getOffset().x, sprinkler->getOffset().y, sprinkler->getOffset().z + 4 });

	//}
	//else if (dir.x == -1) {
	//	sprinkler->setOffset({ sprinkler->getOffset().x - 4, sprinkler->getOffset().y, sprinkler->getOffset().z });

	//}
	//else if (dir.z == -1) {
	//	sprinkler->setOffset({ sprinkler->getOffset().x, sprinkler->getOffset().y, sprinkler->getOffset().z -4 });

	//}
}

void GameScene::checkCollisions()
{


	// miki no veas esto
	// lia cuando veas esto quiero que sepas que esto realmente es una guarrada
	// pero no se como hacer colisiones si no
	auto p = sprinkler->getParticles();
	auto m = manure->getParticles();

	int i = 0, j = 0;

	for (auto a : flooring) {
		for (auto b : a) {

			for (auto part : p) {
				if (part->isInsideStatic(b->solid)) {
					//std::cout << "COLISIONAAAAA" << std::endl;

					//std::cout << b.solid->Position().z << std::endl;
					if (b->cd <= b->timer) {
						if (b->state == DirtState::READY || b->state == DirtState::INPROGRESS) {
							b->Next();
							b->UpdateColor(this);
							b->resetTimer();
						}
					}
					else
						b->addTimer(1);

				}
			}

			for (auto part : m) {
				if (part->isInsideStatic(b->solid)) {
					//std::cout << "COLISIONAAAAA" << std::endl;

					part->Alive(false);

					//std::cout << b.solid->Position().z << std::endl;
					if (b->cd <= b->timer) {
						if (b->state == DirtState::UNREADY) {
							// cambia de estado
							b->Next();
							b->UpdateColor(this);
							b->resetTimer();

						}
					}
					else
						b->addTimer(1);
				}
			}

			if (b->state == DirtState::DONE) {
				complete[i][j] = true;
			}
			j++;
		}
		j = 0;
		i++;
	}



	// mira si colisiona con el agua
	for (auto part : m) {
		if (part->isInsideStatic(sea) && !part->HasBuoyancy()) {
			// le mete buoyancy

			std::cout << "buoyancy" << std::endl;
			part->addForceGen(buoyancy);
			part->HasBuoyancy(true);

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

void GameScene::updateFlooring()
{


}

bool GameScene::isComplete()
{
	bool aux = true;
	int i = 0, j = 0;
	while (i < complete.size() && j < complete[i].size() && complete[i][j]) {
		j++;
		if (j >= complete[i].size()) {
			i++;
			j = 0;
		}
	}

	if (i >= complete.size()) {
			return true;
	}
	return false;

}

void GameScene::celebrate()
{
	Vector3 a = { 0,0,0 };
	Vector3 v = { 10,10,0 };
	Vector3 offset = { 0,0,0 };
	Vector4 c = { 0.87, 0.34, 0.57, 1.0 };
	celebration = new BombSys(v, a, c, offset, 20);
	celebration->Active(true);
	systems.push_back(celebration);
}

void GameScene::setManure()
{

	Vector3 a = { 0,0,0 };
	Vector3 v = { 1,0,1 };
	Vector4 c = { 0.741, 0.565, 0.251, 1.0 };
	Vector3 offset = { 0, 10, 0};
	manure = new FountainSystem(v, a, c, offset, 40, 9000);
	manure->Active(false);
	systems.push_back(manure);
}

void GameScene::prepareSea()
{
	// bloque que hace de agua
	sea = new SolidoRigido();
	sea->StaticRigidSolid(_scene, _phisics, { 0,0, 0 }, { 200,0.3,200 }, {0.376,0.741,0.761,1});

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
		//state = DirtState::UNREADY;
		break;
	}
}

void GameScene::Block::UpdateColor(GameScene* s)
{
	solid->Color(s->colors[(int)state]);

}

void GameScene::Block::addTimer(int a)
{
	timer += a;
}
