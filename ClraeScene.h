#pragma once
#include "Engine/GameObject.h"
class Text;
class ClraeScene :
    public GameObject
{
public:
	int hPict_;
	Text* ctext;
public:
	ClraeScene(GameObject* parent);

	
	void Initialize() override;


	void Update() override;


	void Draw() override;


	void Release() override;
};

