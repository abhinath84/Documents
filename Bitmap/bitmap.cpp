#include "bitmap.h"


Bitmap::Bitmap()
	:m_bitmapFileHeader(),
	m_bitmapInfoHeader(),
	p_pixelArray(NULL),
	p_file(NULL),
  m_pixelArraySize(0)
{
}

Bitmap::Bitmap(const BITMAPFILEHEADER &bmpFileHeader, const BITMAPINFOHEADER &bmpInfoHeader)
	:m_bitmapFileHeader(bmpFileHeader),
	m_bitmapInfoHeader(bmpInfoHeader),
	p_pixelArray(NULL),
	p_file(NULL),
  m_pixelArraySize(0)
{
}

Bitmap::Bitmap(const Bitmap &other)
	:m_bitmapFileHeader(other.m_bitmapFileHeader),
	m_bitmapInfoHeader(other.m_bitmapInfoHeader),
	p_pixelArray(other.p_pixelArray),
	p_file(other.p_file),
  m_pixelArraySize(other.m_pixelArraySize)
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
    m_pixelArraySize = other.m_pixelArraySize;
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
  if(p_pixelArray == NULL)
    p_pixelArray = (unsigned char*)malloc(m_pixelArraySize);

  memset(p_pixelArray, 0xff, m_pixelArraySize);
  memcpy(p_pixelArray, pixelArray, m_pixelArraySize);
}

void Bitmap::setBitmapSize(DWORD size)
{
  this->m_bitmapFileHeader.m_size = size;
  this->m_pixelArraySize = size - (14 + 40);
}

void Bitmap::setPixelArraySize(unsigned int size)
{
  this->m_bitmapFileHeader.m_size += size;
  this->m_pixelArraySize = size;
}

void Bitmap::setBitmapWidth(LONG width)
{
  this->m_bitmapInfoHeader.m_width = width;
}

void Bitmap::setBitmapHeight(LONG height)
{
  this->m_bitmapInfoHeader.m_height = -height;
}

void Bitmap::setBitCount(WORD bitCount)
{
  this->m_bitmapInfoHeader.m_bitCount = bitCount;
}

void Bitmap::write(char *filename)
{
  if (!(fopen_s(&p_file, filename, "wb")) && (m_pixelArraySize > 0))
  {
    fwrite(&m_bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, p_file);
    fwrite(&m_bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, p_file);
    fwrite(p_pixelArray, sizeof(unsigned char), m_pixelArraySize, p_file);

    fclose(p_file);
  }
}

void Bitmap::show(char *filename)
{

}
