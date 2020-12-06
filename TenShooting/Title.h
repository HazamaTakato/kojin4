#pragma once
#include"Scene.h"
class  Title:public Scene{
public:
	void Initialize();
	void Update();
	void Release();
private:
	int _titleImage;
};
