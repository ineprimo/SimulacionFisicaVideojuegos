#include "SolidoRigido.h"

SolidoRigido::SolidoRigido()
{
}

SolidoRigido::SolidoRigido(PxScene* _scene, PxPhysics* _physics, PxTransform ori, Vector3 vel, Vector3 ang_vel, Vector3 size, float density, Vector4 color)
{
	_solid = _physics->createRigidDynamic(ori);
	_solid->setLinearVelocity(vel);
	_solid->setAngularVelocity(ang_vel);

	PxShape* shape = CreateShape(PxBoxGeometry(size));
	_solid->attachShape(*shape);

	PxRigidBodyExt::updateMassAndInertia(*_solid, density);	
	mass = _solid->getMass();

	_scene->addActor(*_solid);

	_item = new RenderItem(shape, _solid, color);


}

SolidoRigido::~SolidoRigido()
{
}

bool SolidoRigido::update(double t)
{
	return false;
}
