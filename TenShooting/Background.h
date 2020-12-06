#pragma once
#include<DxLib.h>
class Background {
public:
	Background();
	void Start();
	void Render();
	void Update();
private:
	int _offsetX;
	const int _width = 800;
	int grp;
};
