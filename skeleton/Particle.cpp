#include "Particle.h"

Particle::Particle(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_)
{
	pose = physx::PxTransform(p_);
	vel = v_;
	a = a_;

	maxp = { 500, 500, 500 };
	maxt = 1000;

	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(rad)), &pose, c_);

}

Particle::Particle(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_, double d_)
{
	pose = physx::PxTransform(p_);
	vel = v_;
	a = a_;
	dump = d_;

	maxp = { 500, 500, 500 };
	maxt = 1000;

	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(rad)), &pose, c_);
}

Particle::Particle(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_, double d_, float r_)
{

	pose = physx::PxTransform(p_);
	vel = v_;
	a = a_;
	dump = d_;
	rad = r_;

	maxp = { 500, 500, 500 };
	maxt = 1000;

	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(rad)), &pose, c_);
}

Particle::~Particle()
{
	DeregisterRenderItem(renderItem);
}

bool Particle::integrate(double t)
{
	pose.p = pose.p + vel;
	vel = vel + t * a;
	vel = vel * pow(dump, t);

	if (t >= maxt) {

		return false;
	}

	// decir cuando/donde muere
	if (pose.p.x >= maxp.x || pose.p.y >= maxp.y || pose.p.z >= maxp.z ||
		pose.p.x <= -maxp.x || pose.p.y <= -maxp.y || pose.p.z <= -maxp.z) {
		return false;
	}

	return true;
}
