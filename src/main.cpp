/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: main.cpp
 */

#include <stdexcept>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "game.h"

using namespace std;

void
InitSystem()
{
	/* Initialize SDL and SDL2_image */
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		string errMsg("Error while initialize SDL2 subsystem: ");
		errMsg += SDL_GetError();
		throw runtime_error(errMsg);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) < 0) {
		string errMsg("Error while initialize SDL2_image: ");
		errMsg += SDL_GetError();
		throw runtime_error(errMsg);
	}

	if (TTF_Init() < 0) {
		string errMsg("Error while initialize SDL2_ttf: ");
		errMsg += SDL_GetError();
		throw runtime_error(errMsg);
	}

	srand(time(nullptr));
}

void
CleanUp()
{
	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
}

int
main(int argc, char* argv[])
{
	try {
		InitSystem();

		Game game;
		game.Execute();
	} catch (runtime_error& e) {
		cerr << e.what() << endl;
	}

	CleanUp();

	return 0;
}
