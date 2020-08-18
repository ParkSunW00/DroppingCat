#include "stdafx.h"
#include "Engine.h"

Engine::Engine() {
	isClick = false;

	engineAnimation = new Animation(1);
	engineAnimation->AddFrame("Resource/Egn-std.png");
	engineAnimation->AddFrame("Resource/Egn-using1.png");
	engineAnimation->AddFrame("Resource/Egn-using2.png");
	engineAnimation->AddFrame("Resource/Egn-using3.png");
	engineAnimation->AddFrame("Resource/Egn-using4.png");
	AddChild(engineAnimation);

	rect = engineAnimation->getRect();
}

Engine::~Engine() {

}

void Engine::Render() {
	Object::Render();
	engineAnimation->Render();
}

void Engine::Update(float dTime) {
	if (isClick) {
		engineAnimation->Update(dTime);
		if (engineAnimation->getIsFinalSrite()) {
			isClick = false;
		}
	}
}

void Engine::setIsClicked(bool isClicked) {
	this->isClick = isClicked;
}

bool Engine::getIsClicked() {
	return isClick;
}