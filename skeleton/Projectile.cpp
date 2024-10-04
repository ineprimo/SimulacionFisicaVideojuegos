#include "Projectile.h"


Projectile::Projectile(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_) : Particle(p_, v_, a_, c_ )
{
}

Projectile::Projectile(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_, double d_) : Particle(p_, v_, a_, c_, d_)
{
}

Projectile::Projectile(Vector3 p_, Vector3 v_, Vector3 a_, Vector4 c_, double d_, float r_) : Particle(p_, v_, a_, c_, d_, r_)
{
}

Projectile::~Projectile()
{

}
