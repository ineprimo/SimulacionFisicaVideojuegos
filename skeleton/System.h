#pragma once
#include "Particle.h"
#include <list>
#include "SolidoRigido.h"


class System
{
public:
	System() {};
	~System() {};

	virtual void update(double t);


	void hide();
	void show();

	void addParticle(Particle* p);

	void addForceGenerator(ForceGen* f, Particle* p);
	void addForceGeneratorToAll(ForceGen* f);

	std::list<Particle*> getParticles() { return particles; }

	void Active(bool a) { active = a; };
	bool Active() {
		return active;
	};


protected:


	bool active;
	std::list<Particle*> particles;
	std::list<SolidoRigido*> solids;

};

