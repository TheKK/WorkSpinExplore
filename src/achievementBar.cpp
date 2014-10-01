/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: achievementBar.cpp
 */

#include "achievementBar.h"

#define GAME_FPS	60
#define GAME_WIDTH	640
#define GAME_HEIGHT	360

AchievementBar::AchievementBar()
{
}

AchievementBar::AchievementBar(string barPicPath, SDL_Renderer* renderer)
{
	Load(barPicPath, renderer);
}

AchievementBar::~AchievementBar()
{
	Release_();
}

void
AchievementBar::Load(string barPicPath, SDL_Renderer* renderer)
{
	//TODO: Improve this
	vector<string> iconPath;
	vector<string> texts;

	iconPath.emplace_back(string("achievementIcon1.png"));
	iconPath.emplace_back(string("achievementIcon1.png"));

	texts.emplace_back(string("This is a test"));
	texts.emplace_back(string("Click mouse 20 times!"));
	//END OF TODO

	assert(iconPath.size() == ACHIEVEMENT_COUNT);
	assert(texts.size() == ACHIEVEMENT_COUNT);

	/* Loading */
	barBackground_.LoadTexture(barPicPath, renderer);

	for (int i = 0; i < ACHIEVEMENT_COUNT; i++)
		icons_.push_back(new Texture(iconPath[i], renderer));

	texts_ = texts;

	/* Set position */
	barBackground_.MoveTo((GAME_WIDTH - barBackground_.Width()) / 2, 30);

	for (auto& e : icons_)
		e->MoveTo(barBackground_.PosX() + 4, barBackground_.PosY() + 4);

	targetRenderer_ = renderer;
}

void
AchievementBar::EventHandler(const SDL_Event& event)
{
	switch (event.type) {
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_e:
			SendJob(ACHIEVEMENT_TEST);
			break;
		case SDLK_r:
			break;
		}
	}
}

void
AchievementBar::Update()
{
	/* Update jobs' position according to their "frame" */
	for (auto& e : jobQueue_) {
		e.frame++;

		if (e.frame > 180) {
			e.shouldDie = true;
		} else if (e.frame > 120) {
			e.alpha =
				(180.0 - e.frame) / 60.0 * SDL_ALPHA_OPAQUE;
			e.pic->SetAlpha(e.alpha);
			e.barPosY = 30.0 * e.alpha / SDL_ALPHA_OPAQUE;
		} else if (e.frame > 60) {
			e.alpha = SDL_ALPHA_OPAQUE;
			e.pic->SetAlpha(e.alpha);
		} else if (e.frame > 0) {
			e.alpha = e.frame / 60.0 * SDL_ALPHA_OPAQUE;
			e.pic->SetAlpha(e.alpha);
			e.barPosY = 30.0 * e.alpha / SDL_ALPHA_OPAQUE;
		}
	}

	/* Kill someone should die */
	while (jobQueue_.size() && jobQueue_.front().shouldDie) {
		delete jobQueue_.front().text;
		jobQueue_.erase(jobQueue_.begin());
	}
}

void
AchievementBar::Render()
{
	for (auto& e : jobQueue_) {
		barBackground_.SetAlpha(e.alpha);
		barBackground_.MoveYTo(e.barPosY);

		e.pic->SetAlpha(e.alpha);
		e.pic->MoveYTo(e.barPosY);

		e.text->MoveYTo(e.barPosY);

		barBackground_.Render();
		e.pic->Render();
		e.text->Render();
	}
}

void
AchievementBar::SendJob(enum Achievements which)
{
	struct AchievementMsg msg;
	SDL_Color textColor = {0, 0, 0, 255};

	msg.pic = icons_[which];
	msg.text = new TextLabel("minecraftia/Minecraftia-Regular.ttf", 11,
				 texts_[which], textColor, targetRenderer_);
	msg.text->MoveTo(barBackground_.PosX() + 46,
			  barBackground_.PosY() + 4);

	jobQueue_.push_back(msg);
}

void
AchievementBar::Release_()
{
	for (Texture* e : icons_)
		delete e;

	for (struct AchievementMsg e : jobQueue_)
	       delete e.text;
}
