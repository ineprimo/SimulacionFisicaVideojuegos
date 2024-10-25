#include "SprinklerSystem.h"


SprinklerSystem::SprinklerSystem(Vector3 _v, Vector3 _a, Vector4 _c, Vector3 o_, int _med, int _var) 
: ParticleSys(_v, _a, _c, o_, _med, _var) {

}

SprinklerSystem::~SprinklerSystem()
{
}

void SprinklerSystem::generateParticle()
{
	const Vector3 u = GetCamera()->getTransform().p;// { 0,0,0 };
	const Vector3 p = { u.x + offset.x, u.y + offset.y, u.z + offset.z }; // 

	float randx, randy, randz;
	std::normal_distribution<float> distribution(1.0, 3.0);
	randx = 1;//distribution(generator);
	randy = 1;// distribution(generator);
	randz = 1;//distribution(generator);

	randx *= cos(alpha*pi/180);
	randy *= cos(beta*pi/180);
	randz *= sin(delta * pi / 180);

	alpha += 10;
	beta += 10;
	delta += 10;

	const Vector3 auxv = { randx * v.x, randy * v.y, randz * v.z };

	Particle* pr = new Particle(p, auxv, g, c);
	particleList.push_back(pr);
}
