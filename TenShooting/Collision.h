#pragma once
#include "Vector2D.h"
#include "GameObject.h"
#include "PlayerShot.h"
#include "EnemyManager.h"

//	�Փ˔���N���X
class Collision
{
public:
	//	�~�Ή~�̔���
	bool CircleCollision(const GameObject* objectA, const GameObject* objectB);

	//	��`�΋�`�̔���
	bool RectCollision(const GameObject* objectA, const GameObject* objectB);
	bool CircleCollision2(const Vector2D& circleA, int aradius, const Vector2D& circleB, int bradius);

};
