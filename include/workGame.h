/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: workGame.h
 */

#ifndef WORK_GAME_H
#define WORK_GAME_H

#include <iostream>
#include <SDL2/SDL.h>

#include "texture.h"
#include "button.h"
#include "numberDisplayer.h"
#include "sound.h"
#include "userEvent.h"

using namespace std;

//struct UI {
	//const char* name = nullptr;
	//Renderable* ptr = nullptr;
//};

class WorkGame
{
	public:
		WorkGame(SDL_Renderer* renderer);
		~WorkGame();

		void EventHandler(const SDL_Event& event);
		void Update();
		void Render();
	private:
		/* Graphical objects */
		Texture backGroundPicture_;
		Button workButton_;
		NumberDisplayer moneyCounter_;
		vector<Renderable*> renderableList_;

		SDL_Renderer* targetRenderer_ = nullptr;

		Sound buttonSound_;

		bool debugOff_ = true;
		//static const Window* window;

		void TapTheButton_();
		void ReleaseTheButton_();

		//lua_State* L;
		//static vector<struct UI> uiSet_;
		//void LoadScript_();
		//static int CreateButton_(lua_State* L);

		void Release_();
};

#endif	/* WORK_GAME_H */
