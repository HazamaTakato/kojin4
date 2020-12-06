#include"GameScene.h"
#include "GraphFactory.h"
#include "WindowInfo.h"
#include<random>
#include"DxLib.h"
#include"SceneManager.h"
#include"DxLib.h"
#include"PlayerShot.h"

void GameScene::Initialize() {
	background.Start();
	player.Start();
	p.Start();
	f = false;
	count = 0;	
	c = 0;
	i = -50;
	std::random_device rand;
	for (int i = 0; i < 11; i++) {
		Enemy* enemy = enemycache.Instantiate(Vector2D(rand()%WindowInfo::WindowWidth, rand() % WindowInfo::WindowHeight), 0);
		enemy->Start(Vector2D(rand() % WindowInfo::WindowWidth,rand() % WindowInfo::WindowHeight), 0);
		enemylist.push_back(enemy);
	}
	//shot.Start(Vector2D(player.Position().x + 16, player.Position().y), 0);
}

void GameScene::Update() {
	background.Update();
	player.Update();
	p.Update();
	shot.Update();
	shot2.Update();
	shot3.Update();
	shot4.Update();
	shot5.Update();
	shot6.Update();
	shot7.Update();
	shot8.Update();
	shot9.Update();
	shot10.Update();
	if (player.OnShotButton() == 1&&!f) {
			p.Shot(Vector2D(player.Position().x + 16, player.Position().y), 2.5);
			p.Shot(Vector2D(player.Position().x + 16, player.Position().y), -2.5);
			p.Shot(Vector2D(player.Position().x + 16, player.Position().y), 10);
			p.Shot(Vector2D(player.Position().x + 16, player.Position().y), -10);
			p.Shot(Vector2D(player.Position().x + 16, player.Position().y), -20);
			p.Shot(Vector2D(player.Position().x + 16, player.Position().y), 20);
			p.Shot(Vector2D(player.Position().x + 16, player.Position().y), -30);
			p.Shot(Vector2D(player.Position().x + 16, player.Position().y), 30);
			p.Shot(Vector2D(player.Position().x + 16, player.Position().y), -40);
			p.Shot(Vector2D(player.Position().x + 16, player.Position().y), -40);
			shot.Start(Vector2D(player.Position().x + 16, player.Position().y), 2.5);
			shot2.Start(Vector2D(player.Position().x + 16, player.Position().y), -2.5);
			shot3.Start(Vector2D(player.Position().x + 16, player.Position().y), 10);
			shot4.Start(Vector2D(player.Position().x + 16, player.Position().y), -10);
			shot5.Start(Vector2D(player.Position().x + 16, player.Position().y), -20);
			shot6.Start(Vector2D(player.Position().x + 16, player.Position().y), 20);
			shot7.Start(Vector2D(player.Position().x + 16, player.Position().y), -30);
			shot8.Start(Vector2D(player.Position().x + 16, player.Position().y), 30);
			shot9.Start(Vector2D(player.Position().x + 16, player.Position().y), -40);
			shot10.Start(Vector2D(player.Position().x + 16, player.Position().y), -40);
			//shot.Update();
			//i = i + 10;
			//BulletStar* shot = shotcache.Instantiate(Vector2D(player.Position().x + 16, player.Position().y), 0);
			//shotlist.push_back(shot);
			//Enemy* enemy = enemycache.Instantiate(Vector2D(player.Position().x + 400, player.Position().y), 0);
			f = true;
		//enemylist.push_back(enemy);
	}
	if (shot.Position().x > WindowInfo::WindowWidth ||
		shot.Position().x<-shot.Size().x ||
		shot.Position().y > WindowInfo::WindowHeight ||
		shot.Position().y < -shot.Size().y)
	{
		f = false;
	}
	//for (auto it = shotlist.begin(); it != shotlist.end();) {
		for (auto enit = enemylist.begin(); enit != enemylist.end();) {
			//(*it)->Update();
			(*enit)->Update();
			if (//(*it)->Position().x > WindowInfo::WindowWidth ||
				//(*it)->Position().x < -(*it)->Size().x ||
				//(*it)->Position().y > WindowInfo::WindowHeight ||
				//(*it)->Position().y < -(*it)->Size().y ||
				(*enit)->Position().x > WindowInfo::WindowWidth ||
				(*enit)->Position().x < -(*enit)->Size().x ||
				(*enit)->Position().y > WindowInfo::WindowHeight ||
				(*enit)->Position().y < -(*enit)->Size().y ||
				col.CircleCollision2(shot.Position(), 12, (*enit)->Position(), 12)||
				col.CircleCollision2(shot2.Position(), 12, (*enit)->Position(), 12)||
				col.CircleCollision2(shot3.Position(), 12, (*enit)->Position(), 12)||
				col.CircleCollision2(shot4.Position(), 12, (*enit)->Position(), 12)||
				col.CircleCollision2(shot5.Position(), 12, (*enit)->Position(), 12)||
				col.CircleCollision2(shot6.Position(), 12, (*enit)->Position(), 12)||
				col.CircleCollision2(shot7.Position(), 12, (*enit)->Position(), 12)||
				col.CircleCollision2(shot8.Position(), 12, (*enit)->Position(), 12)||
				col.CircleCollision2(shot9.Position(), 12, (*enit)->Position(), 12)||
				col.CircleCollision2(shot10.Position(), 12, (*enit)->Position(), 12))
			{
				//shotcache.Cache(*it);
				enemycache.Cache(*enit);
				//auto eit = find(shotlist.begin(),shotlist.end(),it);
				//it = shotlist.erase(it);
				//auto eenit = find(enemylist.begin(), enemylist.end(), enit);
				enit = enemylist.erase(enit);
				count = count + 1;
				if (count == 10) {
					SceneManager::Instance().LoadScene("Title");
				}
				continue;
			}
			//++it;
			++enit;
		//}
	}

		background.Render();
		player.Render();
		p.Render();
		shot.Render();
		shot2.Render();
		shot3.Render();
		shot4.Render();
		shot5.Render();
		shot6.Render();
		shot7.Render();
		shot8.Render();
		shot9.Render();
		shot10.Render();
		//for (auto shot : shotlist) {
			//shot->Render();
		//}
		for (auto enemy : enemylist) {
			enemy->Render();
		}
}


void GameScene::Release() {
}