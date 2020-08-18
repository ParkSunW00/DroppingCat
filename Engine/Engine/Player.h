#pragma once
#include "Object.h"
#include "Animation.h"

class Player : public Object
{
private :
	Animation* playerAnimation;
	bool isClick;

public :
	Player();
	~Player();

	void Render();
	void Update(float dTime);

	void setIsClicked(bool isClick);
	bool getIsClicked();

};