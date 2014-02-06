#include "TextureManager.h"

TextureManager::TextureManager() {}

void TextureManager::draw(SDL_Renderer* renderer) {
	//clear window
	SDL_RenderClear(renderer);
	
	SDL_Surface* pTempSurface = IMG_Load("");
	m_pTexture = SDL_CreateTextureFromSurface(renderer, pTempSurface);

	SDL_RenderPresent(renderer);
}