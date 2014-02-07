#include "TextureManager.h"

TextureManager::TextureManager() {}

void TextureManager::draw(SDL_Renderer* f_prenderer) {
	//clear window
	SDL_RenderClear(f_prenderer);
	
	SDL_Surface* pTempSurface = IMG_Load("assets/grauru.jpg");
	m_pTexture = SDL_CreateTextureFromSurface(f_prenderer, pTempSurface);
	//free and destroy surface
	SDL_FreeSurface(pTempSurface);
	pTempSurface = NULL;

	m_srcRect.x = m_dstRect.x;
	m_srcRect.y = m_dstRect.y;
	m_srcRect.w = m_dstRect.w = 275;
	m_srcRect.h = m_dstRect.h = 183;

	//set color white
	SDL_SetRenderDrawColor(f_prenderer, 255, 255, 255, 255);
	
	SDL_RenderCopy(f_prenderer, m_pTexture, &m_srcRect, &m_dstRect);

	SDL_RenderPresent(f_prenderer);
}