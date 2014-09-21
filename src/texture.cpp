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
