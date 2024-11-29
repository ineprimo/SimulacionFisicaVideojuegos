#pragma once
#include "Scene.h"

class BuoyancyScene : public Scene
{
public:

	BuoyancyScene();
	~BuoyancyScene();

	void update(float t) override;
	void setScene() override;
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;


	SpringForceGenerator* gen;

private:


};

