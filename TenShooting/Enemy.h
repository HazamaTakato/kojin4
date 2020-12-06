#pragma once
#include"DxLib.h"
#include"Vector2D.h"
#include"GameObject.h"

class Enemy{
public:
	Enemy();
	~Enemy();
	//	開始
	void Start(Vector2D pos,float angle);

	//	描画
	void Render();

	//	更新
	void Update();

	Vector2D Position() {
		return _position;
	}

	Vector2D Size() {
		return _size;
	}

	void SetActive(bool value);

public:
	//	画像ハンドル
	int _grp;
	Vector2D _position;
	Vector2D _size;
	Vector2D _velocity;
	bool isActive;
};
