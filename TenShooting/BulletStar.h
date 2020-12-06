#pragma once
#include "Vector2D.h"
#include "DxLib.h"

//	弾のクラス
class BulletStar
{
public:
	//	コンストラクタ
	BulletStar();

	//	デストラクタ
	~BulletStar();

	//	開始
	void Start(Vector2D pos, float angle);

	//	描画
	void Render();

	//	更新
	void Update();

	void SetActive(bool value);

	//	座標の取得
	Vector2D Position() {
		return _position;
	}

	//	サイズの取得
	Vector2D Size() {
		return _size;
	}

private:
	const int AnimationSpeed = 4;	//	アニメーションの速度
	const int HorizonSheet = 5;		//	横画像の枚数
	const int VerticalSheet = 4;	//	縦画像の枚数
	Vector2D _position;				//	座標
	Vector2D _size;					//	画像サイズ
	Vector2D _offset;				//	オフセット座標
	Vector2D _velocity;				//	速度
	int grp;						//	画像ID
	int _animFrameCount;			//	アニメーションのフレームカウント
	bool isActive;					//	表示/非表示
};

