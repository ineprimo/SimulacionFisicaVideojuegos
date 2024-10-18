#include "ParticleSys.h"

ParticleSys::ParticleSys()
{
}

ParticleSys::~ParticleSys()
{
}

void ParticleSys::update(double t)
{
	for (auto it = particleList.begin(); it != particleList.end(); ) {

		Particle* p = *it;
		if (!p->update(t)) {
			particleListToDelete.push_back(p);
			particleList.remove(p);
		}
		else
			++it;
	}
}

void ParticleSys::generateParticle()
{
	const Vector3 p = GetCamera()->getTransform().p;// { 0,0,0 };
	const Vector3 v = GetCamera()->getDir() * 20;
	const Vector3 a = { 0,-9.8,0 };
	const Vector4 c = { 0.0, 1.0, 0.9, 1.0 };

	Particle* pr = new Particle(p, v, a, c);
	particleList.push_back(pr);

}

void ParticleSys::destroyParticle()
{
	for (auto it = particleListToDelete.begin(); it != particleListToDelete.end(); ++it) {

		Particle* p = *it;
		delete p;
		particleListToDelete.pop_front();
	}

}