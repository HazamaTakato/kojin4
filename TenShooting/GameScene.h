#pragma once
#include"Scene.h"
#include"Background.h"
#include"Player.h"
#include"PlayerShot.h"
#include"Enemy.h"
#include"Collision.h"
#include"EnemyManager.h"
//	ゲーム画面シーン
class GameScene : public Scene
{
public:
	//	初期化
	void Initialize();

	//	更新
	void Update();

	//	解放
	void Release();
private:
	Player player;
	Background background;
	PlayerShot p;
	//PlayerShot playershot;
	//EnemyManager enemy;
	std::list<BulletStar*>shotlist;
	BulletCache shotcache;
	std::list<Enemy*>enemylist;
	EnemyCache enemycache;
	float i;
	int count;
	int c;
	int amari;
	bool f;
	bool f2;
	bool f3;
	Collision col;
	BulletStar shot;
	BulletStar shot2;
	BulletStar shot3;
	BulletStar shot4;
	BulletStar shot5;
	BulletStar shot6; 
	BulletStar shot7;
	BulletStar shot8;
	BulletStar shot9;
	BulletStar shot10;
};