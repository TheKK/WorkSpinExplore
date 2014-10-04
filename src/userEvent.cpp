/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: userEvent.cpp
 */

#include "userEvent.h"

vector<Uint32> UserEvent::eventID;

void
UserEvent::Init()
{
	Uint32 id;
	for (int i = 0; i < USEREVENT_COUNT; i++) {
		id = SDL_RegisterEvents(1);
		if (id== -1)
			throw runtime_error("Can't get user event ID");
		else
			eventID.push_back(id);
	}
}

void
UserEvent::PushEvent(enum UserEventList type)
{
	SDL_Event tmp;
	SDL_zero(tmp);
	tmp.type = eventID[type];
	SDL_PushEvent(&tmp);
}
