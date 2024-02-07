#include "Player.h"
#include"Stage.h"
#include"Gauge.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Debug.h"
#include"Engine/Debug.h"

namespace {
	const float PLAYER_MOVE_SPEED{ 1.0f };
}
Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),
	hModel_(-1),speed_(PLAYER_MOVE_SPEED),pStage_(nullptr),
	pGauge_(nullptr), hpCrr_(100), hpMax_(100)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Model\\Player.fbx");
	assert(hModel_ >= 0);
	transform_.position_.x = 0.5;
	transform_.position_.z = 1.5;
	pStage_ = (Stage*)FindObject("Stage");
	
}

void Player::Update()
{
	//向き初期化
	//enum Dir
	//{
	//	LEFT,RIGHT,UP,DOWN,NONE
	//};
	//int moveDir = Dir::NONE;
	XMVECTOR vFront = { 0,0,1,0 };//向き初期化
	XMVECTOR move{ 0,0,0,0 };//移動初期化

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
	//キャラの移動で必要↓//キャラの向きcosθで求める
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	XMVECTOR posTmp = XMVectorZero();
	//posTmp.x posTmp.z => int tx,ty :配列のインデックス
	//仮にmapの配列をmap[][]とする
	//pos = pos + speed_ * move;
	posTmp = pos + speed_ * move;
	int tx, ty;
	tx = (int)(XMVectorGetX(posTmp) + 1.0f);
	ty = pStage_->GetStageWidth() - (int)(XMVectorGetZ(posTmp) + 1.0f);
	if (!(pStage_->IsWall(tx, ty)))
	{
		pos = posTmp;
	}
	else
	{
		hpCrr_ = hpCrr_ - 2;
		if(hpCrr_ < 0)hpCrr_ = 0;
	}
	//Debug::Log("(iX,iZ)=");
	//Debug::Log(tx);
	//Debug::Log(",");
	//Debug::Log(ty);
	//Debug::Log(":");
	//Debug::Log(pStage_->IsWall(tx,ty ),true);

	if (!XMVector3Equal(move, XMVectorZero())) {
		XMStoreFloat3(&(transform_.position_), pos);

		/*XMVECTOR vdot = XMVector3Dot(vFront, move);
		assert(XMVectorGetX(vdot) <= 1 && XMVectorGetX(vdot) >= -1);
		float angle = acos(XMVectorGetX(vdot));

		XMVECTOR vCross = XMVector3Cross(vFront, move);
		if (XMVectorGetY(vCross) < 0)
		{
			angle *= -1;
		}*/

		XMMATRIX rot = XMMatrixRotationY(XM_PIDIV2);
		XMVECTOR modifindVec = XMVector3TransformCoord(move, rot);
	    /*Debug::Log(XMVectorGetX(modifindVec));
		Debug::Log(",");
		Debug::Log(XMVectorGetZ(modifindVec));*/

		float angle = atan2(XMVectorGetZ(modifindVec), XMVectorGetX(modifindVec));
		/*Debug::Log("=>");
		Debug::Log(XMConvertToDegrees(angle),true);*/
		transform_.rotate_.y = XMConvertToDegrees(-angle);
	}
	//キャラの向き
	//float rotAngle[5]{ -90,90,0,180,180 };
	//transform_.rotate_.y = rotAngle[moveDir];
    Gauge *pGauge_ = (Gauge*)FindObject("Gamge");
	pGauge_->SetGaugeVal(hpCrr_, hpMax_);
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
