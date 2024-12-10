#pragma once

#include "Object.h"


class SolidoRigido : public Object
{

public:
	SolidoRigido();
	SolidoRigido(PxScene* _scene, PxPhysics* _physics, PxTransform ori, Vector3 vel, Vector3 ang_vel, Vector3 size, float density, Vector4 color);
	~SolidoRigido();

	bool update(double t) override;

	void applyForce(Vector3 f);

	void StaticRigidSolid(PxScene* _scene, PxPhysics* _physics, PxTransform ori, Vector3 size, Vector4 color);

	PxRigidDynamic* Dynamic() { if (_solid != nullptr) return _solid; }
	PxRigidStatic* Static() { if (_static != nullptr) return _static; }

	void Color(Vector4 c);

private:
	RenderItem* _item = nullptr;
	PxRigidDynamic* _solid = nullptr;
	PxRigidStatic* _static = nullptr;
	Vector3 _size;

	// ???????????????
	//Vector3 Lvel;
	//Vector3 Wvel;

	int lifetime;

};

