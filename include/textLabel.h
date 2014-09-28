/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: textLabel.h
 */

#ifndef TEXT_LABEL_H
#define TEXT_LABEL_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <cassert>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "window.h"
#include "renderable.h"

using namespace std;

class TextLabel : public Renderable
{
	public:
		TextLabel();
		TextLabel(string fontPath, int fontSize, string text,
			  SDL_Color color, SDL_Renderer* renderer);
		~TextLabel();

		void OpenFont(string fontPath, int fontSize);
		void CloseFont();
		void RenderToTexture();
		void ReleaseTexture();

		void SetText(string text);
		void SetLineWidth(int width);
		void SetColor(SDL_Color color);

		void Render();
	private:
		SDL_Texture* texture_ = nullptr;

		TTF_Font* font_ = nullptr;
		string text_;
		SDL_Color color_;

		int lineWidth_ = 300;
};

#endif	/* TEXT_TABLE_H */
