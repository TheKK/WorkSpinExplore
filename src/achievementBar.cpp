/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: achievementBar.cpp
 */

#include "achievementBar.h"

AchievementBar::AchievementBar()
{
}

AchievementBar::AchievementBar(string barPicPath, vector<string> iconPath,
			       vector<string> texts, const Window& window)
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
	/* Loading */
	barBackground_.LoadTexture(barPicPath, window);

	for (int i = 0; i < ACHIEVEMENT_NUM; i++)
		icons_.push_back(new Texture(iconPath[i], window));

	texts_ = texts;

	/* Set position */
	barBackground_.MoveTo(
		(window.Width() - barBackground_.Width()) / 2, 30);

	for (auto& e : icons_)
		e->MoveTo(barBackground_.PosX() + 4, barBackground_.PosY() + 4);

	/* Setup textlabel */
	textLabel_.OpenFont("hachicro/hachicro.TTF", 10);
	textLabel_.SetRenderer(window.GetRenderer());
	textLabel_.SetText("nothing");
	textLabel_.SetColor({0, 0, 0, 255});
	textLabel_.RenderToTexture();
	textLabel_.MoveTo(barBackground_.PosX() + 46,
			  barBackground_.PosY() + 4);

	/* Set renderer */
	targetRenderer_ = window.GetRenderer();
}

void
AchievementBar::EventHandler(const SDL_Event& event)
{
	switch (event.type) {
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_e:
			textLabel_.ReleaseTexture();
			textLabel_.SetText(texts_[ACHIEVEMENT_TEST]);
			textLabel_.RenderToTexture();
			break;
		}
	}
}

void
AchievementBar::Update()
{
}

void
AchievementBar::Render()
{
	barBackground_.Render();
	icons_[ACHIEVEMENT_TEST]->Render();
	textLabel_.Render();
}

void
AchievementBar::Release_()
{
	for (Texture* e : icons_)
		delete e;
}
