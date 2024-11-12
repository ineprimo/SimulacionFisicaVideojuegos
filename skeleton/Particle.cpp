#include "Particle.h"
#include "ForceSystem.h"

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

	// euler 
	//pose.p = pose.p + vel;
	//vel = vel + t * a;
	//vel = vel * pow(dump, t);

	// semi implicito
	vel = vel + t * a;
	pose.p = pose.p + vel * t;
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

bool Particle::update(double t)
{
	for (auto f : forceGens) {
		// actualiza
		f->updateGravityForce(t, this);
	}


	return integrate(t);
}

void Particle::addForceGen(ForceSystem* f)
{
	forceGens.push_back(f);
}

void Particle::applyContForce(Vector3 f)
{
	// v = v + f/m
	vel = vel + f * mass;
}

void Particle::applyInstForce(Vector3 f)
{
	a = a + f / mass;
}


