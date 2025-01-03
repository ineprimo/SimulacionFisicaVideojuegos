#include "Particle.h"
#include "ForceSystem.h"

Particle::Particle(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_)
	: Object(true, true, p_)
{
	pose = physx::PxTransform(p_);
	vel = v_;
	a = a_;

	maxp = { 500, 500, 500 };
	maxt = 1000;

	setBoundingBox(rad/2, rad/2, rad / 2, rad / 2, rad / 2, rad / 2);


	Object::_item = new RenderItem(CreateShape(physx::PxSphereGeometry(rad)), &pose, c_);

}

Particle::Particle(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_, double d_)
	: Object(true, true, p_)
{
	pose = physx::PxTransform(p_);
	vel = v_;
	a = a_;
	dump = d_;

	maxp = { 500, 500, 500 };
	maxt = 1000;

	setBoundingBox(rad / 2, rad / 2, rad / 2, rad / 2, rad / 2, rad / 2);

	Object::_item = new RenderItem(CreateShape(physx::PxSphereGeometry(rad)), &pose, c_);
}

Particle::Particle(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_, double d_, float r_)
	: Object(true, true, p_)
{

	pose = physx::PxTransform(p_);
	vel = v_;
	a = a_;
	dump = d_;
	rad = r_;

	maxp = { 500, 500, 500 };
	maxt = 1000;
	setBoundingBox(rad / 2, rad / 2, rad / 2, rad / 2, rad / 2, rad / 2);


	Object::_item = new RenderItem(CreateShape(physx::PxSphereGeometry(rad)), &pose, c_);
}

Particle::~Particle()
{
	DeregisterRenderItem(Object::_item);
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
		//f->updateForce(t, this);

		// el mete la fuerza a la particula
		f->updateForce(t, this);
		//forces.push_back(f->force(t, this));

	}

	applyForce();

	return integrate(t);
}

void Particle::applyForce()
{
	// calculamos la fuerza acumulada
	Vector3 totalForc = { 0,0,0 };
	for (auto f : forces) {

		totalForc += f;
	}
	forces.clear();
	// F=m*a -> a = f/m

	a = totalForc / mass;
	//std::cout << "FUERZA TOTAL EN Y  " << totalForc.y << std::endl;
	/*
	std::cout << "fuerzaaaaaaaaaa" << std::endl;
	std::cout << "total a: " << a.x << " " << a.y << " " << a.z << std::endl;
	std::cout << "-------------------" << std::endl;*/



	//std::cout << "total force: " << totalForc.x << " " << totalForc.y << " " << totalForc.z << std::endl;


}

void Particle::addForce(Vector3 f)
{
	forces.push_back(f);
}

void Particle::addForceGen(ForceGen* f)
{
	if(f != nullptr)
		forceGens.push_back(f);
}

void Particle::applyContForce(Vector3 f)
{
	// v = v + f/m
	vel = vel + f * mass;
}

void Particle::applyInstForce(Vector3 f)
{
	a = f * mass;
}

void Particle::setVisibility(bool a)
{
	if (Object::_item != nullptr) {

		if (a)
			RegisterRenderItem(Object::_item);
		else 
			DeregisterRenderItem(Object::_item);
	}
}


