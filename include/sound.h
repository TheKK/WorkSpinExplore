/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: sound.h
 */

#ifndef SOUND_H
#define SOUND_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <SDL2/SDL.h>
#include <AL/al.h>
#include <AL/alure.h>

using namespace std;

class Sound
{
	public:
		Sound(string filePath);
		~Sound();

		//File operations
		void LoadSoundFile(string filePath);

		void SetSourcePosition(ALint x, ALint y, ALint z);

		//Sound control
		void Play();
		void Stop();
		void Pause();
	private:
		ALuint source_;
		ALuint buffer_;

		ALint sourcePosX_ = 0;
		ALint sourcePosY_ = 0;
		ALint sourcePosZ_ = 0;

		void Release_();
};

#endif
