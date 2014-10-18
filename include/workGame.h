/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: workGame.h
 */

#ifndef WORK_GAME_H
#define WORK_GAME_H

#include <iostream>
#include <SDL2/SDL.h>

#include "widget.h"
#include "button.h"
#include "numberDisplayer.h"
#include "sound.h"
#include "texture.h"
#include "userEvent.h"

using namespace std;

class WorkGame : public Widget
{
	public:
		WorkGame(SDL_Renderer* renderer);
		~WorkGame();

		void EventHandler(const SDL_Event& event);
		void Update();
		void Render();
	private:
		/* Graphic */
		vector<Renderable*> renderableList_;
		Texture backGroundPicture_;
		NumberDisplayer moneyCounter_;

		/* Sound */
		Sound buttonSound_;

		/* Private functions */
		void Scratch_(const SDL_Event& event);

		/*
		 * This function is not avaliable in sdl2.0.3 so I made
		 * my own implement.
		 */
		SDL_bool SDL_PointInRect(const SDL_Point* p, const SDL_Rect* r);

		void Release_();
};

#endif	/* WORK_GAME_H */
