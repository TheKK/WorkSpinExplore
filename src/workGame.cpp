/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: workGame.cpp
 */

#include "workGame.h"

const static SDL_Rect viewport = {0, 0, 213, 360};

WorkGame::WorkGame(const Window& window):
	testButton("normal.png", "hover.png", "push.png", window),
	numDisplayer_(window)
{
	targetRenderer_ = window.GetRenderer();
	testButton.Move(viewport.x, viewport.y);
}

WorkGame::~WorkGame()
{
}

void
WorkGame::EventHandler(const SDL_Event& event)
{
	switch (event.type) {
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_e:
			numDisplayer_.AddNum(3);
			break;
		case SDLK_r:
			numDisplayer_.SetNum(9876);	
			break;
		}
		break;;
	}
	testButton.EventHandler(event);
}

void
WorkGame::Update()
{
	testButton.Update();
}

void
WorkGame::Render()
{
	testButton.Render();
	numDisplayer_.Render();
}
