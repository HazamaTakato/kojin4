#include"DxLib.h"
#include <string>
#include "WindowInfo.h"
#include"SceneManager.h"
#include"Title.h"
#include"GameScene.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	ChangeWindowMode(true);
	SetMainWindowText("テンシューティング");
	
	SetGraphMode(WindowInfo::WindowWidth, WindowInfo::WindowHeight, 16);

	if (DxLib_Init() == -1) {
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);
	SetBackgroundColor(0, 0, 0);
	SceneManager::Instance().AddScene("Title", new Title);
	SceneManager::Instance().AddScene("Game", new GameScene);

	SceneManager::Instance().StartScene("Title");

	SceneManager::Instance().Update();
	DxLib_End();
	return 0;
}