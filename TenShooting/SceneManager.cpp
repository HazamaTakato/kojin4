#include <DxLib.h>
#include <memory>
#include "SceneManager.h"

SceneManager::~SceneManager()
{
	for (auto scene : _scenes) {
		delete scene.second;
	}
}

SceneManager & SceneManager::Instance()
{
	static std::unique_ptr<SceneManager> instance(new SceneManager);

	return *instance;
}

void SceneManager::AddScene(std::string sceneName, Scene* scene)
{
	if (_scenes.count(sceneName))
		return;
	_scenes[sceneName] = scene;
}

void SceneManager::StartScene(std::string sceneName) {

	if (!_scenes.count(sceneName))
		return;

	_currentScene = _scenes[sceneName];
}

void SceneManager::LoadScene(std::string sceneName)
{
	if (!_scenes.count(sceneName))
		return;

	_nextScene = _scenes[sceneName];
	_state = SceneState::Release;
}

void SceneManager::Update()
{
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();

		SceneUpdate();

		ScreenFlip();
	}
}

void SceneManager::SceneUpdate()
{
	if (!_currentScene)
		return;
	if (_state == SceneState::Initialize) {
		_currentScene->Initialize();
		_state = SceneState::Update;
	}

	_currentScene->Update();

	if (_state == SceneState::Release) {
		_currentScene->Release();
		NextScene();
		_state = SceneState::Initialize;
	}
}

void SceneManager::NextScene()
{
	_currentScene = _nextScene;
}
