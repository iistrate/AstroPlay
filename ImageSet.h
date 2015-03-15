#ifndef IMAGE_SET_H
#define IMAGE_SET_H

#include "Image.h"
#include <vector>

class ImageSet {
private:
	std::vector < Image* > m_Images;
	int m_zIndex;
	const int m_identifier;
public:
	ImageSet(std::vector < Image* > Images, int zIndex, int identity): m_zIndex(zIndex), m_identifier(identity) {
		m_Images = Images;
	}
	ImageSet(Image* singleImage, int zIndex, int identity) : m_Images(0), m_zIndex(zIndex), m_identifier(identity) {
		m_Images.push_back(singleImage);
	}
	~ImageSet(void) {
		for (std::vector < Image* >::size_type i = 0; i < m_Images.size(); i++) {
			delete m_Images[i];
		}
	}
	int getzIndex(void) {
		return m_zIndex;
	}
	std::vector < Image* > getImages(void) {
		return m_Images;
	}
	const int getIdentifier(void) {
		return m_identifier;
	}
};

#endif