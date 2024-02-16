#include "PlayScene.h"
#include"Stage.h"
#include"Player.h"
#include"Gauge.h"
#include"food.h"


PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Instantiate<Player>(this);
	Instantiate<Gauge>(this);
	Instantiate<food>(this);
}
	

void PlayScene::Update()
{


}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
