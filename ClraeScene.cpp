#include "ClraeScene.h"
#include"Engine/SceneManager.h"
#include"Engine/Image.h"
#include"Engine/Input.h"
#include"Engine/Text.h"

ClraeScene::ClraeScene(GameObject* parent)
	:GameObject(parent, "ClearScnen"), hPict_(-1), ctext(nullptr)
{
}

void ClraeScene::Initialize()
{
	hPict_ = Image::Load("Model\\clear.png");
	assert(hPict_ >= 0);
	ctext = new Text;
	ctext->Initialize();
}

void ClraeScene::Update()
{
	if (Input::IsKeyDown(DIK_R))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
}

void ClraeScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
	ctext->Draw(30, 30, "PUSH,R,RETRYGAME");
}

void ClraeScene::Release()
{
}
