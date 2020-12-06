#include"Player.h"
#include"GraphFactory.h"
//�R���X�g���N�^
//Player::Player(Vector2D pos) : _position(pos), _size(Vector2D(32, 32))
//{

//}

//����������
void Player::Start() {
	grp = GraphFactory::Instance().LoadGraph("img\\pipo-airship01.png");
	_size = Vector2D(32, 32);
	_position = Vector2D(0, 160);
}

//�`��
void Player::Render() {
	DrawRectGraph(static_cast<int>(_position.x),
		static_cast<int>(_position.y), 0, 64,
		static_cast<int>(_size.x),
		static_cast<int>(_size.y), grp, TRUE);
}

//�X�V
void Player::Update() {
	//�L�[���͍X�V
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//�ړ���
	Vector2D velocity;

	//��L�[�őO�ɐi��
	if (key&PAD_INPUT_UP) {
		velocity.y -= 2;
	}

	//���L�[�Ō��ɐi��
	if (key&PAD_INPUT_DOWN) {
		velocity.y += 2;
	}

	//�E�L�[�ŉE�ɐi��
	//if (key&PAD_INPUT_RIGHT) {
	//	velocity.x += 2;
	//}

	//���L�[�ō��ɐi��
	/*if (key&PAD_INPUT_LEFT) {
		velocity.x -= 2;
	}*/
	_position += velocity;
}

//�e�𔭎˂���
int Player::OnShotButton() {
	//���[�J���ŐÓI�ϐ���錾�����
	//���̒l�͊֐����I�����Ă��ێ������i������ƈ���
	static int inputFrame = 0;

	//�L�[�{�[�h�̃X�y�[�X�L�[�������ꂽ��
	if (CheckHitKey(KEY_INPUT_Z)) {
		inputFrame++;
	}
	else {
		inputFrame = 0;
	}
	return inputFrame;
}

int Player::HoldShotButton() {
	static int holdFrame = 0;
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		holdFrame++;
	}
	return holdFrame;
}