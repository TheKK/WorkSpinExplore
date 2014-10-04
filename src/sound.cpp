/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: sound.cpp
 */

#include "sound.h"

Sound::Sound(string filePath)
{
	LoadSoundFile(filePath);
}

Sound::~Sound()
{
	Release_();
}

void
Sound::LoadSoundFile(string filePath)
{
	/* Gen buffer */
	alGenBuffers(1, &buffer_);

	/* Make a source */
	alGenSources(1, &source_);

	/* Load audio file */
	buffer_ = alureCreateBufferFromFile(filePath.c_str());
	if (buffer_ == AL_NONE) {
		string msg("OpenAL error: file not found, ");
		msg += filePath;
		throw runtime_error(msg);
	}

	/* Bind buffer to source */
	alSourcei(source_, AL_BUFFER, buffer_);
	if (alGetError() != AL_NO_ERROR) {
		fprintf(stderr, "AL error: %s", alureGetErrorString());
	}

}

void
Sound::SetSourcePosition(ALint x, ALint y, ALint z)
{
	sourcePosX_ = x;
	sourcePosY_ = y;
	sourcePosZ_ = z;

	alSource3i(source_, AL_POSITION, x, y, z);
}

void
Sound::Play()
{
	alSourcePlay(source_);
}

void
Sound::Stop()
{
	alSourceStop(source_);
}

void
Sound::Pause()
{
	alSourcePause(source_);
}

void
Sound::Release_()
{
	alDeleteSources(1, &source_);
	alDeleteBuffers(1, &buffer_);
}

