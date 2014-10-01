/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: spinGame.cpp
 */

#include "spinGame.h"

const static SDL_Rect viewport = {213, 0, 213, 360};

SpinGame::SpinGame(SDL_Renderer* renderer):
	backGroundPicture_("spinGameBG.png", renderer),
	spinPicture_("spin.png", renderer),
	monsterCounter_("number.png", 4, 30, 30, renderer)
{
	targetRenderer_ = renderer;

	/* Initialize according to viewport coordinate */
	backGroundPicture_.MoveTo(viewport.x, viewport.y);
	spinPicture_.MoveTo(viewport.x, viewport.y);
	monsterCounter_.MoveTo(viewport.x, viewport.y);

	spinPicture_.Move(80, 219);
	monsterCounter_.Move(30, 150);

	renderableList_.push_back(&spinPicture_);
	renderableList_.push_back(&monsterCounter_);
}

SpinGame::~SpinGame()
{
	Release_();
}

void
SpinGame::EventHandler(const SDL_Event& event)
{
	switch (event.type) {
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_F11:
			debugOff_ = !debugOff_;
			if (debugOff_)
				cout << "Debug mode off" << endl;
			else
				cout << "Debug mode on" << endl;
			break;
		}
		break;
	case SDL_MOUSEMOTION:
		if (debugOff_)
			break;

		for (Renderable* e : renderableList_) {
			if (e->MouseHovered(event.motion.x, event.motion.y) &&
			    event.motion.state == SDL_BUTTON_LMASK) {
				e->Move(event.motion.xrel, event.motion.yrel);	
			}
		}
		break;
	case SDL_MOUSEBUTTONDOWN:
		/* Check current mode */
		if (debugOff_)
			break;

		if (event.button.button == SDL_BUTTON_MIDDLE) {
			for (Renderable* e : renderableList_) {
				if (e->MouseHovered(event.button.x,
						    event.button.y)) {
					cout << "x: " << e->PosX() << endl;
					cout << "y: " << e->PosY() << endl;
				}
			}
		}
		break;
	case SDL_MOUSEWHEEL:
		SpinSpin_(1);
		break;
	}
}

void
SpinGame::Update()
{
}

void
SpinGame::Render()
{
	backGroundPicture_.Render();
	
	for (auto& e : renderableList_)
		e->Render();
}

void
SpinGame::SpinSpin_(int16_t degree)
{
	static int16_t rotateValue = 0;

	if ((rand() % 10) == 1) {
		spinPicture_.Rotate(degree * 10);
		rotateValue += degree * 10;
	} else {
		spinPicture_.Rotate(degree);
		rotateValue += degree;
	}

	if (rotateValue >= 360) {
		monsterCounter_.AddNum(1);
		rotateValue -= 360;
	}
}

void
SpinGame::Release_()
{
}
