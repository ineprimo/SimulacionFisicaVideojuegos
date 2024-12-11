#pragma once
#include "FountainSystem.h"
#include "Scene.h"
class SolidoRigido;

class SprinklerSystem;
class GravityForceGenerator;
class BombSys;
class FountainSys;

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

	Vector3 stage_bounds;

	enum DirtState {
		UNREADY,		// hay que prepararla
		READY,			// hay que plantar
		INPROGRESS,		// hay que regar
		DONE			// hechoooo
	};

	int omfg = 0;
	struct Block {
		DirtState state;
		SolidoRigido* solid;
		int cd;
		int timer;

		void Next();

		void UpdateColor(GameScene* s);

		void addTimer(int a);
		int Cd() { return cd; }
		void resetTimer() { timer = 0; }
	};



	std::vector<std::vector<Block*>> flooring;
	std::vector<std::vector<bool>> complete;
	bool ended = false;


	std::vector<Vector4> colors;
	std::vector<Particle*> debug;

	SprinklerSystem* sprinkler;
	GravityForceGenerator* gravity;
	BombSys* celebration;
	FountainSystem* manure;

	ParticleSys* current_sys = nullptr;

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

	//
	void prepareCollisionDebug();

	// 
	void updateFlooring();

	//
	bool isComplete();

	// 
	void celebrate();

	// 
	void setManure();
	 
	// --------------- metodos auxiliares ----------
	void prepareColors();


};

