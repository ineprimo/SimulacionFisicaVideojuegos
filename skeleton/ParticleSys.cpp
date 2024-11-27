#include "ParticleSys.h"
#include "ForceSystem.h"
#include "GravityForceGenerator.h"

ParticleSys::ParticleSys(Vector3 _v, Vector3 _a, Vector4 _c, Vector3 o_, int _var, int _med) 
	: v(_v), a(_a), c(_c), offset(o_), var(_var), med(_med), System()
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

	const Vector3 u = { 0,0,0 };
	std::normal_distribution<double> posrand(offset.x, 50.0); // media dispersion
	int varx = posrand(generator);
	int vary = posrand(generator);
	int varz = posrand(generator);

	const Vector3 p = {u.x + offset.x + varx, u.y + offset.y + vary, u.z + offset.z + varz }; // 

	float randx, randy, randz;
	std::normal_distribution<float> distribution(10.0, 1.0);
	std::normal_distribution<float> veldy(5.0, 2.0);
	std::normal_distribution<float> veldz(10.0, 2.0);
	std::normal_distribution<float> veldx(-10.0, 2.0);

	// con 
	randx = veldx(generator);
	randy = veldy(generator);
	randz = veldz(generator);


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
		std::uniform_int_distribution<int> numPartsUniform(0, 5); // numero de 0 a restParticles
		int part = numPartsUniform(generator);

		for (int i = 0; i < part; i++) {
			// genera una particula
			addParticle();

		}

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
	if (gfGen != nullptr) {
		pr->addForceGen(gfGen);
	}
	if (wGen != nullptr)
		pr->addForceGen(wGen);
	if (tGen != nullptr) {
		pr->addForceGen(tGen);
	}
	if (eGen != nullptr) {
		pr->addForceGen(eGen);
	}
	if (sGen != nullptr) {
		pr->addForceGen(sGen);
	}
}

void ParticleSys::hide()
{
	for (auto p : particleList) {
		if(p != nullptr)
			p->setVisibility(false);
	}
}

void ParticleSys::show()
{
	for (auto p : particleList) {
		p->setVisibility(true);
	}
}
