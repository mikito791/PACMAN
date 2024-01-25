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
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Stage(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

