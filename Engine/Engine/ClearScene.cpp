#include "stdafx.h"
#include "ClearScene.h"

ClearScene::ClearScene() {
	//BACKGROUND
	background = new Sprite("Resource/background.png");
	AddObject(background);
	background->setPos(0, 0);

	//CLAER-TXT
	clear_txt = new Sprite("Resource/clear.png");
	AddObject(clear_txt);
	clear_txt->setPos(400, 100);

	//COLLECT
	Sprite* collect_box = new Sprite("Resource/collect.png");
	collect_box->setPos(400, 400);
	collectList.push_back(collect_box);

	//GOAL
	Sprite* tmpGoal = new Sprite("Resource/goal.png");
	tmpGoal->setPos(610, 420);
	goalList.push_back(tmpGoal);

	//OPTION -> RETURN-BTN
	returnButton = new Sprite("Resource/return.png");
	AddObject(returnButton);
	returnButton->setPos(1100, 70);

	//OPTION -> OPTION-BTN
	optionButton = new Sprite("Resource/option.png");
	AddObject(optionButton);
	optionButton->setPos(1230, 70);

	//OPTION -> HOME-BTN
	homeButton = new Sprite("Resource/home.png");
	AddObject(homeButton);
	homeButton->setPos(1370, 70);

}
ClearScene::~ClearScene() {

}
void ClearScene::Render() {
	//BACKGROUND
	background->Render();

	//CLEAR-TXR
	clear_txt->Render();

	//OPTION -> RETURN-BTN
	returnButton->Render();

	//OPTION -> OPTION-BTN
	optionButton->Render();

	//OPTION -> HOME-BTN
	homeButton->Render();

	//COLLECT-BOX
	for (auto& collect : collectList) {
		collect->Render();
	}

	//GOAL
	for (auto& goal : goalList) {
		goal->Render();
	}

}
void ClearScene::Update(float dTime) {
	Scene::Update(dTime);

	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN) {

		if (returnButton->IsPointInRect(inputManager->GetMousePos())) {
			sceneManager->ChangeScene(new GameScene());
			return;
		}

		if (optionButton->IsPointInRect(inputManager->GetMousePos())) {
			return;
		}
		if (homeButton->IsPointInRect(inputManager->GetMousePos())) {
			sceneManager->ChangeScene(new MainScene());
		}
	}

}