#pragma once
#include "Scene.h"
class TornadoScene : public Scene
{


public:
	TornadoScene();
	~TornadoScene();


private:

	void update(float t) override;
	void setScene() override;
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;


	TornadoGenerator* gen;
};

