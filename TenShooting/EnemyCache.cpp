#include"EnemyCache.h"

EnemyCache::~EnemyCache() {
	while (!_cache.empty()) {
		auto enemy = _cache.front();
		delete enemy;
		_cache.pop();
	}
}

Enemy *EnemyCache::Instantiate(Vector2D pos,float angle) {
	if (_cache.size() > 0) {
		auto enemy = _cache.front();
		enemy->Start(pos,angle);
		_cache.pop();
		return enemy;
	}
	auto enemy = new Enemy();
	enemy->Start(pos,angle);
	return enemy;
}

void EnemyCache::Cache(Enemy *enemy) {
	enemy->SetActive(false);

	_cache.push(enemy);
}