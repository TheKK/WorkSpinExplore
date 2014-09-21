/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: workGame.h
 */

#ifndef WORK_GAME_H
#define WORK_GAME_H

#include <iostream>
#include <SDL2/SDL.h>

#include "window.h"
#include "texture.h"
#include "button.h"
#include "numberDisplayer.h"

using namespace std;

class WorkGame
{
	public:
		WorkGame(const Window& window);
		~WorkGame();

		void EventHandler(const SDL_Event& event);
		void Update();
		void Render();
	private:
		Button testButton;
		NumberDisplayer numDisplayer_;
		SDL_Renderer* targetRenderer_;

		void Release_();
};

#endif	/* WORK_GAME_H */
