#pragma once
#include<DxLib.h>
#include<queue>
#include"Vector2D.h"
#include"Enemy.h"

class EnemyCache {
public:
	~EnemyCache();
	Enemy* Instantiate(Vector2D pos,float angle);
	void Cache(Enemy* enemy);
private:
	std::queue<Enemy*>_cache;
};