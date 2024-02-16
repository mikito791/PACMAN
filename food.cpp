#include "food.h"
#include"Engine/Model.h"
#include"Engine/CsvReader.h"
#include"Engine/SphereCollider.h"

food::food(GameObject* parent)
	:GameObject(parent,"food"),hFood_(-1)
{
	CsvReader csvfood;
	csvfood.Load("Model\\map1.csv");
	foodWidth_ = csvfood.GetWidth();
	foodHeight_ = csvfood.GetHeight();
	for (int i = 0; i < foodHeight_; i++)
	{
		vector<int> fdata(foodWidth_, 0);//foodWidth_å¬ÇÃîzóÒÇ0Ç≈èâä˙âª
		foodData.push_back(fdata);
	}
	//vector<vector<int>> stageData(h, vector<int>(w, 0));
	for (int j = 0; j < foodHeight_; j++)
	{
		for (int i = 0; i < foodWidth_; i++)
		{
			foodData[j][i] = csvfood.GetValue(i, j);
		}
	}
}

void food::Initialize()
{
	hFood_ = Model::Load("Model\\food.fbx");
	assert(hFood_ >= 0);
	SphereCollider* foodcollider = new SphereCollider(XMFLOAT3(0, 0, 0), 0.5);
	AddCollider(foodcollider);
}

void food::Update()
{
}

void food::Draw()
{
	Transform foodTrans;
	foodTrans.position_ = { 0,0,0 };
	for (int z = 0; z < 15; z++)
	{
		for (int x = 0; x < 15; x++)
		{
			foodTrans.position_ = { (float)x, 0, (float)z};
			if (foodData[z][x] == 0) {
				Model::SetTransform(hFood_, foodTrans);
				Model::Draw(hFood_);
			}
		}
	}
}

void food::Release()
{
	for (int i = 0; i < foodHeight_; i++)
	{
		foodData[i].clear();
	}
	foodData.clear();
}
