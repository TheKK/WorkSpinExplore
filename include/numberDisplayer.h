/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: numberDisplayer.h
 */

#ifndef NUMBER_DISPLAYER_H
#define NUMBER_DISPLAYER_H

#include <iostream>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "sprite.h"
#include "renderable.h"

#include "toolBox.h"

#define DISPLAY_NUMBER	4

using namespace std;

class NumberDisplayer : public Renderable
{
	public:
		NumberDisplayer(SDL_Renderer* renderer);
		~NumberDisplayer();

		void Render();

		void AddNum(Uint8 value);
		void SetNum(int value);
	private:
		Sprite numbers_;
		Uint8 displayValue_[DISPLAY_NUMBER] = {1, 2, 3, 4};

		void Release_();
};

#endif	/* NUMBER_DISPLAYER_H */
