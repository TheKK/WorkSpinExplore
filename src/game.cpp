/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: game.cpp
 */

#include "game.h"

#define GAME_FPS	60
#define GAME_WIDTH	640
#define GAME_HEIGHT	360

using namespace std;

Game::Game():
	mainWindow_("Work!Spin!Explore!!", GAME_WIDTH, GAME_HEIGHT),
	workGame_(mainWindow_),
	spinGame_(mainWindow_),
	exploreGame_(mainWindow_),
	aBar_("achievementBar.png", mainWindow_),
	appIsRunning_(true)
{
}

Game::~Game()
{
}

void
Game::Execute()
{
	/* Main loop */
	SDL_Event event;
	Timer timer;
	while (appIsRunning_) {
		timer.Start();

		while (SDL_PollEvent(&event))
			EventHandler_(event);

		Update_();
		Render_();

		if (timer.GetTicks() < (1000 / GAME_FPS))
			SDL_Delay((1000 / GAME_FPS) - timer.GetTicks());
	}
}

void
Game::EventHandler_(const SDL_Event &event)
{
	switch (event.type) {
	case SDL_QUIT:
		appIsRunning_ = false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_q:
			appIsRunning_ = false;
			break;
		case SDLK_F12:
			ScreenShot_();
			break;
		}
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (event.button.button == SDL_BUTTON_LEFT)
			mousePushCount++;
	}

	workGame_.EventHandler(event);
	spinGame_.EventHandler(event);
	exploreGame_.EventHandler(event);

	aBar_.EventHandler(event);

	if (!got && mousePushCount == 20) {
		aBar_.SendJob(ACHIEVEMENT_MOUSE_CLICK_20);
		got = true;
	}
}

void
Game::Update_()
{
	workGame_.Update();
	spinGame_.Update();
	exploreGame_.Update();
	
	aBar_.Update();
}

void
Game::Render_()
{
	mainWindow_.Clear();
	{
		workGame_.Render();
		spinGame_.Render();
		exploreGame_.Render();
		
		aBar_.Render();
	}
	mainWindow_.Present();
}

void
Game::ScreenShot_()
{
	int w, h;
	struct tm* timeinfo;
	time_t currentTime;
	char fileName[30];
	SDL_Surface* shot;

	SDL_GetRendererOutputSize(mainWindow_.GetRenderer(), &w, &h);

	/* Create blank surface to store screenshot */
	shot = SDL_CreateRGBSurface(0, w, h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	SDL_RenderReadPixels(mainWindow_.GetRenderer(), NULL, SDL_PIXELFORMAT_ARGB8888, shot->pixels, shot->pitch);

	/* Name file with date and time */
	time(&currentTime);
	timeinfo = localtime(&currentTime);
	strftime(fileName, 30, "%F:%T.bmp", timeinfo);

	SDL_SaveBMP(shot, fileName);

	SDL_FreeSurface(shot);
}

void
Game::Release_()
{
}
