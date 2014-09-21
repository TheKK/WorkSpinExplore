/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: texture.cpp
 */

#include "texture.h"

Texture::Texture()
{
}

Texture::Texture(string filePath, const Window& window,
		 Uint8 r, Uint8 g, Uint8 b)
{
	LoadTexture(filePath, window, r, g, b);
}

Texture::~Texture()
{
	ReleaseTexture();
}

void
Texture::LoadTexture(string filePath, const Window& window,
		 Uint8 r, Uint8 g, Uint8 b)
{
	targetRenderer_ = window.GetRenderer();;
	texture_ = ToolBox::LoadTexture(filePath, window, r, g, b);

	rect_.x = 0;
	rect_.y = 0;
	SDL_QueryTexture(texture_, nullptr, nullptr, &rect_.w, &rect_.h);
}

void
Texture::ReleaseTexture()
{
	if (texture_ != nullptr)
		SDL_DestroyTexture(texture_);
	texture_ = nullptr;
}

void
Texture::Enlarge(int dw, int dh)
{
	rect_.w += dw;
	rect_.h += dh;
}

void
Texture::SetSize(unsigned int w, unsigned int h)
{
	rect_.w = w;
	rect_.h = h;
}

void
Texture::SetAlpha(int alpha)
{
	alpha_ = alpha;
	SDL_SetTextureAlphaMod(texture_, alpha_);
}

void
Texture::Move(int x, int y)
{
	rect_.x += x;
	rect_.y += y;
}

void
Texture::MoveXTo(int x)
{
	rect_.x = x;
}

void
Texture::MoveYTo(int y)
{
	rect_.y = y;
}

void
Texture::MoveTo(int x, int y)
{
	rect_.x = x;
	rect_.y = y;
}

int
Texture::PosX() const
{
	return rect_.x;
}


int
Texture::PosY() const
{
	return rect_.y;
}

int
Texture::Width() const
{
	return rect_.w;
}

int
Texture::Height() const
{
	return rect_.h;
}

SDL_Rect
Texture::Rect() const
{
	return rect_;
}

SDL_Texture*
Texture::Object() const
{
	return texture_;
}

void
Texture::Render()
{
	SDL_RenderCopy(targetRenderer_, texture_, nullptr, &rect_);
}

void
Texture::RenderFullWindow()
{
	SDL_RenderCopy(targetRenderer_, texture_, nullptr, nullptr);
}
