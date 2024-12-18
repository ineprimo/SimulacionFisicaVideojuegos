#include "System.h"

void System::update(double t)
{
	auto it = particles.begin();
	for (it; it != particles.end(); ) {

		Particle* p = *it;
		if (!p->update(t)) {

			delete p;
			it = particles.erase(it);
		}
		else
			++it;
	}

	auto its = solids.begin();
	for (its; its != solids.end(); ) {

		SolidoRigido* s = *its;
		if (!s->update(t)) {

			delete s;
			its = solids.erase(its);
		}
		else
			++its;
	}


}

void System::hide()
{
	for (auto p : particles) {
		if (p != nullptr)
			p->setVisibility(false);
	}
}

void System::show()
{
	for (auto p : particles) {
		if (p != nullptr)
			p->setVisibility(true);
	}
}

void System::addParticle(Particle* p)
{
	particles.push_back(p);
}

void System::addForceGenerator(ForceGen* f, Particle* p)
{
	p->addForceGen(f);
}

void System::addForceGeneratorToAll(ForceGen* f)
{
	for (auto p : particles) {
		p->addForceGen(f);
	}
}

