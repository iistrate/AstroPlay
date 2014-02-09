#include "Image.h"

Image::Image() {
	m_banimated = false;
}
Image::Image(bool a, int f, int tf) {
	m_banimated = a;
	m_icurrentFrame = f;
	m_itotalFrames = tf;
}

void Image::load(std::string fname, int x, int y, int width, int height, int sX, int sY, int layer) {
	m_sfname = fname;
	m_ix = x;
	m_iy = y;
	m_iwidth = width;
	m_iheight = height;
	m_ispriteX = sX;
	m_ispriteY = sY;
	m_ilayer = layer;
}

//getters
int Image::getX() {
	return m_ix;
}
int Image::getY() {
	return m_iy;
}
int Image::getWidth() {
	return m_iwidth;
}
int Image::getHeight() {
	return m_iheight;
}
int Image::getLayer() {
	return m_ilayer;
}
bool Image::isAnimated() {
	return m_banimated;
}
int Image::getFrame() {
	return m_icurrentFrame;
}
int Image::getTotalFrames() {
	return m_itotalFrames;
}
std::string Image::getFileName() {
	return m_sfname;
}
int Image::getSpriteX() {
	return m_ispriteX;
}
int Image::getSpriteY() {
	return m_ispriteY;
}