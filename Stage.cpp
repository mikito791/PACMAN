#include "Stage.h"
#include"Engine/Model.h"
#include"Engine/CsvReader.h"
#include"Engine/Camera.h"
namespace {
	/*const int stageWidth_{ 15 };
	const int stageHeight_{ 15 };
	const int stageData[stageHeight_][stageWidth_]{
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};*/
}

bool Stage::IsWall(int _x, int _y)
{

	if (stageData[_y][_x]==STAGE_OBJ::WALL)
		return true;
	else
		return false;
}

Stage::Stage(GameObject* parent)
	:GameObject(parent,"Stage"),hFloor_(-1),hWall_(-1)
{
	CsvReader csv;
	csv.Load("Model\\map1.csv");
	//ステージ
	stageWidth_ = csv.GetWidth();
	stageHeight_ = csv.GetHeight();
	//ステージの幅と高さ→メンバ変数に代入
	
	
	for (int i = 0; i < stageHeight_; i++)
	{
		vector<int> sdata(stageWidth_, 0);//stageWidth_個の配列を0で初期化
		stageData.push_back(sdata);
	}
	//vector<vector<int>> stageData(h, vector<int>(w, 0));
	for (int j = 0; j < stageHeight_; j++)
	{
		for (int i = 0; i < stageWidth_; i++)
		{
			stageData[j][i] = csv.GetValue(i, j);
		}
	}
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
	floorTrans.position_ = { 0,0,0 };
	for (int z = 0; z < 15; z++)
	{
		for (int x = 0; x < 15; x++)
		{
			floorTrans.position_ = { (float)x, 0, (float)z };
	        //Model::SetTransform(hFloor_, floorTrans);
	        //Model::Draw(hFloor_);
			//Model::SetTransform(hWall_, floorTrans);
			//Model::Draw(hWall_);
			if (stageData[z][x] == 1) {
				Model::SetTransform(hWall_, floorTrans);
				Model::Draw(hWall_);
			}
			else {
				Model::SetTransform(hFloor_, floorTrans);
				Model::Draw(hFloor_);
			}
		}
	}	


}

void Stage::Release()
{
	//配列の掃除
	for (int i = 0; i < stageHeight_; i++)
	{
		stageData[i].clear();
	}
	stageData.clear();
}
