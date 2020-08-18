#include "stdafx.h"
#include "ChapterScene.h"
#include "StageScene1.h"

ChapterScene::ChapterScene() {

	//BACKGROUND
	background = new Sprite("Resource/background.png");
	AddObject(background);
	background->setPos(0, 0);

	//FORMER-BTN
	formerButton = new Sprite("Resource/former.png");
	AddObject(formerButton);
	formerButton->setPos(20, 20);

	//CHAPTER1
	chapter1 = new Sprite("Resource/chapter1.png");
	AddObject(chapter1);
	chapter1->setPos(40,120);

	//CHAPTER2
	chapter2 = new Sprite("Resource/chapter2.png");
	AddObject(chapter2);
	chapter2->setPos(540,120);

	//CHAPTER3
	chapter3 = new Sprite("Resource/chapter3.png");
	AddObject(chapter3);
	chapter3->setPos(1040, 120);
}

ChapterScene::~ChapterScene() {

}

void ChapterScene::Render() {

	//BACKGROUND
	background->Render();

	//CHAPTER
	chapter1->Render();
	chapter2->Render();
	chapter3->Render();

	//FORMER-BTN
	formerButton->Render();
}

void ChapterScene::Update(float dTime) {
	Scene::Update(dTime);

	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN) {

		if (formerButton->IsPointInRect(inputManager->GetMousePos())) {
			sceneManager->ChangeScene(new MainScene());
			return;
		}
		if (chapter1->IsPointInRect(inputManager->GetMousePos())) {
			sceneManager->ChangeScene(new StageScene1());
			return;
		}
		if (chapter2->IsPointInRect(inputManager->GetMousePos())) {
//			sceneManager->ChangeScene(new StageScene2());
			return;
		}
		if (chapter3->IsPointInRect(inputManager->GetMousePos())) {
//			sceneManager->ChangeScene(new StageScene3());
			return;
		}
	}
}