/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: renderable.cpp
 */

#include "renderable.h"

Renderable::Renderable()
{
}

Renderable::~Renderable()
{
}

void
Renderable::Enlarge(int dw, int dh)
{
	rect_.w += dw;
	rect_.h += dh;
}

void
Renderable::SetSize(unsigned int w, unsigned int h)
{
	rect_.w = w;
	rect_.h = h;
}

void
Renderable::SetRenderer(SDL_Renderer* renderer)
{
	targetRenderer_ = renderer;
}

void
Renderable::Move(int x, int y)
{
	rect_.x += x;
	rect_.y += y;
}

void
Renderable::MoveXTo(int x)
{
	rect_.x = x;
}

void
Renderable::MoveYTo(int y)
{
	rect_.y = y;
}

void
Renderable::MoveTo(int x, int y)
{
	rect_.x = x;
	rect_.y = y;
}

int
Renderable::PosX() const
{
	return rect_.x;
}


int
Renderable::PosY() const
{
	return rect_.y;
}

int
Renderable::Width() const
{
	return rect_.w;
}

int
Renderable::Height() const
{
	return rect_.h;
}

SDL_Rect
Renderable::Rect() const
{
	return rect_;
}
