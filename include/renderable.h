/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: renderable.h
 */

#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class Renderable
{
	public:
		Renderable();
		virtual ~Renderable();
		virtual void Render() = 0;

		void Enlarge(int dw, int dh);
		void SetSize(unsigned int w, unsigned int h);
		void SetRenderer(SDL_Renderer* renderer);

		void Move(int x, int y);
		void MoveXTo(int x);
		void MoveYTo(int y);
		void MoveTo(int x, int y);

		int PosX() const;
		int PosY() const;
		int Width() const;
		int Height() const;
		SDL_Rect Rect() const;

		bool MouseHovered(int32_t x, int32_t y);
	protected:
		SDL_Rect rect_ = {0, 0, 0, 0};

		SDL_Renderer* targetRenderer_ = nullptr;

		bool visable_ = true;
};

#endif	/* RENDERABLE_H */
