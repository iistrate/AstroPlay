#include "TextureManager.h"

TextureManager::TextureManager() {}

void TextureManager::draw(SDL_Renderer* f_prenderer, std::vector < Image* > f_Images) {
	//helper vars
	const char* fname = "";
	int cameraModifierX = 0;
	int cameraModifierY = 0;
	int origX = 0;
	int origY = 0;

	for (std::vector < Image >::size_type i = 0; i != f_Images.size(); i++) {
		//speed up loading
		if (fname != f_Images[i]->getFileName()) {
			fname = f_Images[i]->getFileName();
			SDL_Surface* pTempSurface = IMG_Load(fname);
			m_pTexture = SDL_CreateTextureFromSurface(f_prenderer, pTempSurface);
			//free and destroy surface
			SDL_FreeSurface(pTempSurface);
			pTempSurface = NULL;
		}


		m_srcRect.x = f_Images[i]->getSpriteX();
		m_srcRect.y = f_Images[i]->getSpriteY();
		m_srcRect.w = m_dstRect.w = f_Images[i]->getWidth();
		m_srcRect.h = m_dstRect.h = f_Images[i]->getHeight();

		//camera modifiers
		origX = f_Images[i]->getX();
		origY = f_Images[i]->getY();
		m_dstRect.x = origX + cameraModifierX;
		m_dstRect.y = origY + cameraModifierY;

		//magic
		SDL_RenderCopy(f_prenderer, m_pTexture, &m_srcRect, &m_dstRect);
	}
}
void TextureManager::drawText(SDL_Renderer* f_prenderer, std::string s, int x, int y, int wrap) {

	Uint32 lineWidth = wrap;
	int yPos = y;
	int xPos = x;

	//initialize font
	if (TTF_Init() == -1) {
		std::cout << "Fonts failed to initialize" << std::endl;
	}
	else {
		m_pfont = TTF_OpenFont("assets/arounded.ttf", 16);
	}

	m_pcstr = s.c_str();
	m_pTextSurface = TTF_RenderText_Blended_Wrapped(m_pfont, m_pcstr, { 0, 0, 0 }, lineWidth);
	m_pTexture = SDL_CreateTextureFromSurface(f_prenderer, m_pTextSurface);
	m_pTextSurface = NULL;
	SDL_QueryTexture(m_pTexture, 0, 0, &m_srcRect.w, &m_srcRect.h);

	m_dstRect.x = x;
	m_dstRect.y = y;

	m_dstRect.w = m_srcRect.w;
	m_dstRect.h = m_srcRect.h;

	//magic
	SDL_RenderCopy(f_prenderer, m_pTexture, NULL, &m_dstRect);
}
TextureManager::~TextureManager() {
	//font cleanup
	TTF_Quit();
	TTF_CloseFont(m_pfont);
	m_pfont = 0;
}

void TextureManager::sortByLayer(std::vector < Image* > f_Images) {
	for (std::vector < Image >::size_type i = 0; i < f_Images.size(); i++) {
		std::cout << f_Images[i]->getLayer() << std::endl;
	}
}