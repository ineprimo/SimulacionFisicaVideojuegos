#pragma once
#include "ForceSystem.h"


class GravityForceGenerator :
    public ForceSystem
{

    GravityForceGenerator();
    GravityForceGenerator(Vector3 g);
    ~GravityForceGenerator();


    void updateGravityForce(double t, Particle* p) override;

private:
    Vector3 gravity;


};

