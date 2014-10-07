#include "toolBox.h"

SDL_Texture*
ToolBox::LoadTexture(string filePath, SDL_Renderer* renderer,
		     Uint8 r, Uint8 g, Uint8 b)
{
	SDL_assert(renderer != nullptr);

	SDL_Surface* loadedImage = nullptr;
	SDL_Texture* tex = nullptr;
	string basePath = SDL_GetBasePath();

	loadedImage = IMG_Load((basePath + filePath).c_str());
	if (loadedImage == nullptr) {
		string errMsg("IMG error while opening: ");
		errMsg += IMG_GetError();
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, errMsg.c_str());
		return nullptr;
	}

	SDL_SetColorKey(loadedImage, SDL_TRUE,
			SDL_MapRGB(loadedImage->format, r, g, b));

	tex = SDL_CreateTextureFromSurface(renderer, loadedImage);
	if (tex == nullptr) {
		string errMsg("SDL error while converting surface: ");
		errMsg += SDL_GetError();
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, errMsg.c_str());
	}

	SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);

	SDL_FreeSurface(loadedImage);

	return tex;
}
