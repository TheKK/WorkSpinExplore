/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: exploreGame.cpp
 */

#include "exploreGame.h"

const static SDL_Rect viewport = {426, 0, 213, 360};

ExploreGame::ExploreGame(SDL_Renderer* renderer):
	backGroundPicture_("exploreGameBG.png", renderer)
{
	targetRenderer_ = renderer;

	backGroundPicture_.MoveTo(viewport.x, viewport.y);
}

ExploreGame::~ExploreGame()
{
}

void
ExploreGame::EventHandler(const SDL_Event& event)
{
	switch (event.type) {
	}
}

void
ExploreGame::Update()
{
}

void
ExploreGame::Render()
{
	backGroundPicture_.Render();
}
