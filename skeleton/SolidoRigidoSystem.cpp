#include "SolidoRigidoSystem.h"
#include "SolidoRigido.h"

SolidoRigidoSystem::SolidoRigidoSystem(PxScene* _scene, PxPhysics* _physics, PxTransform pos)
	: scene(_scene), physics(_physics), position(pos)
{
}

SolidoRigidoSystem::~SolidoRigidoSystem()
{
}

std::vector<SolidoRigido*> SolidoRigidoSystem::generateSolids()
{
	// settea randoms
	std::vector<SolidoRigido*> aux;

	const Vector3 u = { 0,0,0 };
	const Vector3 p = { u.x + position.p.x,
						u.y + position.p.y,
						u.z + position.p.z }; // 


	std::normal_distribution<float> rand(1.0, 1.0);
	std::uniform_int_distribution<> distr(1, 10); 
	std::uniform_int_distribution<> distr2(-100, 100); 
	std::uniform_int_distribution<> inertia(0, 5); 
	SolidoRigido* sr;

	for (int i = 0; i < partcant; i++) {

		// AQUI Y FALTA AJUSTA LOS TIPOS DE FORMAAAAAAAAAS

		float randx = rand(generator);
		float randy = rand(generator);
		float randz = rand(generator);

		float randxs = distr(generator);
		float randys = distr(generator);
		float randzs = distr(generator);

		float randposx = distr2(generator);


		float inertiax = inertia(generator);

		const Vector3 auxv = { 0, 0, 0};
		const Vector3 auxva = { 0, 0, 0};
		const Vector3 size = { randxs, randys, randzs };
		int typ = std::rand() % 2;	// random entre 0 y 1
		
		int dens = std::rand() % 11;// random entre 0 y 11
		if (dens == 0) dens = 1;

		PxTransform pos = { randposx, position.p.y + i ,position.p.z + i };

		sr = new SolidoRigido(scene, physics, pos, {0,0,0}, auxva, size, dens, {0,0,1,1}, typ);
		sr->Dynamic()->setMassSpaceInertiaTensor({inertiax,0,0});
		//sr->Dynamic()->setMass(mass);
		solids.push_back(sr);
		aux.push_back(sr); 
	}

	return aux;
}

void SolidoRigidoSystem::update(double t)
{
	//System::update(t);
	wait();
}

void SolidoRigidoSystem::addSolid()
{
	std::vector<SolidoRigido*> p = generateSolids();
	for (auto pr : p) {
		if (pr == nullptr) return;
		if (gfGen != nullptr) {
			pr->AddForceGen(gfGen);
		}
		if (wGen != nullptr)
			pr->AddForceGen(wGen);
		if (tGen != nullptr) {
			pr->AddForceGen(tGen);
		}
		if (eGen != nullptr) {
			pr->AddForceGen(eGen);
		}
		if (sGen != nullptr) {
			pr->AddForceGen(sGen);
		}
	}
}

void SolidoRigidoSystem::wait()
{
	if (!active) return;

	if (timeElapsed > cooldown) {
		std::uniform_int_distribution<int> numPartsUniform(0, 5); // numero de 0 a restParticles
		int part = numPartsUniform(generator);

		for (int i = 0; i < part; i++) {
			// genera una particula
			addSolid();
		}

		// genera otro cooldown aleatorio
		//

		// reinicia el contador
		timeElapsed = 0;
	}
	else
		timeElapsed++;


}
