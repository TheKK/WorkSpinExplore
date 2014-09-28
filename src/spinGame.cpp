/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: spinGame.cpp
 */

#include "spinGame.h"

const static SDL_Rect viewport = {213, 0, 213, 360};

SpinGame::SpinGame(const Window& window):
	backGroundPicture_("spinGameBG.png", window)
{
	targetRenderer_ = window.GetRenderer();

	backGroundPicture_.MoveTo(viewport.x, viewport.y);
}

SpinGame::~SpinGame()
{
}

void
SpinGame::EventHandler(const SDL_Event& event)
{
	switch (event.type) {
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
}
