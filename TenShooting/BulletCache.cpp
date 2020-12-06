#include"BulletCache.h"

BulletCache::~BulletCache() {
	while (!_cache.empty()) {
		auto bullet = _cache.front();
		delete bullet;
		_cache.pop();
	}
}

BulletStar *BulletCache::Instantiate(Vector2D pos, float angle) {
	if (_cache.size() > 0) {
		auto bullet = _cache.front();
		bullet->Start(pos, angle);
		_cache.pop();
		return bullet;
	}
	auto bullet = new BulletStar();
		bullet->Start(pos, angle);
	return bullet;
}

void BulletCache::Cache(BulletStar *bullet) {
	bullet->SetActive(false);

	_cache.push(bullet);
}

void BulletCache::ShowDebugLog() {
	//DrawFormatString(0, 16, GetColor(255, 255, 255), "弾のキャッシュ数：%d", _cache.size());
}