#include<DxLib.h>
#include"Title.h"
#include"GraphFactory.h"
#include"SceneManager.h"
void Title::Initialize() {
	_titleImage = GraphFactory::Instance().LoadGraph("img\\Title.png");
}

void Title::Update() {
	DrawGraph(0, 0, _titleImage, FALSE);
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (key&PAD_INPUT_10) {
		SceneManager::Instance().LoadScene("Game");
	}
}
void Title::Release() {
	GraphFactory::Instance().EraseGraph("img\\Title.png");
}