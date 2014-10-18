/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: mainGameState.h
 */

#ifndef MAIN_GAME_STATE_H
#define MAIN_GAME_STATE_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <SDL2/SDL.h>

#include "achievementBar.h"
#include "exploreGame.h"
#include "gameState.h"
#include "sound.h"
#include "spinGame.h"
#include "timer.h"
#include "userEvent.h"
#include "widget.h"
#include "window.h"
#include "workGame.h"

using namespace std;

class MainGameState : public GameState
{
	public:
		MainGameState();
		~MainGameState();

		void EventHandler(const SDL_Event& event);
		void Update();
		void Render();
	private:
		/* State */
		bool appIsPaused_ = false;

		/* Window */
		Window mainWindow_;

		/* Widget */
		vector<Widget*> widgetList_;
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
		void TogglePause_();
		void ScreenShot_();

		void Release_();
};

#endif	/* MAIN_GAME_STATE_H */
