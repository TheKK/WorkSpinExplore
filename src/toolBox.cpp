#include "toolBox.h"

SDL_Texture*
ToolBox::LoadTexture(string filePath, const Window& window,
		     Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Surface* loadedImage = nullptr;
	SDL_Texture* tex = nullptr;
	string basePath = SDL_GetBasePath();	/* Using absolute path here */

	loadedImage = IMG_Load((basePath + filePath).c_str());
	if (loadedImage == nullptr) {
		string errMsg("SDL error while loading ");
		errMsg += (filePath + ": " + IMG_GetError());
		throw runtime_error(errMsg);
	}

	SDL_SetColorKey(loadedImage, SDL_TRUE,
			SDL_MapRGB(loadedImage->format, r, g, b));

	tex = SDL_CreateTextureFromSurface(window.GetRenderer(), loadedImage);
	if (tex == nullptr) {
		string errMsg("SDL error while converting surface: ");
		errMsg += SDL_GetError();
		throw runtime_error(errMsg);
	}

	SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);

	SDL_FreeSurface(loadedImage);

	return tex;
}
