#include "TextureManager.h"
#include <iostream>

TextureManager::TextureManager() {}

void TextureManager::draw(SDL_Renderer* f_prenderer) {

	SDL_Surface* pTempSurface = IMG_Load("assets/grauru.jpg");
	m_pTexture = SDL_CreateTextureFromSurface(f_prenderer, pTempSurface);
	//free and destroy surface
	SDL_FreeSurface(pTempSurface);
	pTempSurface = NULL;

	m_srcRect.x = m_dstRect.x;
	m_srcRect.y = m_dstRect.y;
	m_srcRect.w = m_dstRect.w = 275;
	m_srcRect.h = m_dstRect.h = 183;
	
	SDL_RenderCopy(f_prenderer, m_pTexture, &m_srcRect, &m_dstRect);
}
void TextureManager::drawText(SDL_Renderer* f_prenderer, std::string s) {
	//initialize font
	if (TTF_Init() == -1) {
		std::cout << "Fonts failed to initialize" << std::endl;
	}
	else {
		m_pfont = TTF_OpenFont("assets/ARLRDBD.TTF", 10);
	}
	m_pcstr = s.c_str();
	m_pTextSurface = TTF_RenderUTF8_Solid(m_pfont, m_pcstr, { 0, 0, 0 });
	m_pTexture = SDL_CreateTextureFromSurface(f_prenderer, m_pTextSurface);
	m_pTextSurface = NULL;

	m_srcRect.x = m_dstRect.x;
	m_srcRect.y = m_dstRect.y;
	m_srcRect.w = m_dstRect.w = 275;
	m_srcRect.h = m_dstRect.h = 183;

	SDL_RenderCopy(f_prenderer, m_pTexture, &m_srcRect, &m_dstRect);
}
TextureManager::~TextureManager() {
	//font cleanup
	TTF_Quit();
	TTF_CloseFont(m_pfont);
	m_pfont = 0;
}