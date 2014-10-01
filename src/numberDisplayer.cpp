/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: numberDisplayer.cpp
 */

#include "numberDisplayer.h"

NumberDisplayer::NumberDisplayer(SDL_Renderer* renderer):
	numbers_("number.png", renderer, 30, 30)
{
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = 120;
	rect_.h = 30;
	numbers_.SetSize(rect_.w / DISPLAY_NUMBER, rect_.h);
}

NumberDisplayer::~NumberDisplayer()
{
}

void
NumberDisplayer::AddNum(Uint8 value)
{
	assert(value < 10);

	Uint8 toNext = 0;

	displayValue_[DISPLAY_NUMBER - 1] += value;
	if (displayValue_[DISPLAY_NUMBER - 1] > 9) {
		displayValue_[DISPLAY_NUMBER - 1] -= 10;
		toNext = 1;
	}

	for (int i = DISPLAY_NUMBER - 2; i >= 0; i--) {
		displayValue_[i] += toNext;

		if (displayValue_[i] > 9) {
			toNext = 1;
			displayValue_[i] -= 10;
		} else {
			break;
		}
	}
}

void
NumberDisplayer::SetNum(int value)
{
	assert(value < pow(10, DISPLAY_NUMBER));
	for (int i = 0; i < DISPLAY_NUMBER; i++) {
		displayValue_[i] = value / pow(10, DISPLAY_NUMBER - 1 - i);
		value -= pow(10, DISPLAY_NUMBER - 1 - i) *displayValue_[i];
	}
}

void
NumberDisplayer::Render()
{
	for (int i = 0; i < DISPLAY_NUMBER; i++) {
		numbers_.MoveTo((rect_.x + numbers_.Width() * i), rect_.y);
		numbers_.JumpTo(displayValue_[i]);
		numbers_.Render();
	}
}
