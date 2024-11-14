#include "ParticleSys.h"
#include "ForceSystem.h"
#include "GravityForceGenerator.h"

ParticleSys::ParticleSys(Vector3 _v, Vector3 _a, Vector4 _c, Vector3 o_, int _var, int _med) 
	: v(_v), a(_a), c(_c), offset(o_), var(_var), med(_med)
{
	mass = 1;
	timeElapsed = 0.0;
	cooldown = 10.0;

	g = {0, -9.8, 0};


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

			delete p;
			it = particleList.erase(it);
		}
		else
			++it;
	}

	countCooldown();

	//destroyParticles();
}

Particle* ParticleSys::generateParticle()
{
	const Vector3 u = GetCamera()->getTransform().p;// { 0,0,0 };
	const Vector3 p = {u.x + offset.x, u.y + offset.y, u.z + offset.z}; // 

	float randx, randy, randz;
	std::normal_distribution<float> distribution(1.0, 3.0);

	// con 
	randx = 1;// distribution(generator);
	randy = distribution(generator);
	randz = 1;//distribution(generator);


	////std::cout
	//const Vector3 v = { randx, 10, randz};//GetCamera()->getDir() * 20;
	//const Vector3 a = { 0,1,0 };				// aceleracion
	//const Vector4 c = { 0.0, 1.0, 0.9, 1.0 };	// color

	const Vector3 auxv = { randx * v.x, randy * v.y, randz * v.z };

	Particle* pr = new Particle(p, auxv, g, c);	
	pr->setMass(mass);
	particleList.push_back(pr);

	return pr;

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
		addParticle();

		// genera otro cooldown aleatorio
		//

		// reinicia el contador
		timeElapsed = 0;
	}
	else
		timeElapsed++;

}

void ParticleSys::addParticle()
{
	Particle* pr = generateParticle();
	pr->addForceGen(gfGen);
}
