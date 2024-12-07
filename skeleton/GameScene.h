#pragma once
#include "Scene.h"
class GameScene : public Scene
{
public:

	GameScene();
	~GameScene();


private:

	void update(float t) override;
	void setScene() override;
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;

};

