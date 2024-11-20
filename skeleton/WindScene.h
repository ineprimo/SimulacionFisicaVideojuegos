#pragma once
#include "Scene.h"
class WindScene : public Scene
{
public:
	WindScene();
	~WindScene();


private:

	void update(float t) override;
	void setScene() override;
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;


	WindForceGenerator* gen;
};

