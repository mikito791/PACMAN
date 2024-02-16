#pragma once
#include "Engine/GameObject.h"
class Stage;
class Gauge;
class Player :
    public GameObject
{
    int hModel_;
	float speed_;
	Stage* pStage_;
	Gauge* pGauge_;
	int hpCrr_;
	int hpMax_;
public:
	Player(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
	void OnCollision(GameObject* pTarget) override;
};

