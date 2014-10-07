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
#include "userEvent.h"
#include "soundEngine.h"

using namespace std;

void PrintVersionInfo()
{
	SDL_version compiled;
	SDL_version linked;

	SDL_VERSION(&compiled);
	SDL_GetVersion(&linked);
	SDL_Log("Compiled against SDL version %d.%d.%d.\n",
	       compiled.major, compiled.minor, compiled.patch);
	SDL_Log("Linked against SDL version %d.%d.%d.\n",
	       linked.major, linked.minor, linked.patch);

	SDL_Log("SDL_image linked version %d.%d.%d\n",
		IMG_Linked_Version()->major,
		IMG_Linked_Version()->minor,
		IMG_Linked_Version()->patch
	);

	SDL_Log("SDL_ttf linked version %d.%d.%d.\n",
		TTF_Linked_Version()->major,
		TTF_Linked_Version()->minor,
		TTF_Linked_Version()->patch
	);
}

void
InitSystem()
{
	/* Initialize SDL, SDL2_image and SDL2_ttf */
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		string errMsg("Error while initialize SDL2 subsystem: ");
		errMsg += SDL_GetError();
		throw runtime_error(errMsg);
	}

	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) < 0) {
		string errMsg("Error while initialize SDL2_image: ");
		errMsg += IMG_GetError();
		throw runtime_error(errMsg);
	}

	if (TTF_Init() < 0) {
		string errMsg("Error while initialize SDL2_ttf: ");
		errMsg += TTF_GetError();
		throw runtime_error(errMsg);
	}

	/* Register user events */
	UserEvent::Init();
	SoundEngine::Init();

	/* Make game "pixelate" */
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

	/* Set application log's priority to DEBUG */
	SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_DEBUG);

	srand(time(nullptr));

	PrintVersionInfo();
}

void
CleanUp()
{
	SDL_Quit();
	IMG_Quit();
	TTF_Quit();

	SoundEngine::Quit();
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
