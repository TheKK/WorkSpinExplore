/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameState.h
 */

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <SDL2/SDL.h>

class GameState
{
	public:
		virtual ~GameState() {};

		virtual void EventHandler(const SDL_Event& event) = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;

		bool IsRunning() { return isRunning; };
		void WantQuit() { isRunning = false; };
	private:
		static bool isRunning;
};

#endif	/* GAME_STATE_H */
