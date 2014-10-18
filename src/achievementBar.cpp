/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: achievementBar.cpp
 */

#include "achievementBar.h"

AchievementBar::AchievementBar(string barPicPath, SDL_Renderer* renderer):
	barBackground_(barPicPath, renderer),
	achiUnlockSE_("./game/sounds/achiUnlockSE.ogg")
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
	int width;
	vector<string> iconPath;

	/* Set Background image and set position */
	SDL_RenderGetLogicalSize(renderer,&width, nullptr);
	barBackground_.MoveTo((width - barBackground_.Width()) / 2, 30);

	/* Loading icons */
	iconPath.emplace_back(string("game/images/achievementIcon1.png"));
	iconPath.emplace_back(string("game/images/achievementIcon1.png"));
	SDL_assert_paranoid(iconPath.size() == ACHIEVEMENT_COUNT);

	icons_.resize(ACHIEVEMENT_COUNT);
	for (int i = 0; i < ACHIEVEMENT_COUNT; i++)
		icons_[i].Load(iconPath[i], renderer);

	for (auto& e : icons_)
		e.MoveTo(barBackground_.PosX() + 4, barBackground_.PosY() + 4);

	/* Loading texts */
	texts_.emplace_back(string("This is a test"));
	texts_.emplace_back(string("Click mouse 20 times!"));
	SDL_assert_paranoid(texts_.size() == ACHIEVEMENT_COUNT);

	targetRenderer_ = renderer;
}

void
AchievementBar::EventHandler(const SDL_Event& event)
{
	if (isPaused_)
		return;

	switch (event.type) {
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_e:
			SendJob(ACHIEVEMENT_TEST);
			break;
		}
		break;
	}
}

void
AchievementBar::Update()
{
	if (isPaused_)
		return;

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

		e.text->SetAlpha(e.alpha);
		e.text->MoveYTo(e.barPosY);

		barBackground_.Render();
		e.pic->Render();
		e.text->Render();
	}
}

void
AchievementBar::Pause()
{
	isPaused_ = true;
	PauseAllSound_();
}

void
AchievementBar::Unpause()
{
	isPaused_ = false;
	ResumeAllSound_();
}

void
AchievementBar::SendJob(enum Achievements which)
{
	struct AchievementMsg msg;
	SDL_Color textColor = {0, 0, 0, 255};

	msg.pic = &icons_[which];
	msg.text = new TextLabel("minecraftia/Minecraftia-Regular.ttf", 11,
				 texts_[which], &textColor, targetRenderer_);
	msg.text->MoveTo(barBackground_.PosX() + 46,
			  barBackground_.PosY() + 4);

	jobQueue_.push_back(msg);

	achiUnlockSE_.Play();
}

void
AchievementBar::PauseAllSound_()
{
	if (achiUnlockSE_.IsPlaying())
		achiUnlockSE_.Pause();
	cout << "Pause" << endl;
}

void
AchievementBar::ResumeAllSound_()
{
	if (achiUnlockSE_.IsPaused())
		achiUnlockSE_.Play();
	cout << "Resume" << endl;
}

void
AchievementBar::Release_()
{
	for (struct AchievementMsg e : jobQueue_)
				       delete e.text;
}
