/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: exploreGame.cpp
 */

#include "exploreGame.h"

const static SDL_Rect viewport = {426, 0, 213, 360};

ExploreGame::ExploreGame(const Window& window):
	testButton("normal.png", "hover.png", "push.png", window)
{
	targetRenderer_ = window.GetRenderer();
	testButton.Move(viewport.x, viewport.y);
}

ExploreGame::~ExploreGame()
{
}

void
ExploreGame::EventHandler(const SDL_Event& event)
{
	switch (event.type) {
	}
	testButton.EventHandler(event);
}

void
ExploreGame::Update()
{
	testButton.Update();
}

void
ExploreGame::Render()
{
	testButton.Render();
}
