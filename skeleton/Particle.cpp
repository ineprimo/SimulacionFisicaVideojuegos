#include "Particle.h"

Particle::Particle(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_)
{
	pose = physx::PxTransform(p_);
	vel = v_;
	a = a_;

	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(rad)), &pose, c_);

}

Particle::Particle(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_, double d_)
{
	pose = physx::PxTransform(p_);
	vel = v_;
	a = a_;
	dump = d_;

	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(rad)), &pose, c_);
}

Particle::Particle(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_, double d_, float r_)
{

	pose = physx::PxTransform(p_);
	vel = v_;
	a = a_;
	dump = d_;
	rad = r_;

	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(rad)), &pose, c_);
}

Particle::~Particle()
{
	DeregisterRenderItem(renderItem);
}

void Particle::integrate(double t)
{
	pose.p = pose.p + vel;
	vel = vel + t * a;
	vel = vel * pow(dump, t);

	// decir cuando/donde muere
}
