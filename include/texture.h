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
#include "renderable.h"

#include "toolBox.h"

using namespace std;

class Texture : public Renderable
{
	public:
		Texture();
		Texture(string filePath, const Window& window,
			Uint8 r = 0, Uint8 g = 255, Uint8 b = 255);
		~Texture();

		void LoadTexture(string filePath, const Window& window,
				Uint8 r = 0, Uint8 g = 255, Uint8 b = 255);
		void ReleaseTexture();

		void SetAlpha(Uint8 value);
		SDL_Texture* Object() const;

		void Render();
		void RenderFullWindow();
	private:
		SDL_Texture* texture_ = nullptr;
		Uint8 alpha_ = SDL_ALPHA_OPAQUE;
};

#endif	/* TEXTURE_H */
