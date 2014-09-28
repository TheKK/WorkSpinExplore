/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: textLabel.cpp
 */

#include "textLabel.h"

TextLabel::TextLabel()
{
}

TextLabel::TextLabel(string fontPath, int fontSize, string text,
		     SDL_Color color, SDL_Renderer* renderer)
{
	SetRenderer(renderer);
	OpenFont(fontPath, fontSize);
	SetText(text);
	SetColor(color);
	RenderToTexture();
}

TextLabel::~TextLabel()
{
	CloseFont();
	ReleaseTexture();
}

void
TextLabel::OpenFont(string fontPath, int fontSize)
{
	string basePath = SDL_GetBasePath();

	font_ = TTF_OpenFont((basePath + fontPath).c_str(), fontSize);
	if (font_ == nullptr) {
		string errMsg("Error while open font_: ");
		errMsg += TTF_GetError();
		throw runtime_error(errMsg);
	}
}

void
TextLabel::CloseFont()
{
	if (font_ != nullptr)
		TTF_CloseFont(font_);
	font_ = nullptr;
}

void
TextLabel::RenderToTexture()
{
	SDL_Surface* tmpSurface = nullptr;
	SDL_Texture* tex = nullptr;

	/* Rendering */
	tmpSurface = TTF_RenderText_Blended_Wrapped(font_, text_.c_str(),
						    color_, lineWidth_);
	if (tmpSurface == nullptr) {
		string errMsg("Error while rendering font_: ");
		errMsg += TTF_GetError();
		throw runtime_error(errMsg);
	}

	/* Converting */
	tex = SDL_CreateTextureFromSurface(targetRenderer_, tmpSurface);
	if (tex == nullptr) {
		string errMsg("Error while converting surface: ");
		errMsg += SDL_GetError();
		throw runtime_error(errMsg);
	}

	SDL_FreeSurface(tmpSurface);
	tmpSurface = nullptr;

	/* Update data */
	texture_ = tex;

	SDL_QueryTexture(texture_, nullptr, nullptr, &rect_.w, &rect_.h);
}

void
TextLabel::ReleaseTexture()
{
	if (texture_ != nullptr)
		SDL_DestroyTexture(texture_);
	texture_ = nullptr;
}

void
TextLabel::SetText(string text)
{
	text_ = text;
}

void
TextLabel::SetLineWidth(int width)
{
}

void
TextLabel::SetColor(SDL_Color color)
{
	color_ = color;
}
void
TextLabel::Render()
{
	SDL_RenderCopy(targetRenderer_, texture_, nullptr, &rect_);
}
