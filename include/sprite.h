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

#include "toolBox.h"

using namespace std;

class Sprite
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

		void Enlarge(int dw, int dh);
		void SetSize(unsigned int w, unsigned int h);
		void SetAlpha(int alpha);

		void Move(int x, int y);
		void MoveXTo(int x);
		void MoveYTo(int y);
		void MoveTo(int x, int y);

		int PosX();
		int PosY();
		int Width();
		int Height();
		SDL_Rect Rect();
		SDL_Texture* Object();

		void Render();
		void RenderFullWindow();

		void NextFrame();
		void PrevFrame();
		void JumpTo(int where);
	private:
		SDL_Texture* sheet_ = nullptr;
		SDL_Rect pos_;
		vector<SDL_Rect> clip_;
		SDL_Renderer* targetRenderer_ = nullptr;

		/*
		 * Use to store the number of frame
		 */
		int totalFrame_;

		/*
		 * Tell you which frame will show. Start from 0.
		 */
		int currentFrame_ = 0;

		int alpha_ = SDL_ALPHA_OPAQUE;
};

#endif	/* SPRITE_H */
