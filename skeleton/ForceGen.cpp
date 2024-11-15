#include "ForceGen.h"
#include "Particle.h"

ForceGen::ForceGen()
{
}

void ForceGen::updateForce(double t, Particle* p)
{
}

Vector3 ForceGen::force(Particle* P)
{
	//std::cout << "vamos no me jodas" << std::endl;
	return Vector3();
}

bool ForceGen::enterZone(Particle* p)
{
	// si esta dentro de la zona
	if (isInside(p->getPosition())) {
		//particleList.push_back(p);

		return true;
	}
	return false;
}

void ForceGen::exitZone(Particle* p)
{
	//particleList.remove(p);

}

void ForceGen::applyForce()
{
	/*for (auto p : particleList) {

		float m = p->getMass();
		Vector3 a = { force.x / m, force.y / m, force.z / m };

		p->setAcceleration(a);
	}*/
}

bool ForceGen::isInside(Vector3 pos)
{
	/*return { pos.x - radio > 0 &&
			pos.y - radio > 0 &&
			pos.z - radio > 0 };*/
	return true;
}
