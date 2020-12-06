#define _USE_MATH_DEFINES  
#include "BulletStar.h"
#include <cmath>
#include "GraphFactory.h"

//	�R���X�g���N�^
BulletStar::BulletStar() : _size(Vector2D(32, 32))
{
}

//	�f�X�g���N�^
BulletStar::~BulletStar()
{
}

void BulletStar::Start(Vector2D pos, float angle)
{
	//	�摜�̓ǂݍ��݂��s��	
	grp = GraphFactory::Instance().LoadGraph("img\\pipo-mapeffect011j.png");

	_animFrameCount = 0;

	//	���W�̏�����
	_position = pos;

	//	�x���V�e�B�̏�����
	float velocity = 4.0f;
	auto x = cos((M_PI / 180) * angle) * velocity;
	auto y = sin((M_PI / 180) * angle) * velocity;

	_velocity = Vector2D(x, y);

	//	�\����ԂɕύX
	SetActive(true);
}

//	�e����ʂɕ\������
void BulletStar::Render()
{
	//	��A�N�e�B�u�̏ꍇ�A�����`�悵�Ȃ�
	if (!isActive)
		return;

	//	���]�t���O��TRUE�ɂ��Ă���͉̂摜�̌����̊֌W��
	DrawRectGraph(static_cast<int>(_position.x),
		static_cast<int>(_position.y), _offset.x, _offset.y,
		static_cast<int>(_size.x),
		static_cast<int>(_size.y), grp, TRUE, TRUE);
}

//	�X�V
void BulletStar::Update()
{
	//	��A�N�e�B�u�̏ꍇ�A�����������Ȃ�
	if (!isActive)
		return;


	//	�A�j���[�V�����̎��s
	_animFrameCount++;

	//	�摜�̃I�t�Z�b�g�ʒu��ύX
	auto sheetNo = _animFrameCount / AnimationSpeed;
	_offset.x = (sheetNo % HorizonSheet) * _size.x;
	_offset.y = ((sheetNo / HorizonSheet) % VerticalSheet) * _size.y;

	//	�e�̍��W���ړ�������
	_position += _velocity;
}

void BulletStar::SetActive(bool value)
{
	isActive = value;
}

