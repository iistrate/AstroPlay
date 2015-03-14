#ifndef PANEL_H
#define PANEL_H

#include <vector>
#include "Image.h"

using std::vector;

class Panel {
private:
	int m_width;
	int m_height;
	int m_xPos;
	int m_yPos;
	vector < Image* > m_Images;
public:
	Panel(void) : m_width(0), m_height(0), m_xPos(0), m_yPos(0), m_Images(0) {}
	Panel(int w, int h, int x, int y);
	~Panel(void);
	//inlines
	void setWidth(int w) {
		m_width = w;
	}
	void setHeight(int h) {
		m_height = h;
	}
	void setXPos(int x) {
		m_xPos = x;
	}
	void setYPos(int y) {
		m_yPos = y;
	}
	int getWidth(void) {
		return m_width;
	}
	int getHeight(void) {
		return m_height;
	}
	int getXPos(void) {
		return m_xPos;
	}
	int getYPos(void) {
		return m_yPos;
	}

};

#endif //end Panel.h