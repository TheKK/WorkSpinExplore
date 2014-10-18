/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: game.h
 */

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <SDL2/SDL.h>

#include "achievementBar.h"
#include "exploreGame.h"
#include "sound.h"
#include "spinGame.h"
#include "timer.h"
#include "userEvent.h"
#include "window.h"
#include "workGame.h"

#define GAME_FPS	60

using namespace std;

class Game
{
	public:
		Game();
		~Game();

		void Execute();
	private:
		/* State */
		bool appIsRunning_ = true;
		bool appIsPaused_ = false;

		/* Window */
		Window mainWindow_;

		/* Widget */
		WorkGame workGame_;
		SpinGame spinGame_;
		ExploreGame exploreGame_;

		AchievementBar achiBar_;

		/* Graphic */
		Texture hand_;
		Texture screenBorder_;
		Texture pauseBG_;

		/* Sound */
		Sound pauseSE_;

		/* Private functions */
		void EventHandler_(const SDL_Event& event);
		void Update_();
		void Render_();

		void TogglePause_();
		void ScreenShot_();

		void Release_();
};

#endif	/* GAME_H */
