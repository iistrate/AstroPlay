#ifndef IMAGE_H
#define IMAGE_H

#include <string>

class Image {
private:
	//location on screen
	int m_ix;
	int m_iy;
	//image attributes
	int m_iwidth;
	int m_iheight;
	//layer; z-index
	int m_ilayer;
	//animated
	bool m_banimated;
	int m_icurrentFrame;
	int m_itotalFrames;
	//file name
	std::string m_sfname;
	//image location
	int m_ispriteX;
	int m_ispriteY;

public:
	Image();
	Image(bool a, int f, int tf);
	~Image() {}

	void load(std::string fname, int x, int y, int width, int height, int sX, int sY, int layer);
	
	//getters
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	int getLayer();
	bool isAnimated();
	int getFrame();
	int getTotalFrames();
	std::string getFileName();
	int getSpriteX();
	int getSpriteY();
};

#endif // Image.h