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

	struct BoundingBox {	//Pongo las 3 coordenadas aunque mi idea es que sea un mundo "2D"
		float minX, maxX;
		float minY, maxY;
		float minZ, maxZ;
	};

protected:

	BoundingBox bb;

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

	// BOUNDING BOX
	void setBoundingBox(float minX_, float maxX_,
						float minY_, float maxY_,
						float minZ_, float maxZ_)
	{
		bb.maxX = maxX_;
		bb.minX = minX_;
		bb.maxY = maxY_;
		bb.minY = minY_;
		bb.maxZ = maxZ_;
		bb.minZ = minZ_;
	};

	BoundingBox BB() { return bb; }

	bool isInside(Object* b);
};
