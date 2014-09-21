/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: sprite.cpp
 */

#include "sprite.h"

Sprite::Sprite()
{
}

Sprite::Sprite(string filePath, Window& targetWindow,
	       int w, int h,
	       Uint8 r, Uint8 g, Uint8 b)
{
	LoadSheet(filePath, targetWindow, w, h, r, g, b);
}

Sprite::~Sprite()
{
	ReleaseSheet();
}

int
Sprite::LoadSheet(string filePath, Window& targetWindow,
	       int w, int h,
	       Uint8 r, Uint8 g, Uint8 b)
{
	/* Set default target renderer */
	targetRenderer_ = targetWindow.GetRenderer();

	/* Load and convert image */
	SDL_Surface* loadedImage = nullptr;
	//string basePath = SDL_GetBasePath();

	loadedImage = IMG_Load(filePath.c_str());
	if (loadedImage == nullptr) {
		fprintf(stderr, "SDL error while loading \"%s\": %s\n",
			filePath.c_str(), IMG_GetError());
		return -1;
	}

	SDL_SetColorKey(loadedImage, SDL_TRUE,
			SDL_MapRGB(loadedImage->format, r, g, b));

	if (sheet_ != nullptr)
		ReleaseSheet();

	sheet_ = SDL_CreateTextureFromSurface(targetRenderer_, loadedImage);
	if (sheet_ == nullptr) {
		fprintf(stderr,
			"SDL error while convering surface into texture: %s\n",
			SDL_GetError());
		return -1;
	}

	pos_.x = 0;
	pos_.y = 0;
	pos_.w = w;
	pos_.h = h;

	/* Setup clip for each frame and other stuffs*/
	totalFrame_= loadedImage->w / w;
	SDL_Rect toBePushed;
	toBePushed.y = 0;
	toBePushed.w = w;
	toBePushed.h = h;
	for (int i = 0; i <= totalFrame_; i++) {
		toBePushed.x = i * w;
		clip_.push_back(toBePushed);
	}

	SDL_FreeSurface(loadedImage);
	loadedImage = nullptr;

	return 0;
}

void
Sprite::ReleaseSheet()
{
	if (sheet_ != nullptr)
		SDL_DestroyTexture(sheet_);
	sheet_ = nullptr;
}

void
Sprite::Enlarge(int dw, int dh)
{
	pos_.w += dw;
	pos_.h += dh;
}

void
Sprite::SetSize(unsigned int w, unsigned int h)
{
	pos_.w = w;
	pos_.h = h;
}

void
Sprite::SetAlpha(int alpha)
{
	alpha_ = alpha;
	SDL_SetTextureAlphaMod(sheet_, alpha_);
}

void
Sprite::Move(int x, int y)
{
	pos_.x += x;
	pos_.y += y;
}

void
Sprite::MoveXTo(int x)
{
	pos_.x = x;
}

void
Sprite::MoveYTo(int y)
{
	pos_.y = y;
}

void
Sprite::MoveTo(int x, int y)
{
	pos_.x = x;
	pos_.y = y;
}

int
Sprite::PosX()
{
	return pos_.x;
}


int
Sprite::PosY()
{
	return pos_.y;
}

int
Sprite::Width()
{
	return pos_.w;
}

int
Sprite::Height()
{
	return pos_.h;
}

SDL_Rect
Sprite::Rect()
{
	return pos_;
}

SDL_Texture*
Sprite::Object()
{
	return sheet_;
}

void
Sprite::Render()
{
	SDL_RenderCopy(targetRenderer_, sheet_, &clip_[currentFrame_], &pos_);
}

void
Sprite::RenderFullWindow()
{
	SDL_RenderCopy(targetRenderer_, sheet_, &clip_[currentFrame_], nullptr);
}

void
Sprite::NextFrame()
{
	currentFrame_++;
	if (currentFrame_ == totalFrame_)
		currentFrame_ = 0;
}

void
Sprite::PrevFrame()
{
	currentFrame_--;
	if (currentFrame_ < 0)
		currentFrame_ = totalFrame_ - 1;
}

void
Sprite::JumpTo(int where)
{
	currentFrame_ = where;
}
