#include "Stage.h"
#include"Engine/Model.h"
#include"Engine/Camera.h"

Stage::Stage(GameObject* parent)
	:GameObject(parent,"Stage"),hFloor_(-1),hWall_(-1)
{
}

void Stage::Initialize()
{
	hFloor_ = Model::Load("Model\\Floor.fbx");
	assert(hFloor_ >= 0);
	hWall_ = Model::Load("Model\\Wall.fbx");
	assert(hWall_ >= 0);
	Camera::SetPosition(XMFLOAT3(6.5, 10, -6));
	Camera::SetTarget(XMFLOAT3( 6.5,0,5.5 ));

}

void Stage::Update()
{
}

void Stage::Draw()
{
	Transform floorTrans;
	for (float z = 0; z < 15; z++)
	{
		for (float x = 0; x < 15; x++)
		{
			floorTrans.position_ = { x,0,z };
	        //Model::SetTransform(hFloor_, floorTrans);
	        //Model::Draw(hFloor_);
			Model::SetTransform(hWall_, floorTrans);
			Model::Draw(hWall_);
		}
	}	


}

void Stage::Release()
{
}
