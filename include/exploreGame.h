/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: spinGame.h
 */

#ifndef EXPLORE_GAME_H
#define EXPLORE_GAME_H

#include <iostream>
#include <SDL2/SDL.h>

#include "button.h"
#include "texture.h"
#include "widget.h"

using namespace std;

class ExploreGame : public Widget
{
	public:
		ExploreGame(SDL_Renderer* renderer);
		~ExploreGame();

		void EventHandler(const SDL_Event& event);
		void Update();
		void Render();
	private:
		/* Graphic */
		Texture backGroundPicture_;

		SDL_Renderer* targetRenderer_ = nullptr;

		/* Private functions */
		void Release_();
};

#endif	/* EXPLORE_GAME_H */
