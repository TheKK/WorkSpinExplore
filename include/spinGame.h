/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: spinGame.h
 */

#ifndef SPIN_GAME_H
#define SPIN_GAME_H

#include <iostream>
#include <SDL2/SDL.h>

#include "texture.h"
#include "button.h"

using namespace std;

class SpinGame
{
	public:
		SpinGame(SDL_Renderer* renderer);
		~SpinGame();

		void EventHandler(const SDL_Event& event);
		void Update();
		void Render();
	private:
		Texture backGroundPicture_;
		Texture spinPicture_;

		SDL_Renderer* targetRenderer_ = nullptr;

		void Release_();
};

#endif	/* SPIN_GAME_H */
