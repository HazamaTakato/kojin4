#pragma once
#include "Scene.h"
#include <unordered_map>
enum SceneState {
	Initialize,	
	Update,		
	Release		
};

class SceneManager
{
private:
	SceneManager() : _state(SceneState::Initialize),
		_currentScene(nullptr), _nextScene(nullptr) {}
	SceneManager(const SceneManager&) {}
	SceneManager& operator=(const SceneManager&) {}
public:
	~SceneManager();

	static SceneManager& Instance();

	void AddScene(std::string sceneName, Scene* scene);

	void StartScene(std::string sceneName);

	void LoadScene(std::string sceneName);

	void Update();

private:
	void SceneUpdate();

	void NextScene();

private:
	Scene* _currentScene;	
	Scene* _nextScene;		
	SceneState _state;			
	std::unordered_map<std::string, Scene*> _scenes;
};
