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

	pic_[BUTTON_NORMAL] = ToolBox::LoadTexture("normal.png", window, r, g, b);
	pic_[BUTTON_HOVERED] = ToolBox::LoadTexture("hover.png", window, r, g, b);
	pic_[BUTTON_PUSHED] = ToolBox::LoadTexture("push.png", window, r, g, b);

	rect_.x = 60;
	rect_.y = 120;
	SDL_QueryTexture(pic_[BUTTON_NORMAL], nullptr, nullptr, &rect_.w, &rect_.h);

	buttonState_ = BUTTON_NORMAL;
}

Button::~Button()
{
	Release_();
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
	SDL_RenderCopy(targetRenderer_, pic_[buttonState_], nullptr, &rect_);
}

void
Button::RenderFullWindow()
{
	SDL_RenderCopy(targetRenderer_, pic_[buttonState_], nullptr, nullptr);
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
