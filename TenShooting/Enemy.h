#pragma once
#include"DxLib.h"
#include"Vector2D.h"
#include"GameObject.h"

class Enemy{
public:
	Enemy();
	~Enemy();
	//	�J�n
	void Start(Vector2D pos,float angle);

	//	�`��
	void Render();

	//	�X�V
	void Update();

	Vector2D Position() {
		return _position;
	}

	Vector2D Size() {
		return _size;
	}

	void SetActive(bool value);

public:
	//	�摜�n���h��
	int _grp;
	Vector2D _position;
	Vector2D _size;
	Vector2D _velocity;
	bool isActive;
};
