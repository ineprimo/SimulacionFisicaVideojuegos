#pragma once
//#include "ForceSystem.h"
#include "ForceGen.h"

class GravityForceGenerator : public ForceGen
{
public:
    GravityForceGenerator();
    GravityForceGenerator(Vector3 g);
    ~GravityForceGenerator();


    void updateGravityForce(double t, Particle* p) override;

private:
    Vector3 gravity;


};

