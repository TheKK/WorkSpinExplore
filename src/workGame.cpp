/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: workGame.cpp
 */

#include "workGame.h"

const static SDL_Rect viewport = {0, 0, 213, 360};

//const Window* WorkGame::window;
//vector<struct UI> WorkGame::uiSet_;

WorkGame::WorkGame(SDL_Renderer* renderer):
	backGroundPicture_("workGameBG.png", renderer),
	workButton_("normal.png", "hover.png", "push.png", renderer),
	moneyCounter_("./number.png", 4, 30, 30, renderer)
{
	//this->window = &window;
	targetRenderer_ = renderer;

	/* Set initial position to the left upper coner of this viewport*/
	backGroundPicture_.MoveTo(viewport.x, viewport.y);
	workButton_.MoveTo(viewport.x, viewport.y);
	moneyCounter_.MoveTo(viewport.x, viewport.y);

	/* Move these friends to their new place*/
	workButton_.Move(
		(viewport.w - workButton_.Width()) / 2,
		(viewport.h - workButton_.Height()) / 2);
	moneyCounter_.Move(
		(viewport.w - moneyCounter_.Width()) / 2 - 30,
		viewport.h - moneyCounter_.Height() - 10);

	//TODO: make this looks great
	renderableList_.push_back(&workButton_);
	renderableList_.push_back(&moneyCounter_);

	//LoadScript_();
}

WorkGame::~WorkGame()
{
	Release_();
}

void
WorkGame::EventHandler(const SDL_Event& event)
{
	switch (event.type) {
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_F11:
			debugOff_ = !debugOff_;
			if (debugOff_)
				cout << "Debug mode off" << endl;
			else
				cout << "Debug mode on" << endl;
			break;
		case SDLK_w:
			cout << "Num: " << moneyCounter_.GetNum() << endl;
			break;
		}
		break;
	case SDL_MOUSEMOTION:
		if (debugOff_)
			break;

		for (Renderable* e : renderableList_) {
			if (e->MouseHovered(event.motion.x, event.motion.y) &&
			    event.motion.state == SDL_BUTTON_LMASK) {
				e->Move(event.motion.xrel, event.motion.yrel);	
			}
		}
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (event.button.button == SDL_BUTTON_LEFT) {
			TapTheButton_();
			//for (auto e : uiSet_) {
				//if (e.ptr->MouseHovered(event.button.x,
						    //event.button.y)) {
					//lua_getglobal(L,e.name);
					//lua_getfield(L, -1, "clickFunc");
					//lua_call(L, 0, 0);
					//lua_pop(L, 1);
					//cout << "Size: " <<
					//lua_gettop(L) << endl;
				//}
			//}
		}

		/* Check current mode */
		if (debugOff_)
			break;

		if (event.button.button == SDL_BUTTON_MIDDLE) {
			for (Renderable* e : renderableList_) {
				if (e->MouseHovered(event.button.x,
						    event.button.y)) {
					cout << "x: " << e->PosX() << endl;
					cout << "y: " << e->PosY() << endl;
				}
			}
		}
		break;
	case SDL_MOUSEBUTTONUP:
		if (event.button.button == SDL_BUTTON_LEFT)
			ReleaseTheButton_();
		break;
	case SDL_USEREVENT:
		if (event.user.type == UserEvents::UserEvent1)
			cout << "event1 got" << endl;
		else if (event.user.type == UserEvents::UserEvent2)
			cout << "event2 got" << endl;
		else
			cout << event.user.type << endl;
		break;
	}
}

void
WorkGame::Update()
{
}

void
WorkGame::Render()
{
	backGroundPicture_.Render();

	for (auto& e : renderableList_)
		e->Render();
}

void
WorkGame::TapTheButton_()
{
	workButton_.ChangeState(BUTTON_PUSHED);
	moneyCounter_.AddNum(1);
}

void
WorkGame::ReleaseTheButton_()
{
	workButton_.ChangeState(BUTTON_NORMAL);
}

//void
//WorkGame::LoadScript_()
//{
	//L = luaL_newstate();
	//luaL_openlibs(L);

	//lua_register(L, "CreateButton", CreateButton_);
	//if (luaL_dofile(L, "./game/scripts/workGame.lua")) {
		//cout << "Lua error: " <<  lua_tostring(L, -1) << endl;
		//lua_close(L);
		//return;
	//}
//}

//int
//WorkGame::CreateButton_(lua_State* L)
//{
	//int posX, posY;
	//const char* filePath;
	//const char* name;

	//lua_getfield(L, -1, "posX");
	//lua_getfield(L, -2, "posY");
	//posX = lua_tointeger(L, -2);
	//posY = lua_tointeger(L, -1);
	//lua_pop(L, 2);

	//lua_getfield(L, -1, "pic");
	//filePath = lua_tostring(L, -1);
	//lua_pop(L, 1);

	//lua_getfield(L, -1, "name");
	//name = lua_tostring(L, -1);
	//lua_pop(L, 2);
	
	//Renderable* tmp = new Texture(string(filePath), *window);
	//tmp->MoveTo(posX, posY);
	
	//struct UI tp;
	//tp.name = name;
	//tp.ptr = tmp;
	//uiSet_.push_back(tp);

	//return 0;
//}

void
WorkGame::Release_()
{
	//for(auto e : uiSet_)
		//delete e.ptr;

	//lua_close(L);
}
