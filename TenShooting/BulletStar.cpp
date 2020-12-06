#define _USE_MATH_DEFINES  
#include "BulletStar.h"
#include <cmath>
#include "GraphFactory.h"

//	コンストラクタ
BulletStar::BulletStar() : _size(Vector2D(32, 32))
{
}

//	デストラクタ
BulletStar::~BulletStar()
{
}

void BulletStar::Start(Vector2D pos, float angle)
{
	//	画像の読み込みを行う	
	grp = GraphFactory::Instance().LoadGraph("img\\pipo-mapeffect011j.png");

	_animFrameCount = 0;

	//	座標の初期化
	_position = pos;

	//	ベロシティの初期化
	float velocity = 4.0f;
	auto x = cos((M_PI / 180) * angle) * velocity;
	auto y = sin((M_PI / 180) * angle) * velocity;

	_velocity = Vector2D(x, y);

	//	表示状態に変更
	SetActive(true);
}

//	弾を画面に表示する
void BulletStar::Render()
{
	//	非アクティブの場合、何も描画しない
	if (!isActive)
		return;

	//	反転フラグをTRUEにしているのは画像の向きの関係上
	DrawRectGraph(static_cast<int>(_position.x),
		static_cast<int>(_position.y), _offset.x, _offset.y,
		static_cast<int>(_size.x),
		static_cast<int>(_size.y), grp, TRUE, TRUE);
}

//	更新
void BulletStar::Update()
{
	//	非アクティブの場合、何も処理しない
	if (!isActive)
		return;


	//	アニメーションの実行
	_animFrameCount++;

	//	画像のオフセット位置を変更
	auto sheetNo = _animFrameCount / AnimationSpeed;
	_offset.x = (sheetNo % HorizonSheet) * _size.x;
	_offset.y = ((sheetNo / HorizonSheet) % VerticalSheet) * _size.y;

	//	弾の座標を移動させる
	_position += _velocity;
}

void BulletStar::SetActive(bool value)
{
	isActive = value;
}

