#pragma once
#include "Scene.h"
class SolidoRigido;

class SprinklerSystem;
class GravityForceGenerator;

class GameScene : public Scene
{
public:

	GameScene(PxScene* scene_, PxPhysics* phisics_);
	~GameScene();

	void update(float t) override;
	void setScene() override;
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;

private:


	Vector3 direction;
	int dircd = 10;
	PxScene* _scene;
	PxPhysics* _phisics;

	enum DirtState {
		UNREADY,		// hay que prepararla
		READY,			// hay que plantar
		INPROGRESS,		// hay que regar
		DONE			// hechoooo
	};
	struct Block {
		DirtState state;
		SolidoRigido* solid;
		float cd;
		float timer = 0;

		void Next();

		void UpdateColor(GameScene* s);
	};

	std::vector<std::vector<Block>> flooring;

	std::vector<Vector4> colors;

	SprinklerSystem* sprinkler;
	GravityForceGenerator* gravity;


	// para crear el suelo con bloques
	void createFloor(int l, int w);

	// para el crecimiento de las plantas (cambia el color)
	void updateDirt();

	// aspersor
	void createSprinkler(Vector3 pos);

	// para mover el sprinkler
	void updateSprinkler(Vector3 dir);

	// para mirar las colisiones
	void checkCollisions();

	void prepareCollisionDebug();

	// --------------- metodos auxiliares ----------
	void prepareColors();


};

