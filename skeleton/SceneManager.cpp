#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager()
{

	current = -1;
}

SceneManager::~SceneManager()
{
	for (auto a : scenes) {
		delete a.scene;
		a.scene = nullptr;
		a.it = 0;
	}
}

void SceneManager::update(float t)
{
	// cambia de escena si es necesario
	if (next != current) {
		// limpia la escena
		if(current != -1)
			scenes[current].scene->hide();

		changeScene(next);

		scenes[current].scene->show();

	}


	// actualiza la escena actual
	scenes[current].scene->update(t);

}

void SceneManager::changeScene(int s)
{
	current = next;
}

void SceneManager::nextScene(int i)
{
	next = i;
}

void SceneManager::addScene(Scene* s)
{
	SceneInfo aux;
	aux.scene = s;
	aux.it = scenes.size();

	//s->hide();

	scenes.push_back(aux);
}

void SceneManager::addSceneInfo(SceneInfo s)
{
	scenes.push_back(s);
}

std::vector<SceneInfo> SceneManager::getScenes()
{
	return scenes;
}

Scene* SceneManager::getScene(int i)
{
	return scenes[i].scene;
}

int SceneManager::Current()
{
	return current;
}

int SceneManager::Next()
{
	return next;
}
