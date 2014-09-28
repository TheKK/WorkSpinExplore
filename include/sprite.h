/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: sprite.h
 */

#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "window.h"
#include "renderable.h"

#include "toolBox.h"

using namespace std;

class Sprite : public Renderable
{
	public:
		Sprite();
		Sprite(string filePath, const Window& window,
		       int w, int h,
		       Uint8 r = 0, Uint8 g = 255, Uint8 = 255);
		~Sprite();

		int LoadSheet(string filePath, const Window& window,
			      int w, int h,
			      Uint8 r = 0, Uint8 g = 255, Uint8 = 255);
		void ReleaseSheet();

		SDL_Texture* Object();

		void Render();
		void RenderFullWindow();

		void NextFrame();
		void PrevFrame();
		void JumpTo(int where);
	private:
		SDL_Texture* sheet_ = nullptr;
		vector<SDL_Rect> clip_;

		/*
		 * Use to store the number of frame
		 */
		int totalFrame_;

		/*
		 * Tell you which frame will show. Start from 0.
		 */
		int currentFrame_ = 0;
};

#endif	/* SPRITE_H */
