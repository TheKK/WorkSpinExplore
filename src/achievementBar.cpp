/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: achievementBar.cpp
 */

#include "achievementBar.h"

#define GAME_FPS	60

AchievementBar::AchievementBar()
{
}

AchievementBar::AchievementBar(string barPicPath, vector<string>& iconPath,
			       vector<string>& texts, const Window& window)
{
	Load(barPicPath, iconPath, texts, window);
}

AchievementBar::~AchievementBar()
{
	Release_();
}

void
AchievementBar::Load(string barPicPath, vector<string>& iconPath,
		     vector<string>& texts, const Window& window)
{
	assert(iconPath.size() == ACHIEVEMENT_COUNT);
	assert(texts.size() == ACHIEVEMENT_COUNT);

	/* Loading */
	barBackground_.LoadTexture(barPicPath, window);

	for (int i = 0; i < ACHIEVEMENT_COUNT; i++)
		icons_.push_back(new Texture(iconPath[i], window));

	texts_ = texts;

	/* Set position */
	barBackground_.MoveTo(
		(window.Width() - barBackground_.Width()) / 2, 30);

	for (auto& e : icons_)
		e->MoveTo(barBackground_.PosX() + 4, barBackground_.PosY() + 4);

	targetRenderer_ = window.GetRenderer();
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
	for (auto& e : jobQueue) {
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

	while (jobQueue.size() && jobQueue.front().shouldDie) {
		delete jobQueue.front().text;
		jobQueue.erase(jobQueue.begin());
	}
}

void
AchievementBar::Render()
{
	for (auto& e : jobQueue) {
		barBackground_.SetAlpha(e.alpha);
		barBackground_.MoveYTo(e.barPosY);

		e.pic->SetAlpha(e.alpha);
		e.pic->MoveYTo(e.barPosY);

		e.text->MoveYTo(e.barPosY);

		barBackground_.Render();
		e.pic->Render();
		e.text->Render();
	}
	//barBackground_.Render();
	//icons_[ACHIEVEMENT_TEST]->Render();
	//textLabel_.Render();
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

	jobQueue.push_back(msg);
}

void
AchievementBar::Release_()
{
	for (Texture* e : icons_)
		delete e;
}
