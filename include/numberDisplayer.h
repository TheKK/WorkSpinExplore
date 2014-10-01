/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: numberDisplayer.h
 */

#ifndef NUMBER_DISPLAYER_H
#define NUMBER_DISPLAYER_H

#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "sprite.h"
#include "renderable.h"

#include "toolBox.h"

using namespace std;

class NumberDisplayer : public Renderable
{
	public:
		NumberDisplayer(string picPath, uint8_t displayDigitalNum,
				uint16_t digitalWidth, uint16_t digitalHeight,
				SDL_Renderer* renderer);
		~NumberDisplayer();

		void Render();

		void AddNum(uint32_t value);
		void SetNum(int value);
		uint64_t GetNum() const;
	private:
		Sprite numbers_;

		vector<uint8_t> digitals_;
		uint16_t digitalNum_;

		void Release_();
};

#endif	/* NUMBER_DISPLAYER_H */
