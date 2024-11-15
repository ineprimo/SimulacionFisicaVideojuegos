#pragma once
//#include "ForceSystem.h"
#include "ForceGen.h"

class GravityForceGenerator : public ForceGen
{
public:
    GravityForceGenerator();
    GravityForceGenerator(Vector3 g);
    ~GravityForceGenerator();


    void updateForce(double t, Particle* p) override;
    Vector3 force(double t, Particle* p) override;


private:
    Vector3 gravity;


};

