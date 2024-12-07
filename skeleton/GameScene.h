#pragma once
#include "Scene.h"
class SolidoRigido;


class GameScene : public Scene
{
public:

	GameScene(PxScene* scene_, PxPhysics* phisics_);
	~GameScene();

	void update(float t) override;
	void setScene() override;
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;

private:

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
	};

	std::vector<std::vector<Block>> flooring;

	std::vector<Vector4> colors;


	// para crear el suelo con bloques
	void createFloor(int l, int w);

	// para el crecimiento de las plantas (cambia el color)
	void updateDirt();


	// --------------- metodos auxiliares ----------
	void prepareColors();


};

