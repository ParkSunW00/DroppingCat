#pragma once
#include "Object.h"
#include "Animation.h"

class Engine : public Object
{
private:
	Animation* engineAnimation;
	bool isClick;

public:
	Engine();
	~Engine();

	void Render();
	void Update(float dTime);

	void setIsClicked(bool isClick);
	bool getIsClicked();
};

