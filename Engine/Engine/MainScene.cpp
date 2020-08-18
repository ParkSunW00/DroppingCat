#include "stdafx.h"
#include "MainScene.h"
#include "ChapterScene.h"

MainScene::MainScene() {
	//BACKGROUND
	background = new Sprite("Resource/background.png");
	AddObject(background);
	background->setPos(0, 0);

	//TITLE
	title = new Sprite("Resource/title.png");
	AddObject(title);
	title->setPos(210, 130);

	//START TXT
	Sprite* tmpStart = new Sprite("Resource/start.png");
	tmpStart->setPos(445, 600);
	startList.push_back(tmpStart);

	//OPTION -> EXIT-BTN
	exitButton = new Sprite("Resource/exit.png");
	AddObject(exitButton);
	exitButton->setPos(1370, 40);
}

MainScene::~MainScene() {

}

void MainScene::Render() {

	//BACKGROUND
	background->Render();

	//TITLE
	title->Render();

	//START-TXT
	for (auto& start : startList) {
		start->Render();
	}

	//EXIT-BTN
	exitButton->Render();
}

void MainScene::Update(float dTime) {
	Scene::Update(dTime);

	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN) {
		if (exitButton->IsPointInRect(inputManager->GetMousePos())) {
			PostQuitMessage(0);
			return;
		}
		if (background->IsPointInRect(inputManager->GetMousePos())) {
			sceneManager->ChangeScene(new ChapterScene());
			return;
		}


	}
}