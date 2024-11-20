#pragma once
#include "Scene.h"

class ExplosionScene : public Scene
{

public:
	ExplosionScene();
	~ExplosionScene();


private:

	void update(float t) override;
	void setScene() override;
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;

};

