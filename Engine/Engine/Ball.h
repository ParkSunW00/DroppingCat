#pragma once
#include "Object.h"
#include "Animation.h"
class Ball : public Object
{
private:
	Animation* ballAnimation;
	//�߷�
	float gravity;
	//�ӵ�
	float velocity;
	//�߻簢��
	float angle;
	//�ð�
	float time;
	//����
	float height;
	//�Ÿ�
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

