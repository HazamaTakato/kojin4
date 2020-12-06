#pragma once
#include "Vector2D.h"
#include "GameObject.h"
#include "PlayerShot.h"
#include "EnemyManager.h"

//	衝突判定クラス
class Collision
{
public:
	//	円対円の判定
	bool CircleCollision(const GameObject* objectA, const GameObject* objectB);

	//	矩形対矩形の判定
	bool RectCollision(const GameObject* objectA, const GameObject* objectB);
	bool CircleCollision2(const Vector2D& circleA, int aradius, const Vector2D& circleB, int bradius);

};
