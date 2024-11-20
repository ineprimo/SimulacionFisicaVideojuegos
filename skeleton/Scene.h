#pragma once

#include <vector>
#include "Particle.h"
#include <iostream>
#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "RenderUtils.hpp"
#include <cmath>

#include "ParticleSys.h"
#include "ForceGen.h"

class Scene
{
public:

	Scene();
	~Scene();

	void Activate(bool a) { active = a; }
	bool Active() { return active; }

	virtual void update(float t);
	virtual void setScene() {} ;
	virtual void keyPressed(unsigned char key, const physx::PxTransform& camera) {};

	void show();
	void hide();

protected:

	// vector de sistemas
	std::vector<ParticleSys*> systems;
	// vector de sistemas
	std::vector<ForceGen*> generators;

private:

	bool active;


};

