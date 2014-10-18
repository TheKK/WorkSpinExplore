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
	workGame_(mainWindow_.GetRenderer()),
	spinGame_(mainWindow_.GetRenderer()),
	exploreGame_(mainWindow_.GetRenderer()),
	achiBar_("game/images/achievementBar.png", mainWindow_.GetRenderer()),
	hand_("game/images/hand.png", mainWindow_.GetRenderer()),
	screenBorder_("game/images/screenBorder.png",
		      mainWindow_.GetRenderer()),
	pauseBG_("game/images/pause.png", mainWindow_.GetRenderer()),
	pauseSE_("game/sounds/pauseSound.ogg")
{
	/**
	 * Make window two times large than logical size
	 * and move it to center of screen
	 */
	mainWindow_.Resize(mainWindow_.Width() * 2, mainWindow_.Height() * 2);
	mainWindow_.MoveTo(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

	pauseBG_.SetAlpha(250);
	pauseBG_.Hide();
	pauseBG_.SetBlendMode(SDL_BLENDMODE_MOD);

	SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "game class created");
}

Game::~Game()
{
	Release_();
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
		case SDLK_p:
			TogglePause_();
			break;
		case SDLK_F12:
			ScreenShot_();
			break;
		}
		break;
	case SDL_MOUSEMOTION:
		hand_.MoveTo(event.motion.x - 80, event.motion.y);
		break;
	}

	workGame_.EventHandler(event);
	spinGame_.EventHandler(event);
	exploreGame_.EventHandler(event);

	achiBar_.EventHandler(event);
}

void
Game::Update_()
{
	workGame_.Update();
	spinGame_.Update();
	exploreGame_.Update();

	achiBar_.Update();
}

void
Game::Render_()
{
	mainWindow_.Clear();
	{
		workGame_.Render();
		spinGame_.Render();
		exploreGame_.Render();

		screenBorder_.Render();

		hand_.Render();

		achiBar_.Render();

		pauseBG_.RenderFullWindow();
	}
	mainWindow_.Present();
}

void
Game::TogglePause_()
{
	appIsPaused_ = !appIsPaused_;

	if (appIsPaused_) {
		achiBar_.Pause();
		workGame_.Pause();

		pauseBG_.Show();
		pauseSE_.Play();
	} else {
		achiBar_.Resume();
		workGame_.Resume();

		pauseBG_.Hide();
		pauseSE_.Stop();
	}
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
	shot = SDL_CreateRGBSurface(
		0,
		w, h,
		32,
		0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000
	);
	SDL_RenderReadPixels(
		mainWindow_.GetRenderer(), NULL,
		SDL_PIXELFORMAT_ARGB8888,
		shot->pixels,
		shot->pitch
	);

	/* Name file with date and time */
	time(&currentTime);
	timeinfo = localtime(&currentTime);
	strftime(fileName, 30, "%F:%T.png", timeinfo);

	IMG_SavePNG(shot, fileName);

	SDL_FreeSurface(shot);
}

void
Game::Release_()
{
	SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "game class released");
}
