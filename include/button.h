/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: button.h
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "window.h"
#include "texture.h"

#include "toolBox.h"

using namespace std;

enum ButtonState {
	BUTTON_NORMAL,
	BUTTON_HOVERED,
	BUTTON_PUSHED
};

class Button
{
	public:
		Button(string normalPicPath, string hoverPicPath,
		       string pushPicPath, const Window& window,
		       Uint8 r = 0, Uint8 g = 255, Uint8 b = 255);
		~Button();

		void EventHandler(const SDL_Event& event);
		void Update();
		void Render();
		void RenderFullWindow();

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

		bool MouseHoverd(int mousePosX, int mousePosY);
		void ChangeState(enum ButtonState buttonState);
	private:
		SDL_Texture* normalPic_ = nullptr;
		SDL_Texture* hoverPic_ = nullptr;
		SDL_Texture* pushPic_ = nullptr;
		SDL_Rect rect_;
		enum ButtonState buttonState_ = BUTTON_NORMAL;

		SDL_Renderer* targetRenderer_;

		void Release_();
};

#endif	/* BUTTON_H */
