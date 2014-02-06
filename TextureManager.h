#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL.h>
#include <SDL_image.h>

class TextureManager {
private:
	SDL_Rect m_dstRect;
	SDL_Rect m_srcRect;
	SDL_Texture* m_pTexture;
public:
	TextureManager();
	~TextureManager() {}

	void draw(SDL_Renderer* f_prenderer);
};
#endif // end TextureManager.h