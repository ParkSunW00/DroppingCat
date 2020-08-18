#include "stdafx.h"
#include "Ball.h"
#include <math.h>
Ball::Ball() {

	isClick = false;
	ballAnimation = new Animation(0);
	ballAnimation->AddFrame("Resource/ball.png");
	rect = ballAnimation->getRect();

	gravity = false;
	isJump = false;

	gravity = 9.8;
	velocity = 50;
	angle = 60;
	time = 0;
	height = 0;
	distance = 0;

	AddChild(ballAnimation);
}
Ball::~Ball() {

}
void Ball::Render() {
	Object::Render();
	ballAnimation->Render();
}

void Ball::Update(float dTime) {

	//angleÀ» radianÀ¸·Î 
	float radian = angle * 180 / 3.14;

	height = velocity * time * sin(radian) - 0.5f * gravity * time * time;
	distance = velocity * time*cos(radian);

	if (isJump) {
		setPos(getPosX(), getPosY() - 500 * dTime);
		gravity += 900.8f *dTime;
		setPos(getPosX() + 10, getPosY() + gravity * dTime);
	}

	if (isClick) {
		ballAnimation->Update(dTime);
		if (getPosY() == 520) {
			isJump = true;
			gravity = 0;
		}
	}

	if (getPosY() > 520) {
		setPos(getPosX(), 520);
		isJump = false;
	}

	if (height < 0) {
		return;
	}

	if (1530 - 88 < getPosX()) {
		setPos(1530 - 88, getPosY());
		isJump = false;
		if (isClick) {
			ballAnimation->Update(dTime);
			if (getPosY() == 520) {
				isJump = true;
				gravity = 0;
			}
		}
	}
}

void Ball::setIsClicked(bool isClicked) {
	this->isClick = isClicked;
}

bool Ball::getIsClicked() {
	return isClick;
}