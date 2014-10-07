/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: numberDisplayer.cpp
 */

#include "numberDisplayer.h"

NumberDisplayer::NumberDisplayer(string picPath, uint8_t displayDigitalNum,
				uint16_t digitalWidth, uint16_t digitalHeight,
				 SDL_Renderer* renderer):
	numbers_("number.png", renderer, digitalWidth, digitalHeight),
	digitalNum_(displayDigitalNum)
{
	SetRenderer(renderer);

	/* Set rendering size of this displayer */
	SetSize(digitalWidth * displayDigitalNum, digitalHeight);

	/* Set vector size and init value */
	digitals_.resize(digitalNum_);

	SetZero();
}

NumberDisplayer::~NumberDisplayer()
{
	Release_();
}

void
NumberDisplayer::AddNum(uint32_t value)
{
	uint32_t toNext = 0;

	digitals_[digitalNum_- 1] += value;
	if (digitals_[digitalNum_ - 1] > 9) {
		digitals_[digitalNum_ - 1] -= 10;
		toNext = 1;
	}

	for (int i = digitalNum_ - 2; i >= 0; i--) {
		digitals_[i] += toNext;

		if (digitals_[i] > 9) {
			toNext = 1;
			digitals_[i] -= 10;
		} else {
			break;
		}
	}
}

void
NumberDisplayer::SetNum(int value)
{
	SDL_assert(value < pow(10, digitalNum_));
	for (int i = 0; i < digitalNum_; i++) {
		digitals_[i] = value / pow(10, digitalNum_ - 1 - i);
		value -= pow(10, digitalNum_ - 1 - i) * digitals_[i];
	}
}

uint64_t
NumberDisplayer::GetNum() const
{
	uint64_t toReturn = 0;

	for (int i = 0; i < digitals_.size(); i++)
		toReturn += (digitals_[i] * pow(10, digitals_.size() - i - 1));

	return toReturn;
}

void
NumberDisplayer::SetZero()
{
	for (auto& e: digitals_)
		e = 0;
}

void
NumberDisplayer::Render()
{
	for (int i = 0; i < digitalNum_; i++) {
		numbers_.MoveTo((rect_.x + numbers_.Width() * i), rect_.y);
		numbers_.JumpTo(digitals_[i]);
		numbers_.Render();
	}
}

void
NumberDisplayer::Release_()
{
}
