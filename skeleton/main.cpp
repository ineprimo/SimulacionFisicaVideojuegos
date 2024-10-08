#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"
#include "Particle.h"
#include "Projectile.h"
#include <vector>
#include <list>

#include <iostream>

std::string display_text = "This is a test";


using namespace physx;

PxDefaultAllocator		gAllocator;
PxDefaultErrorCallback	gErrorCallback;

PxFoundation*			gFoundation = NULL;
PxPhysics*				gPhysics	= NULL;


PxMaterial*				gMaterial	= NULL;

PxPvd*                  gPvd        = NULL;

PxDefaultCpuDispatcher*	gDispatcher = NULL;
PxScene*				gScene      = NULL;
ContactReportCallback gContactReportCallback;

//transform fuera porque es un puntero <3
RenderItem* xrenderItem = NULL;
RenderItem* yrenderItem = NULL;
RenderItem* zrenderItem = NULL;
RenderItem* orenderItem = NULL;

PxTransform xTransform(10.0, 0.0, 0.0);
PxTransform yTransform(0.0, 10.0, 0.0);
PxTransform zTransform(0.0, 0.0, 10.0);
PxTransform oTransform(0.0, 0.0, 0.0);



// ------------

Particle* particle;
std::vector<Projectile*> projectileList;


// ------------


// Initialize physics engine
void initPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	gFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, gAllocator, gErrorCallback);

	gPvd = PxCreatePvd(*gFoundation);
	PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate(PVD_HOST, 5425, 10);
	gPvd->connect(*transport,PxPvdInstrumentationFlag::eALL);

	gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(),true,gPvd);

	gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);

	// For Solid Rigids +++++++++++++++++++++++++++++++++++++
	PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
	sceneDesc.gravity = PxVec3(0.0f, -9.8f, 0.0f);
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = contactReportFilterShader;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	gScene = gPhysics->createScene(sceneDesc);
	

	// crear esfera
	xrenderItem = new RenderItem(CreateShape(PxSphereGeometry(1)), &xTransform, {1.0, 0.7, 0.8, 1.0});
	yrenderItem = new RenderItem(CreateShape(PxSphereGeometry(1)), &yTransform, {0.0, 1.0, 0.9, 1.0});
	zrenderItem = new RenderItem(CreateShape(PxSphereGeometry(1)), &zTransform, {0.0, 0.0, 0.9, 1.0});
	orenderItem = new RenderItem(CreateShape(PxSphereGeometry(1)), &oTransform, {0.0, 0.0, 0.0, 1.0});


	// ------------------

	Vector3 p = {0,0,0};
	Vector3 v = {0,2,0};
	Vector3 a = {0,2,0};
	Vector4 c = { 0.0, 1.0, 0.9, 1.0 };

	particle = new Particle(p, v, a, c);


	// ------------------

}


// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);


	gScene->simulate(t);
	gScene->fetchResults(true);


	particle->integrate(t);
	for (int i = 0; i < projectileList.size(); i++) {
		projectileList[i]->integrate(t);
	}

}

// Function to clean data
// Add custom code to the begining of the function
void cleanupPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	//
	DeregisterRenderItem(xrenderItem);
	DeregisterRenderItem(yrenderItem);
	DeregisterRenderItem(zrenderItem);
	DeregisterRenderItem(orenderItem);


	//  �?�?�?�?�?�?�?�?�?�?�?�?�?�?�?�?�?�?
	delete particle;
	for (int i = 0; i < projectileList.size(); i++) {
		delete projectileList[i];
	}

	// Rigid Body ++++++++++++++++++++++++++++++++++++++++++
	gScene->release();
	gDispatcher->release();
	// -----------------------------------------------------
	gPhysics->release();	
	PxPvdTransport* transport = gPvd->getTransport();
	gPvd->release();
	transport->release();
	
	gFoundation->release();
	}

// Function called when a key is pressed
void keyPress(unsigned char key, const PxTransform& camera)
{
	PX_UNUSED(camera);

	switch(toupper(key))
	{
	//case 'B': break;
	//case ' ':	break;
	case 'P':
	{
		{
			Vector3 p = camera.p;// { 0,0,0 };
			Vector3 v = { 0,2,0 };
			Vector3 a = { 0,-9.8,0 };
			Vector4 c = { 0.0, 1.0, 0.9, 1.0 };

			Projectile* pr = new Projectile(p, v, a, c);
			projectileList.push_back(pr);
		}

		break;
	}
	case ' ':
	{
		break;
	}
	default:
		break;
	}
}

void onCollision(physx::PxActor* actor1, physx::PxActor* actor2)
{
	PX_UNUSED(actor1);
	PX_UNUSED(actor2);
}


int main(int, const char*const*)
{
#ifndef OFFLINE_EXECUTION 
	extern void renderLoop();
	renderLoop();
#else
	static const PxU32 frameCount = 100;
	initPhysics(false);
	for(PxU32 i=0; i<frameCount; i++)
		stepPhysics(false);
	cleanupPhysics(false);
#endif

	return 0;
}