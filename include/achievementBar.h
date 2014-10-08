/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: achievementBar.h
 */

#ifndef ACHIEVEMENT_BAR_H
#define ACHIEVEMENT_BAR_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "texture.h"
#include "textLabel.h"

#include "toolBox.h"

using namespace std;

enum Achievements
{
	ACHIEVEMENT_TEST = 0,
	ACHIEVEMENT_MOUSE_CLICK_20,
	ACHIEVEMENT_COUNT
};

struct AchievementMsg
{
	Texture* pic = nullptr;
	TextLabel* text = nullptr;
	int barPosY = 0;
	Uint8 alpha = SDL_ALPHA_TRANSPARENT;
	int frame = 0;
	bool shouldDie = false;
};

class AchievementBar
{
	public:
		AchievementBar(string barPicPath, SDL_Renderer* renderer);
		~AchievementBar();

		void Load(string barPicPath, SDL_Renderer* renderer);

		void EventHandler(const SDL_Event& event);
		void Update();
		void Render();

		void SendJob(enum Achievements which);
	private:
		Texture barBackground_;

		vector<Texture> icons_;
		vector<string> texts_;

		vector<struct AchievementMsg> jobQueue_;

		SDL_Renderer* targetRenderer_ = nullptr;

		void Release_();
};

#endif	/* ACHIEVEMTNT_BAR_H */
