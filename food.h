#pragma once
#include "Engine/GameObject.h"
class food :
    public GameObject
{
	int hModel_;
public:
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

