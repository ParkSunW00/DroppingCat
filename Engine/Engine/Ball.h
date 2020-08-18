#pragma once
#include "Object.h"
#include "Animation.h"
class Ball : public Object
{
private:
	Animation* ballAnimation;
	//중력
	float gravity;
	//속도
	float velocity;
	//발사각도
	float angle;
	//시간
	float time;
	//높이
	float height;
	//거리
	float distance;

	bool isJump;
	bool isClick;

public:
	Ball();
	~Ball();

	void Render();
	void Update(float dTime);

	void setIsClicked(bool isClick);
	bool getIsClicked();
};

