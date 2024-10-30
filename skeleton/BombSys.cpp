#include "BombSys.h"

BombSys::BombSys(physx::PxVec3 _v, physx::PxVec3 _a, physx::PxVec4 _c, physx::PxVec3 _o, int p)
	: ParticleSys(_v, _a, _c, _o, 0, 0), partnum(p)
{
	ParticleSys::setGravity({0,0,0});

}

void BombSys::generateParticle()
{
	// si no ha explotado, explota (cooldown?)
	if (!exploded) {
		int alpha = 1;
		int a = 360 / partnum;

		while (alpha < 360) {
			const Vector3 u = GetCamera()->getTransform().p;// { 0,0,0 };
			const Vector3 p = { u.x + offset.x, u.y + offset.y, u.z + offset.z }; // 

			float randx = 1, randy = 1, randz = 1;
			std::normal_distribution<float> distribution(1.0, 3.0);

			randx *= cos(alpha * pi / 180);
			randy *= sin(alpha * pi / 180);
			randz *= 1;

			alpha += a;

			const Vector3 auxv = { randx * v.x, randy * v.y, randz * v.z };

			Particle* pr = new Particle(p, auxv, g, c);
			particleList.push_back(pr);

		}

		exploded = true;



		// exploded = true;
	}
	else {
		if (count < cooldown) {
			count++;
		}
		else {
			exploded = false;
			count = 0;
		}
	}

}
