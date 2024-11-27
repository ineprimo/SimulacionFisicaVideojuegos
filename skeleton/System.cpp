#include "System.h"

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
