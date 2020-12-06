#include"EnemyManager.h"
#include<cmath>
//EnemyManager::~EnemyManager() {

//}

void EnemyManager::Spawn(const Vector2D&pos, float angle) {
	Enemy* enemy = cache.Instantiate(pos,angle);
	enemyList.push_back(enemy);
}

void EnemyManager::Update(){
	for (auto it = enemyList.begin(); it != enemyList.end();) {
		(*it)->Update();

		if ((*it)->Position().x > WindowInfo::WindowWidth ||
			(*it)->Position().x < -(*it)->Size().x ||
			(*it)->Position().y > WindowInfo::WindowHeight ||
			(*it)->Position().y < -(*it)->Size().y)
		{
			cache.Cache(*it);
			it = enemyList.erase(it);
			continue;
		}

		++it;
	}
}

void EnemyManager::Render() {
	for (auto enemy: enemyList) {
		enemy->Render();
	}
}

void EnemyManager::Start() {
}

void EnemyManager::Release() {
	for (auto enemy : enemyList) {
		delete enemy;
	}
}