#pragma once

#include "Object.h"


class SolidoRigido : public Object
{


public:
	SolidoRigido();
	SolidoRigido(PxScene* _scene, PxPhysics* _physics, PxTransform ori, Vector3 vel);
	~SolidoRigido();

	//bool update(float t) override;



private:

	int lifetime;

};

