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
	appIsRunning_(true)
{
	vector<string> iconPathes, texts;

	iconPathes.emplace_back(string("achievementIcon1.png"));
	texts.emplace_back(string("Achievement unlocked!"));

	aBar_.Load("achievementBar.png", iconPathes, texts, mainWindow_);
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
		aBar_.SendJob(ACHIEVEMENT_TEST);
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
Game::Release_()
{
}
