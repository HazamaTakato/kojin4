#include"PlayerShot.h"
#include"Collision.h"

void PlayerShot::Shot(const Vector2D&pos, float angle) {
	BulletStar* shot = _cache.Instantiate(pos, angle);
	_shotList.push_back(shot);
	//_position = pos;
}

void PlayerShot::Update() {
	for (auto it = _shotList.begin(); it != _shotList.end();) {
		(*it)->Update();
			if ((*it)->Position().x > WindowInfo::WindowWidth ||
				(*it)->Position().x < -(*it)->Size().x ||
				(*it)->Position().y > WindowInfo::WindowHeight ||
				(*it)->Position().y < -(*it)->Size().y)
			{
				_cache.Cache(*it);
				it = _shotList.erase(it);
				continue;
			}

			++it;
	}
}


void PlayerShot::Render() {
	_cache.ShowDebugLog();
	for (auto shot : _shotList) {
		shot->Render();
	}
}

void PlayerShot::Start() {

}

void PlayerShot::Release() {
	for (auto shot : _shotList) {
		delete shot;
	}
}