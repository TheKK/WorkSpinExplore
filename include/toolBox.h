#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class ToolBox
{
	public:
		static SDL_Texture* LoadTexture(
			string filePath, SDL_Renderer* renderer,
			Uint8 r = 0, Uint8 g = 255, Uint8 b = 255);
};

#endif	/* TOOLBOX_H */
