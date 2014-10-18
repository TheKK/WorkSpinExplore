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
#include "numberDisplayer.h"
#include "sound.h"
#include "texture.h"
#include "userEvent.h"
#include "widget.h"

using namespace std;

class SpinGame : public Widget
{
	public:
		SpinGame(SDL_Renderer* renderer);
		~SpinGame();

		void EventHandler(const SDL_Event& event);
		void Update();
		void Render();
	private:
		/* Graphic */
		vector<Renderable*> renderableList_;
		Texture backGroundPicture_;
		Texture spinPicture_;
		NumberDisplayer monsterCounter_;

		/* Sound */
		Sound spinSound_;

		/* Private functions */
		void SpinSpin_(int16_t degree);

		void Release_();
};

#endif	/* SPIN_GAME_H */
