/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: button.cpp
 */

#include "button.h"

Button::Button(string normalPicPath, string hoverPicPath, string pushPicPath,
	       const Window& window, Uint8 r, Uint8 g, Uint8 b)
{
	targetRenderer_ = window.GetRenderer();

	normalPic_ = ToolBox::LoadTexture("normal.png", window, r, g, b);
	hoverPic_ = ToolBox::LoadTexture("hover.png", window, r, g, b);
	pushPic_ = ToolBox::LoadTexture("push.png", window, r, g, b);

	rect_.x = 60;
	rect_.y = 120;
	SDL_QueryTexture(normalPic_, NULL, NULL, &rect_.w, &rect_.h);
}

Button::~Button()
{
}

void
Button::EventHandler(const SDL_Event& event)
{
	switch (event.type) {
	case SDL_MOUSEMOTION:
		if (MouseHoverd(event.motion.x, event.motion.y))
			ChangeState(BUTTON_HOVERED);
		else
			ChangeState(BUTTON_NORMAL);
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (MouseHoverd(event.button.x, event.button.y))
			ChangeState(BUTTON_PUSHED);
		break;
	case SDL_MOUSEBUTTONUP:
		ChangeState(BUTTON_NORMAL);
		break;
	}
}

void
Button::Update()
{
}

void
Button::Render()
{
	switch (buttonState_) {
	case BUTTON_NORMAL:
		SDL_RenderCopy(targetRenderer_, normalPic_, NULL, &rect_);
		break;
	case BUTTON_HOVERED:
		SDL_RenderCopy(targetRenderer_, hoverPic_, NULL, &rect_);
		break;
	case BUTTON_PUSHED:
		SDL_RenderCopy(targetRenderer_, pushPic_, NULL, &rect_);
		break;
	}
}

void
Button::Move(int dx, int dy)
{
	rect_.x += dx;
	rect_.y += dy;
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
	if (normalPic_ != nullptr)
		SDL_DestroyTexture(normalPic_);
	normalPic_ = nullptr;

	if (hoverPic_ != nullptr)
		SDL_DestroyTexture(hoverPic_);
	hoverPic_ = nullptr;

	if (pushPic_ != nullptr)
		SDL_DestroyTexture(pushPic_);
	pushPic_ = nullptr;
}
