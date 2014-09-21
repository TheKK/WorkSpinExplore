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
#include <cstdio>
#include <SDL2/SDL.h>

#include "workGame.h"
#include "spinGame.h"
#include "exploreGame.h"
#include "window.h"
#include "timer.h"
#include "achievementBar.h"

#define GAME_FPS	60

using namespace std;

class Game
{
	public:
		Game();
		~Game();

		void Execute();
	private:
		Window mainWindow_;

		WorkGame workGame_;
		//SpinGame spinGame_;
		//ExploreGame exploreGame_;

		bool appIsRunning_;

		void EventHandler_(const SDL_Event& event);
		void Update_();
		void Render_();

		void Release_();
};

#endif	/* GAME_H */
