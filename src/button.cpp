/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: button.cpp
 */

#include "button.h"

Button::Button(string normalPicPath, string hoverPicPath, string pushPicPath,
	       const Window& window, Uint8 r, Uint8 g, Uint8 b)
{
	Load(normalPicPath, hoverPicPath, pushPicPath, window, r, g, b);
}

Button::~Button()
{
	Release_();
}

void
Button::Load(string normalPicPath, string hoverPicPath, string pushPicPath,
	     const Window& window, Uint8 r, Uint8 g, Uint8 b)
{
	SetRenderer(window.GetRenderer());

	pic_[BUTTON_NORMAL] = ToolBox::LoadTexture("normal.png", window,
						   r, g, b);
	pic_[BUTTON_HOVERED] = ToolBox::LoadTexture("hover.png", window,
						    r, g, b);
	pic_[BUTTON_PUSHED] = ToolBox::LoadTexture("push.png", window,
						   r, g, b);

	SDL_QueryTexture(pic_[BUTTON_NORMAL], nullptr, nullptr,
			 &rect_.w, &rect_.h);

	buttonState_ = BUTTON_NORMAL;
}

void
Button::Render()
{
	SDL_RenderCopy(targetRenderer_, pic_[buttonState_], nullptr, &rect_);
}

bool
Button::MouseHoverd(int mousePosX, int mousePosY)
{
	if (
		mousePosX < (rect_.x + rect_.w) && mousePosX > rect_.x &&
		mousePosY < (rect_.y + rect_.h) && mousePosY > rect_.y
	)
		return true;
	else
		return false;
}

void
Button::ChangeState(enum ButtonState newState)
{
	buttonState_ = newState;
}

void
Button::Release_()
{
	for (SDL_Texture* e : pic_) {
		if (e != nullptr)
			SDL_DestroyTexture(e);
		e = nullptr;
	}
}
