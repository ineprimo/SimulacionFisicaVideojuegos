#include "SolidoRigido.h"
#include "ForceGen.h"

SolidoRigido::SolidoRigido()
{
}

SolidoRigido::SolidoRigido(PxScene* _scene, PxPhysics* _physics, PxTransform ori, Vector3 vel, Vector3 ang_vel, Vector3 size, float density, Vector4 color, int type)
	: Object()
{
	_solid = _physics->createRigidDynamic(ori);
	_solid->setLinearVelocity(vel);
	_solid->setAngularVelocity(ang_vel);
	PxShape* shape;

	switch (type)
	{
	case 0:
		shape = CreateShape(PxBoxGeometry(size));
		_solid->attachShape(*shape);

		break;
	case 1: 
		shape = CreateShape(PxSphereGeometry(size.x));
		_solid->attachShape(*shape);

		break;
	default:
		shape = CreateShape(PxBoxGeometry(size));
		_solid->attachShape(*shape);
		break;
	}

	PxRigidBodyExt::updateMassAndInertia(*_solid, density);	
	mass = _solid->getMass();

	_scene->addActor(*_solid);

	setBoundingBox(size.x / 2, size.x / 2, size.y / 2, size.y / 2, size.z / 2, size.z / 2);


	Object::_item = new RenderItem(shape, _solid, color);

}

SolidoRigido::~SolidoRigido()
{

}

bool SolidoRigido::update(double t)
{
	lifetime -= t;

	if (lifetime <= 0)
		Active(false);
		;

	//applyForce();

	return Active();
}

void SolidoRigido::applyForce(Vector3 f)
{

}

void SolidoRigido::AddForceGen(ForceGen* f)
{
	if (f != nullptr)
		forceGens.push_back(f);
}


void SolidoRigido::StaticRigidSolid(PxScene* _scene, PxPhysics* _physics, PxTransform ori, Vector3 size, Vector4 color, int type)
{
	//createCaja(ori.p, tam.x, tam.y, tam.z);
	_static = _physics->createRigidStatic(ori);
	_static->setGlobalPose(ori);
	Transform(ori);
	PxShape* shapeEstatic;
	switch (type)
	{
	case 1:
		shapeEstatic = CreateShape(PxBoxGeometry(size));
		_static->attachShape(*shapeEstatic);
		break;
	case 2:
		shapeEstatic = CreateShape(PxSphereGeometry(size.x));
		_static->attachShape(*shapeEstatic);
		break;
	default:
		shapeEstatic = CreateShape(PxBoxGeometry(size));
		_static->attachShape(*shapeEstatic);
		break;
	}

	_scene->addActor(*_static);

	Transform(ori);
	Position(ori.p);

	setBoundingBox(size.x / 2, size.x / 2, size.y / 2, size.y / 2, size.z / 2, size.z / 2);


	_item = new RenderItem(shapeEstatic, _static, color);

}

void SolidoRigido::Color(Vector4 c)
{
	_item->color = c;
}
