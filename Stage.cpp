#include "Stage.h"
#include"Engine/Model.h"
#include"Engine/CsvReader.h"
#include"Engine/Camera.h"
namespace {
	const int STAGE_X{ 15 };
	const int STAGE_Y{ 15 };
	const int stageData[STAGE_Y][STAGE_X]{
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
	};


}

Stage::Stage(GameObject* parent)
	:GameObject(parent,"Stage"),hFloor_(-1),hWall_(-1)
{
	CsvReader csv;
	csv.Load("Model\\map.csv");
	int STAGE_X = csv.GetWidth();
	int STAGE_Y = csv.GetHeight();
	
	for (int i = 0; i < STAGE_Y; i++)
	{
		vector<int> sdata(STAGE_X, 0);
		stageData.push_back(sdata);
	}
	//vector<vector<int>> stageData(h, vector<int>(w, 0));
	for (int j = 0; j < STAGE_Y; j++)
	{
		for (int i = 0; i < STAGE_X; i++)
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
}
