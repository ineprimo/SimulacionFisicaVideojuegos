#include "SolidoRigido.h"

SolidoRigido::SolidoRigido()
{
	setBoundingBox(0,0,0,0,0,0);

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

	Object::_item = new RenderItem(shape, _solid, color);

	setBoundingBox(size.x/2, size.x/2, size.y/2, size.y/2, size.z/2, size.z/2);


}

SolidoRigido::~SolidoRigido()
{

}

bool SolidoRigido::update(double t)
{
	lifetime -= t;

	if (lifetime <= 0)
		//Active(false);
		;

	//applyForce();

	return Active();
}

void SolidoRigido::applyForce(Vector3 f)
{
}

void SolidoRigido::StaticRigidSolid(PxScene* _scene, PxPhysics* _physics, PxTransform ori, Vector3 size, Vector4 color)
{
	//createCaja(ori.p, tam.x, tam.y, tam.z);
	_static = _physics->createRigidStatic(ori);
	_static->setGlobalPose(ori);
	Transform(ori);
	PxShape* shapeEstatic = CreateShape(PxBoxGeometry(size));
	_static->attachShape(*shapeEstatic);
	_scene->addActor(*_static);

	setBoundingBox(size.x / 2, size.x / 2, size.y / 2, size.y / 2, size.z / 2, size.z / 2);

	Object::Transform(ori);
	Object::Position(ori.p);
	Object::_item = new RenderItem(shapeEstatic, &ori, _static, color);
	//Object::_item->transform = &ori;

}

void SolidoRigido::Color(Vector4 c)
{
	Object::_item->color = c;
}
