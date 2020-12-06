#pragma once
#include<list>
#include"Vector2D.h"
#include"BulletStar.h"
#include"WindowInfo.h"
#include"BulletCache.h"
#include"GameObject.h"
#include"Collision.h"
#include<DxLib.h>
#include"Enemy.h"
#include"EnemyCache.h"
class PlayerShot{
public:
	//~PlayerShot() override;
	void Shot(const Vector2D& pos, float angle);
	void Update();
	void Render();
	void Start();
	void Release();
	//Vector2D Position() {
		//return _position;
	//}
public:
	//Vector2D _position;				//	ç¿ïW
	std::list<BulletStar*>_shotList;
	BulletCache _cache;
	EnemyCache _eCache;
	//Collision collision;
};