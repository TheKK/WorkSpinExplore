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

#include "window.h"
#include "texture.h"
#include "textLabel.h"

#include "toolBox.h"

using namespace std;

enum Achievements {
	ACHIEVEMENT_TEST = 0,
	ACHIEVEMENT_NUM
};

class AchievementBar
{
	public:
		AchievementBar();
		AchievementBar(string barPicPath, vector<string> iconPath,
			       vector<string> texts, const Window& window);
		~AchievementBar();

		void Load(string barPicPath, vector<string>& iconPath,
			  vector<string>& texts, const Window& window);

		void EventHandler(const SDL_Event& event);
		void Update();
		void Render();
	private:
		Texture barBackground_;
		TextLabel textLabel_;

		vector<Texture*> icons_;
		vector<string> texts_;

		SDL_Renderer* targetRenderer_ = nullptr;

		void Release_();
};

#endif	/* ACHIEVEMTNT_BAR_H */
