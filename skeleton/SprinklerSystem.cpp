#include "SprinklerSystem.h"


SprinklerSystem::SprinklerSystem(Vector3 _v, Vector3 _a, Vector4 _c, Vector3 o_, int _med, int _var, int pnum, int cd, int angles) 
: ParticleSys(_v, _a, _c, o_, _med, _var), particlenum(pnum), cooldown(cd), anglesum(angles) {

}

SprinklerSystem::~SprinklerSystem()
{
}

std::vector<Particle*> SprinklerSystem::generateParticle()
{
	Particle* pr;
	std::vector<Particle*> aux;
	if (counter >= cooldown) {

		if (particlecount <= particlenum) {
			const Vector3 u = { 0,0,0 }; //GetCamera()->getTransform().p;// { 0,0,0 };
			const Vector3 p = { u.x + offset.x, u.y + offset.y, u.z + offset.z }; // 

			float randx, randy, randz;
			std::normal_distribution<float> distribution(1.0, 2.0);
			randx = 1; //distribution(generator);
			randy = 1;//distribution(generator);
			randz = 1;//distribution(generator);

			randx *= cos(alpha * pi / 180);
			//randy *= cos(beta*pi/180);
			randz *= sin(delta * pi / 180);

			alpha += anglesum;
			beta += anglesum;
			delta += anglesum;

			const Vector3 auxv = { randx * v.x, randy * v.y, randz * v.z };

			pr = new Particle(p, auxv, {0,0,0}, c);
			pr->setType(0);
			pr->setMass(mass);
			particles.push_back(pr);

			aux.push_back(pr);
			particlecount++;
		}
		else {
			counter = 0;
			particlecount = 0;
			return aux;

		}
	}
	else {

		counter++;
		return aux;
	}

	return aux;
}

void SprinklerSystem::setCD(int c)
{
	cooldown = c;
}

void SprinklerSystem::setPartNum(int p)
{
	particlenum = p;
}
