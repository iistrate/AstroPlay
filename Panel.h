#ifndef PANEL_H
#define PANEL_H

#include <vector>
#include "Image.h"
#include "Button.h"

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
	std::vector <Button*> m_Buttons;
public:
	Panel(int w, int h, int x, int y);
	~Panel();

	void getImages(std::vector < Image* > &f_Images);

	int getX() {
		return m_panelx;
	}
	int getY() {
		return m_panely;
	}
	void setX(int x) {
		m_panelx = x;
	}
	void setY(int y) {
		m_panely = y;
	}
	bool isVisible() {
		return m_visible;
	}
	void setVisible(bool visible) {
		m_visible = visible;
	}
	void addButton(int x, int y, int w, int h, Image* btnImage, int identity);
	std::vector < Button* > getButtons(void) {
		return m_Buttons;
	}
};

#endif //end Panel.h