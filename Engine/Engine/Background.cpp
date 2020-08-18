#include "stdafx.h"
#include "Background.h"

Background::Background() {
	background = new Sprite("Resource/background.png");
	AddChild(background);
}

Background::~Background() {

}

void Background::Render() {
	Object::Render();
	background->Render();
}

void Background::Update(float dTime) {
	Object::Update(dTime);
}