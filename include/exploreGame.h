/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: spinGame.h
 */

#ifndef EXPLORE_GAME_H
#define EXPLORE_GAME_H

#include <iostream>
#include <SDL2/SDL.h>

#include "texture.h"
#include "button.h"

using namespace std;

class ExploreGame
{
	public:
		ExploreGame(SDL_Renderer* renderer);
		~ExploreGame();

		void EventHandler(const SDL_Event& event);
		void Update();
		void Render();
	private:
		Texture backGroundPicture_;

		SDL_Renderer* targetRenderer_ = nullptr;

		void Release_();
};

#endif	/* EXPLORE_GAME_H */
