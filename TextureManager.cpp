#include "TextureManager.h"

TextureManager::TextureManager() {}

void TextureManager::draw(SDL_Renderer* f_prenderer, std::vector < Image* > f_Images) {
	const char* fname = "";
	for (std::vector < Image >::size_type i = 0; i != f_Images.size(); i++) {
		fname = f_Images[i]->getFileName();
		SDL_Surface* pTempSurface = IMG_Load(fname);
		m_pTexture = SDL_CreateTextureFromSurface(f_prenderer, pTempSurface);
		//free and destroy surface
		SDL_FreeSurface(pTempSurface);
		pTempSurface = NULL;

		m_srcRect.x = f_Images[i]->getSpriteX();
		m_srcRect.y = f_Images[i]->getSpriteY();
		m_dstRect.x = f_Images[i]->getX() + 360;
		m_dstRect.y = f_Images[i]->getY();
		m_srcRect.w = m_dstRect.w = f_Images[i]->getWidth();
		m_srcRect.h = m_dstRect.h = f_Images[i]->getHeight();

		SDL_RenderCopy(f_prenderer, m_pTexture, &m_srcRect, &m_dstRect);
	}
}
void TextureManager::drawText(SDL_Renderer* f_prenderer, std::string s) {
	//initialize font
	if (TTF_Init() == -1) {
		std::cout << "Fonts failed to initialize" << std::endl;
	}
	else {
		m_pfont = TTF_OpenFont("assets/arounded.ttf", 16);
	}
	m_pcstr = s.c_str();
	printf(m_pcstr);
	m_pTextSurface = TTF_RenderUTF8_Solid(m_pfont, m_pcstr, { 0, 0, 0 });
	m_pTexture = SDL_CreateTextureFromSurface(f_prenderer, m_pTextSurface);
	m_pTextSurface = NULL;
	SDL_QueryTexture(m_pTexture, 0, 0, &m_srcRect.w, &m_srcRect.h);

	m_srcRect.x = m_dstRect.x;
	m_srcRect.y = m_dstRect.y;
	m_dstRect.w = m_srcRect.w;
	m_dstRect.h = m_srcRect.h;

	SDL_RenderCopy(f_prenderer, m_pTexture, &m_srcRect, &m_dstRect);
}
TextureManager::~TextureManager() {
	//font cleanup
	TTF_Quit();
	TTF_CloseFont(m_pfont);
	m_pfont = 0;
}