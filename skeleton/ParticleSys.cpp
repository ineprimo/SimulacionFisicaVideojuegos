#include "ParticleSys.h"

ParticleSys::ParticleSys()
{

	timeElapsed = 0.0;
	cooldown = 2.0;
}

ParticleSys::~ParticleSys()
{

	for (auto it = particleListToDelete.begin(); it != particleListToDelete.end(); ++it) {

		Particle* p = *it;
		delete p;
		particleListToDelete.pop_front();
	}
	for (auto it = particleList.begin(); it != particleList.end(); ++it) {

		Particle* p = *it;
		delete p;
		particleList.pop_front();
	}
}

void ParticleSys::update(double t)
{
	for (auto it = particleList.begin(); it != particleList.end(); ) {

		Particle* p = *it;
		if (!p->update(t)) {
		//	particleListToDelete.push_back(p);
		//	particleList.erase(it);

		delete p;
		it = particleList.erase(it);
		}
		else
			++it;
	}

	countCooldown();

	//destroyParticles();
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

void ParticleSys::destroyParticles()
{
	for (auto it = particleListToDelete.begin(); it != particleListToDelete.end(); ++it) {

		Particle* p = *it;
		delete p;
	}
	particleListToDelete.clear();
}

void ParticleSys::countCooldown()
{
	if (timeElapsed > cooldown) {

		// genera una particula
		generateParticle();

		// genera otro cooldown aleatorio
		//

		// reinicia el contador
		timeElapsed = 0;
	}
	else
		timeElapsed++;

}
