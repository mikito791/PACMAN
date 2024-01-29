#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
namespace {
	const float PLAYER_MOVE_SPEED{ 0.1f };
}
Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel_(-1),speed_(PLAYER_MOVE_SPEED)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Model\\Player.fbx");
	assert(hModel_ >= 0);
	transform_.position_.x = 0.5;
	transform_.position_.z = 1.5;

}

void Player::Update()
{
	//向き初期化
	//enum Dir
	//{
	//	LEFT,RIGHT,UP,DOWN,NONE
	//};
	//int moveDir = Dir::NONE;
	XMVECTOR vFront = { 0,0,1,0 };
	XMVECTOR move{ 0,0,1,0 };//移動初期化

	if (Input::IsKey(DIK_LEFT))
	{
		//transform_.rotate_.y = -90;
		//transform_.position_.x -= 0.1f;
		
		//moveDir = Dir::LEFT;
		move = XMVECTOR{ -1,0,0,0 };
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		//transform_.rotate_.y = 90;
		//transform_.position_.x += 0.1f;
		move = XMVECTOR{ 1,0,0,0 };
		//moveDir = Dir::RIGHT;
	}
	if (Input::IsKey(DIK_UP))
	{
		//transform_.rotate_.y = 0;
		//transform_.position_.z += 0.1f;
		move = XMVECTOR{ 0,0,1,0 };
		//moveDir = Dir::UP;
	}
	if (Input::IsKey(DIK_DOWN))
	{
		//transform_.rotate_.y = -180;
		//transform_.position_.z -= 0.1f;
		move = XMVECTOR{ 0,0,-1,0 };
		//moveDir = Dir::DOWN;
	}
	//キャラの移動で必要↓
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	pos = pos + speed_ * move;
	XMStoreFloat3(&(transform_.position_), pos);

	XMVECTOR vdot= XMVector3Dot(vFront, move);
	float angle = acos(XMVectorGetX(vdot));

	XMVECTOR vCross = XMVector3Cross(vFront, move);
	if (XMVectorGetY(vCross) < 0)
	{
		angle *= -1;
	}
	transform_.rotate_.y = XMConvertToDegrees(angle);
	//キャラの向き
	//float rotAngle[5]{ -90,90,0,180,180 };
	//transform_.rotate_.y = rotAngle[moveDir];
}

void Player::Draw()
{
	//Transform playerPos;
	//playerPos.position_ = { 6.5,0,7.5 };真ん中配置
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
