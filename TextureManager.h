#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include <iostream>


#include "Image.h"

class TextureManager {
private:
	SDL_Rect m_dstRect;
	SDL_Rect m_srcRect;
	SDL_Texture* m_pTexture;

	//font
	SDL_Surface* m_pTextSurface = 0;
	TTF_Font* m_pfont = 0;
	const char *m_pcstr;
	std::string m_scommand;

public:
	TextureManager();
	~TextureManager();

	void draw(SDL_Renderer* f_prenderer, std::vector < Image > f_Images);
	void drawText(SDL_Renderer* f_prenderer, std::string s);
};
#endif // end TextureManager.h