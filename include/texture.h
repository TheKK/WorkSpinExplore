/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: texture.h
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <functional>
#include <string>
#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "window.h"

#include "toolBox.h"

using namespace std;

class Texture
{
	public:
		Texture();
		Texture(string filePath, const Window& window,
			Uint8 r = 0, Uint8 g = 255, Uint8 b = 255);
		~Texture();

		void LoadTexture(string filePath, const Window& window,
				Uint8 r = 0, Uint8 g = 255, Uint8 b = 255);
		void ReleaseTexture();

		void Enlarge(int dw, int dh);
		void SetSize(unsigned int w, unsigned int h);
		void SetAlpha(int alpha);

		void Move(int x, int y);
		void MoveXTo(int x);
		void MoveYTo(int y);
		void MoveTo(int x, int y);

		int PosX() const;
		int PosY() const;
		int Width() const;
		int Height() const;
		SDL_Rect Rect() const;
		SDL_Texture* Object() const;

		void Render();
		void RenderFullWindow();
	private:
		SDL_Texture* texture_ = nullptr;
		SDL_Rect rect_;
		SDL_Renderer* targetRenderer_ = nullptr;

		int alpha_ = SDL_ALPHA_OPAQUE;
};

#endif	/* TEXTURE_H */
