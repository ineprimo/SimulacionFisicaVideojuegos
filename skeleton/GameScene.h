#pragma once
#include "Scene.h"

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


};

