#include "stdafx.h"
#include "Player.h"

Player::Player() {
	isClick = false;

    playerAnimation = new Animation(2);
	playerAnimation->AddFrame("Resource/cat1.png");
	playerAnimation->AddFrame("Resource/cat2.png");
	AddChild(playerAnimation);

	rect = playerAnimation->getRect();
}

Player::~Player() {

}

void Player::Render() {
	Object::Render();
	playerAnimation->Render();
}

void Player::Update(float dTime) {
	if (isClick) {
		playerAnimation->Update(dTime);
		if (playerAnimation->getIsFinalSrite()) {
			isClick = false;
			playerAnimation->setIsFinalSprite(false);
		}
	}
}

void Player::setIsClicked(bool isClicked) {
	this->isClick = isClicked;
}

bool Player::getIsClicked() {
	return isClick;
}