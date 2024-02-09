#include "food.h"
#include"Engine/Model.h"
food::food(GameObject* parent)
	:GameObject(parent,"food"),hModel_(-1)
{
}

void food::Initialize()
{
	hModel_ = Model::Load("Model\\food.fbx");
	assert(hModel_ >= 0);
	transform_.position_.y = 2;
}

void food::Update()
{
}

void food::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void food::Release()
{
}
