#include"Background.h"
#include"GraphFactory.h"
Background::Background() {

}

void Background::Start() {
	grp = GraphFactory::Instance().LoadGraph("img\\background.png");
	_offsetX = 0;
}

void Background::Render() {
	DrawGraph(_offsetX, 0, grp, FALSE);
	DrawGraph(800 + _offsetX, 0, grp, FALSE);
}

void Background::Update() {
	_offsetX -= 10;
	if (_offsetX <= -_width)
		_offsetX = _offsetX + _width;
}
