/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: spinGame.cpp
 */

#include "spinGame.h"

const static SDL_Rect viewport = {213, 0, 213, 360};

SpinGame::SpinGame(SDL_Renderer* renderer):
	backGroundPicture_("spinGameBG.png", renderer),
	spinPicture_("spin.png", renderer)
{
	targetRenderer_ = renderer;

	/* Initialize according to viewport coordinate */
	backGroundPicture_.MoveTo(viewport.x, viewport.y);
	spinPicture_.MoveTo(viewport.x, viewport.y);

	spinPicture_.Move(80, 219);
}

SpinGame::~SpinGame()
{
}

void
SpinGame::EventHandler(const SDL_Event& event)
{
	switch (event.type) {
	case SDL_MOUSEWHEEL:
		spinPicture_.Rotate(5.0);
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
	
	spinPicture_.Render();
}
