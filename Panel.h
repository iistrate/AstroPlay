#ifndef PANEL_H
#define PANEL_H

#include <vector>
#include "Image.h"

using std::vector;

class Panel {
private:
	//size
	int m_vectorY;
	int m_vectorX;

	//position
	int m_panelx;
	int m_panely;

	//flags
	bool m_visible;

	std::vector <Image *> m_Images;
public:
	Panel(int w, int h, int x, int y);
	~Panel();

	void getImages(std::vector < Image* > &f_Images);

	int Panel::getX() {
		return m_panelx;
	}
	int Panel::getY() {
		return m_panely;
	}
	void Panel::setX(int x) {
		m_panelx = x;
	}
	void Panel::setY(int y) {
		m_panely = y;
	}
	bool Panel::isVisible() {
		return m_visible;
	}
	void Panel::setVisible(bool visible) {
		m_visible = visible;
	}
};

#endif //end Panel.h