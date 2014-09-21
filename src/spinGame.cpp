/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: spinGame.cpp
 */

#include "spinGame.h"

const static SDL_Rect viewport = {213, 0, 213, 360};

SpinGame::SpinGame(const Window& window):
	testButton("normal.png", "hover.png", "push.png", window)
{
	targetRenderer_ = window.GetRenderer();
	testButton.Move(viewport.x, viewport.y);
}

SpinGame::~SpinGame()
{
}

void
SpinGame::EventHandler(const SDL_Event& event)
{
	switch (event.type) {
	}
	testButton.EventHandler(event);
}

void
SpinGame::Update()
{
	testButton.Update();
}

void
SpinGame::Render()
{
	testButton.Render();
}
