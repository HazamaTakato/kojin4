#pragma once
#include<list>
#include"Vector2D.h"
#include"Enemy.h"
#include"WindowInfo.h"
#include"EnemyCache.h"
#include"GameObject.h"
#include"BulletStar.h"
#include<DxLib.h>
class EnemyManager {
public:
	//~EnemyManager();
	void Spawn(const Vector2D& pos,float angle);
	void Update();
	void Render();
	void Start();
	void Release();
public:
	std::list<Enemy*>enemyList;
	BulletStar b;
	EnemyCache cache;
};
