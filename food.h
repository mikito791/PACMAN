#pragma once
#include "Engine/GameObject.h"
#include<vector>
using std::vector;
class food :
    public GameObject
{
	int hFood_;
	vector<vector<int>>foodData;
	int foodWidth_, foodHeight_;
public:
	int GetFoodWidth() { return foodWidth_; }
	int GetFoodHeight() { return foodHeight_; }
	food(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

