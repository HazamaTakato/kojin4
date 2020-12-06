#pragma once
#include "Vector2D.h"

//	ゲームオブジェクトクラス
class GameObject
{
public:
	//	コンストラクタ
	GameObject() : _position(0, 0), _size(0, 0) {}

	//	開始
	virtual void Start(Vector2D pos,float angle) = 0;

	//	描画
	virtual void Render() = 0;

	//	更新
	virtual void Update() = 0;

	//	解放
	virtual void Release() = 0;

	virtual void Shot(const Vector2D& pos, float angle) = 0;

	//	※Tipsメンバ関数にconstを付与する事で
	//	その関数内でのメンバ変数の変更を禁止にする
	Vector2D Position() const { return _position; }
	Vector2D Size() const { return _size; }
	float Radius() const { return _radius; }

public:
	Vector2D _position;		//	座標
	Vector2D _size;			//	サイズ
	float _radius;			//	半径
};
