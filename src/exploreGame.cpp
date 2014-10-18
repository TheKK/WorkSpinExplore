/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: exploreGame.cpp
 */

#include "exploreGame.h"

const static SDL_Rect viewport = {426, 0, 213, 360};

ExploreGame::ExploreGame(SDL_Renderer* renderer):
	backGroundPicture_("game/images/exploreGameBG.png", renderer),
	treasureCounter_("game/images/number.png", 4, 30, 30, renderer)
{
	/* Initialize according to viewport coordinate */
	backGroundPicture_.MoveTo(viewport.x, viewport.y);
	treasureCounter_.MoveTo(viewport.x, viewport.y);

	treasureCounter_.MoveBy(52, 320);

	renderableList_.push_back(&treasureCounter_);

	targetRenderer_ = renderer;

	/* DEBUG */
	treasureCounter_.SetNum(1000);
}

ExploreGame::~ExploreGame()
{
	Release_();
}

void
ExploreGame::EventHandler(const SDL_Event& event)
{
	switch (event.type) {
	case SDL_MOUSEBUTTONDOWN:
		UserEvent::Push(USEREVENT_EXPLO_QUEST);
		break;
	}

	if (event.type == UserEvent::ID[USEREVENT_EXPLO_COMFIRM])
		treasureCounter_.AddNum(1);
	if (event.type == UserEvent::ID[USEREVENT_EXPLO_REFUSE])
		SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION,
			     "Not enough monster");
}

void
ExploreGame::Update()
{
}

void
ExploreGame::Render()
{
	backGroundPicture_.Render();

	for (auto& e : renderableList_)
		e->Render();
}

void
ExploreGame::Release_()
{
}
