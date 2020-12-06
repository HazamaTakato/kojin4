#pragma once
#include<DxLib.h>
#include<queue>
#include"Vector2D.h"
#include"BulletStar.h"

class BulletCache {
public:
	~BulletCache();
	BulletStar* Instantiate(Vector2D pos, float angle);
	void Cache(BulletStar* bullet);
	void ShowDebugLog();
private:
	std::queue<BulletStar*> _cache;
};
