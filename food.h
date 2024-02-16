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

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;
};

