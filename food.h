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

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

