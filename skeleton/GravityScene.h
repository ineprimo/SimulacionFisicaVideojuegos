#pragma once
#include "Scene.h"
class GravityScene : public Scene
{


public:
	GravityScene();
	~GravityScene();


private:

	void update(float t) override;
	void setScene() override;
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;


	GravityForceGenerator* gen;
	GravityForceGenerator* gen2;
};

