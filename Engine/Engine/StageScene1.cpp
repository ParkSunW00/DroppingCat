#include "stdafx.h"
#include "StageScene1.h"
#include "ChapterScene.h"

StageScene1::StageScene1() {

	//BACKGROUND
	background = new Sprite("Resource/background.png");
	AddObject(background);
	background->setPos(0, 0);

	//FORMER-BTN
	formerButton = new Sprite("Resource/former.png");
	AddObject(formerButton);
	formerButton->setPos(20, 20);

	//GLASS-STAGE
	glass = new Sprite("Resource/glass-stage.png");
	AddObject(glass);
	glass->setPos(200,265);

	//COLLECT-BOX
	Sprite* tmpCollect_box = new Sprite("Resource/collect-box.png");
	tmpCollect_box->setPos(160,230);
	collectboxList.push_back(tmpCollect_box);
}
StageScene1::~StageScene1() {

}
void StageScene1::Render() {

	//BACKGROUND
	background->Render();

	//FORMER-BTN
	formerButton->Render();

	//COLLECT-BOX
	for (auto& collectbox : collectboxList) {
		collectbox->Render();
	}
	//GLASS
	glass->Render();
}
void StageScene1::Update(float dTime) {
	Scene::Update(dTime);

	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN) {

		if (formerButton->IsPointInRect(inputManager->GetMousePos())) {
			sceneManager->ChangeScene(new ChapterScene());
			return;
		}
		if (glass->IsPointInRect(inputManager->GetMousePos())) {
			sceneManager->ChangeScene(new GameScene);
		}
	}
}
