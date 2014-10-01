/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: spinGame.h
 */

#ifndef SPIN_GAME_H
#define SPIN_GAME_H

#include <iostream>
#include <random>
#include <SDL2/SDL.h>

#include "button.h"
#include "texture.h"
#include "numberDisplayer.h"

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
		/* Graphical objects */
		Texture backGroundPicture_;
		Texture spinPicture_;
		NumberDisplayer monsterCounter_;
		vector<Renderable*> renderableList_;

		SDL_Renderer* targetRenderer_ = nullptr;

		bool debugOff_ = true;

		void SpinSpin_(int16_t degree);

		void Release_();
};

#endif	/* SPIN_GAME_H */
