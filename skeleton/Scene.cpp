#include "Scene.h"

Scene::Scene()
{
	active = false;
}


Scene::~Scene()
{
}

void Scene::update(float t)
{
	if (!active) return;

	for (auto s : systems) {
		s->update(t);
	}
	
}
