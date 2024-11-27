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

void Scene::show()
{
	for (auto o : objects) {
		o->setVisibility(true);
	}
	for (auto s : systems) {
		s->show();
	}
	for (auto g : generators) {
		g->Activate(true);
	}
}

void Scene::hide()
{

	std::cout << "ou";
	for (auto o : objects) {
		o->setVisibility(false);
	}
	for (auto s : systems) {
		s->hide();
	}
	for (auto g : generators) {
		g->Activate(false);
	}


}
