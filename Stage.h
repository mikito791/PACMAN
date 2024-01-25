#pragma once
#include "Engine/GameObject.h"
#include<vector>
using std::vector;
class Stage :
    public GameObject
{
	int hFloor_;
	int hWall_;
	const int STAGE_X{ 15 };
	const int STAGE_Z{ 15 };
	int stageData;
	//1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	//1,0,0,0,0,0,0,0,0,0,0,0,0,0,1
	//1,0,0,0,0,0,0,0,0,0,0,0,0,0,1
	//1,0,0,0,0,0,0,0,0,0,0,0,0,0,1
	//1,0,0,0,0,0,0,0,0,0,0,0,0,0,1
	//1,0,0,0,0,0,0,0,0,0,0,0,0,0,1
	//1,0,0,0,0,0,0,0,0,0,0,0,0,0,1
	//1,0,0,0,0,0,0,0,0,0,0,0,0,0,1
	//1,0,0,0,0,0,0,0,0,0,0,0,0,0,1
	//1,0,0,0,0,0,0,0,0,0,0,0,0,0,1
	//1,0,0,0,0,0,0,0,0,0,0,0,0,0,1
	//1,0,0,0,0,0,0,0,0,0,0,0,0,0,1
	//1,0,0,0,0,0,0,0,0,0,0,0,0,0,1
	//1,0,0,0,0,0,0,0,0,0,0,0,0,0,1
	//1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Stage(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

