#include "bitmap.h"


Bitmap::Bitmap()
	:m_bitmapFileHeader(),
	m_bitmapInfoHeader(),
	p_pixelArray(NULL),
	p_file(NULL)
{
}

Bitmap::Bitmap(const BITMAPFILEHEADER &bmpFileHeader, const BITMAPINFOHEADER &bmpInfoHeader)
	:m_bitmapFileHeader(bmpFileHeader),
	m_bitmapInfoHeader(bmpInfoHeader),
	p_pixelArray(NULL),
	p_file(NULL)
{
}

Bitmap::Bitmap(const Bitmap &other)
	:m_bitmapFileHeader(other.m_bitmapFileHeader),
	m_bitmapInfoHeader(other.m_bitmapInfoHeader),
	p_pixelArray(other.p_pixelArray),
	p_file(other.p_file)
{
}

Bitmap& Bitmap::operator=(const Bitmap &other)
{
	if(this != &other)
	{
		m_bitmapFileHeader = other.m_bitmapFileHeader;
		m_bitmapInfoHeader = other.m_bitmapInfoHeader;
		p_pixelArray = other.p_pixelArray;
		p_file = other.p_file;
	}

	return(*this);
}

Bitmap::~Bitmap()
{
	if(p_file != NULL)
	{
		fclose(p_file);
		p_file = NULL;
	}
}

void Bitmap::setFileHeader(const BITMAPFILEHEADER &bmpFileHeader)
{
	m_bitmapFileHeader = bmpFileHeader;
}

BITMAPFILEHEADER Bitmap::getFileHeader() const
{
	return(m_bitmapFileHeader);
}

void Bitmap::setInfoHeader(const BITMAPINFOHEADER &bmpInfoHeader)
{
	m_bitmapInfoHeader = bmpInfoHeader;
}

BITMAPINFOHEADER Bitmap::getInfoHeader() const
{
	return(m_bitmapInfoHeader);
}

void Bitmap::setPixelArray(unsigned char *pixelArray)
{
	memcpy(p_pixelArray, pixelArray, sizeof(pixelArray));
}

void Bitmap::write(char *filename)
{

}

void Bitmap::show(char *filename)
{

}
