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


	std::normal_distribution<float> rand(3.0, 1.0);
	SolidoRigido* sr;

	for (int i = 0; i < partcant; i++) {

		// AQUI Y FALTA AJUSTA LOS TIPOS DE FORMAAAAAAAAAS

		float randx = rand(generator);
		float randy = rand(generator);
		float randz = rand(generator);

		const Vector3 auxv = { randx, randy, randz};
		const Vector3 auxva = { randx, randy, randz};
		const Vector3 size = { 1, 1, 1};
		PxTransform pos = { 0,0,0 };
		float dens = 1;	// masa calculada con esto
		int typ = 1;
		int mass;

		sr = new SolidoRigido(scene, physics, pos, auxv, auxva, size, dens, { 0,0,1,1 }, typ);
		sr->Dynamic()->setMassSpaceInertiaTensor({0,0,0});
		//sr->Dynamic()->setMass(mass);
		solids.push_back(sr);
		aux.push_back(sr); 
	}

	return aux;
}

void SolidoRigidoSystem::update(double t)
{
	System::update(t);
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
