#pragma once



#include <vector>
#include "Particle.h"
#include <iostream>
#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "RenderUtils.hpp"
#include <cmath>

class Scene;


struct SceneInfo {
	Scene* scene;
	int it;
};

class SceneManager
{

public:
	SceneManager();
	~SceneManager();


	// ----------
	void update(float t);
	void changeScene(int s);


	void nextScene(int i);
	void addScene(Scene* s);
	void addSceneInfo(SceneInfo s);
	std::vector<SceneInfo> getScenes();
	Scene* getScene(int i);
	int Current();
	int Next();





private:

	std::vector<SceneInfo> scenes;

	int current;
	int next;


};

