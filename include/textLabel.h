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

using namespace std;

class TextLabel
{
	public:
		TextLabel();
		TextLabel(string fontPath, int fontSize, string text,
			  SDL_Color color, Window& targetWindow);
		~TextLabel();

		void OpenFont(string fontPath, int fontSize);
		void CloseFont();
		void RenderToTexture();
		void ReleaseTexture();

		void SetText(string text);
		void SetSize(int w, int h);
		void SetColor(SDL_Color color);
		void SetAlpha(int alpha);
		void SetRenderer(SDL_Renderer* renderer);

		void Move(int x, int y);
		void MoveXTo(int x);
		void MoveYTo(int y);
		void MoveTo(int x, int y);

		int PosX();
		int PosY();
		int Width();
		int Height();
		SDL_Rect Rect();

		void Render();
		void RenderFullWindow();
	private:
		SDL_Texture* texture_ = nullptr;
		SDL_Rect rect_ = {0, 0, 0, 0};

		TTF_Font* font_ = nullptr;
		string text_;
		SDL_Color color_;

		SDL_Renderer* targetRenderer_ = nullptr;

		int alpha_ = SDL_ALPHA_OPAQUE;
};

#endif	/* TEXT_TABLE_H */
