/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: workGame.h
 */

#ifndef WORK_GAME_H
#define WORK_GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include <lua.hpp>

#include "texture.h"
#include "button.h"
#include "numberDisplayer.h"
#include "userEventControler.h"

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
		Texture backGroundPicture_;
		Button workButton_;
		NumberDisplayer moneyDisplayer_;

		SDL_Renderer* targetRenderer_;
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
