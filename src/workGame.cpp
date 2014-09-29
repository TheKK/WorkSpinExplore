/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: workGame.cpp
 */

#include "workGame.h"

const static SDL_Rect viewport = {0, 0, 213, 360};

WorkGame::WorkGame(const Window& window):
	backGroundPicture_("workGameBG.png", window),
	workButton_("normal.png", "hover.png", "push.png", window),
	moneyDisplayer_(window)
{
	targetRenderer_ = window.GetRenderer();

	/* Set initial position to the coner of this viewport*/
	backGroundPicture_.MoveTo(viewport.x, viewport.y);
	//workButton_.MoveTo(viewport.x, viewport.y);
	moneyDisplayer_.MoveTo(viewport.x, viewport.y);

	/* Move these friends to their new place*/
	workButton_.Move(
		(viewport.w - workButton_.Width()) / 2,
		(viewport.h - workButton_.Height()) / 2);
	moneyDisplayer_.Move(
		(viewport.w - moneyDisplayer_.Width()) / 2 - 30,
		viewport.h - moneyDisplayer_.Height() - 10);
}

WorkGame::~WorkGame()
{
	Release_();
}

void
WorkGame::EventHandler(const SDL_Event& event)
{
	switch (event.type) {
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		}
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (event.button.button == SDL_BUTTON_LEFT)
			TapTheButton_();
		break;
	case SDL_MOUSEBUTTONUP:
		if (event.button.button == SDL_BUTTON_LEFT)
			ReleaseTheButton_();
		break;
	case SDL_USEREVENT:
		if (event.user.type == UserEvents::UserEvent1)
			cout << "event1 got" << endl;
		else if (event.user.type == UserEvents::UserEvent2)
			cout << "event2 got" << endl;
		else
			cout << event.user.type << endl;
		break;
	}
}

void
WorkGame::Update()
{
}

void
WorkGame::Render()
{
	backGroundPicture_.Render();

	workButton_.Render();
	moneyDisplayer_.Render();
}

void
WorkGame::TapTheButton_()
{
	workButton_.ChangeState(BUTTON_PUSHED);
	moneyDisplayer_.AddNum(1);
}

void
WorkGame::ReleaseTheButton_()
{
	workButton_.ChangeState(BUTTON_NORMAL);
}

void
WorkGame::Release_()
{
}
