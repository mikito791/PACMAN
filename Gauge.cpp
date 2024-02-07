#include "Gauge.h"
#include"Engine/Image.h"

Gauge::Gauge(GameObject* parent)
	:GameObject(parent,"Gauge"),hGaugeBar_(-1),hGaugeFrame_(-1)
	,gaugeMaxVal_(100),gaugeCrrVal_(100)
{
}

void Gauge::Initialize()
{
	hGaugeBar_ = Image::Load("Model\\LifeGauge.png");
	assert(hGaugeBar_ >= 0);
	hGaugeFrame_ = Image::Load("Model\\LifeGaugeBar.png");
	assert(hGaugeFrame_ >= 0);
	transform_.position_.x = 0.0f;
	transform_.position_.y = 0.9f;
}

void Gauge::Update()
{
}

void Gauge::Draw()
{
	Transform tr = transform_;
	tr.scale_.x = (float)gaugeCrrVal_ / (float)gaugeMaxVal_;
	Image::SetTransform(hGaugeFrame_, transform_);
	Image::Draw(hGaugeFrame_);

	Image::SetTransform(hGaugeBar_, tr);
	Image::Draw(hGaugeBar_);
}
	

void Gauge::Release()
{
}

