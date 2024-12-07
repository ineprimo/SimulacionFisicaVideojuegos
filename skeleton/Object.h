#pragma once
#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "RenderUtils.hpp"

using namespace physx;


class Object
{

private:

	Vector3 position;
	PxTransform transform;
	bool active, visible;


protected:

	float mass = 1;

public:

	Object() {};
	Object(bool v, bool a, Vector3 p);
	~Object() {};

	virtual bool update(double t);

	

	// mira si este objeto y el dado colisionan
	bool collides(Object* o);

	// visible
	virtual void setVisibility(bool a) { visible = a; }

	// set active
	void Active(bool a) { active = a; }
	// is active
	bool Active() { return active; }

	// set position
	void Position(Vector3 p) { position = p; }
	// return position
	Vector3 Position() { return position; }

	// set position
	void Transform(PxTransform p) { transform = p; }
	// return position
	PxTransform Transform() { return transform; }

	// orientation????
	//

	//
};
