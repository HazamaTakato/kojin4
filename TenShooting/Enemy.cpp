#define _USE_MATH_DEFINES
#include"Enemy.h"
#include<cmath>
#include"GraphFactory.h"

Enemy::Enemy() :_size(Vector2D(32, 32)) {

}

Enemy::~Enemy() {

}

void Enemy::Start(Vector2D pos, float angle) {
	_grp = GraphFactory::Instance().LoadGraph("img\\pipo-charachip010.png");
	_position = pos;

	//float vel = 4.0f;
	//auto x = cos((M_PI / 180) * angle) * vel;
	//auto y = sin((M_PI / 180) * angle) * vel;

	//_velocity = Vector2D(x, y);

	SetActive(true);
}

void Enemy::Render() {
	//	��A�N�e�B�u�̏ꍇ�A�����`�悵�Ȃ�
	if (!isActive)
		return;
	//	���]�t���O��TRUE�ɂ��Ă���͉̂摜�̌����̊֌W��
	DrawRectGraph(static_cast<int>(_position.x),
		static_cast<int>(_position.y), 0, 64,
		static_cast<int>(_size.x),
		static_cast<int>(_size.y), _grp, TRUE, TRUE);

}


void Enemy::Update() {
		//	��A�N�e�B�u�̏ꍇ�A�����������Ȃ�
		if (!isActive)
			return;
	//_position -= _velocity;
}
void Enemy::SetActive(bool value)
{
	isActive = value;
}