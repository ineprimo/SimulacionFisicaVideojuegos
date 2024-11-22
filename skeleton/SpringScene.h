#pragma once
#include "Scene.h"
#include "SpringForceGenerator.h"

class SpringScene : public Scene
{
public:
	SpringScene();
	~SpringScene();

	void update(float t) override;
	void setScene() override;
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;


	SpringForceGenerator* gen;
	

private:


};

