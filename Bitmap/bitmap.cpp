#include "bitmap.h"


Bitmap::Bitmap()
  :m_bitmapFileHeader(),
  m_bitmapInfoHeader(),
  p_pixelArray(NULL),
  p_file(NULL)
{
}

Bitmap::Bitmap(LONG imageWidth, LONG imageHeight)
  :m_bitmapFileHeader(),
  m_bitmapInfoHeader(),
  p_pixelArray(NULL),
  p_file(NULL)
{
  m_bitmapInfoHeader.m_width = imageWidth;
  m_bitmapInfoHeader.m_height = imageHeight;
  m_bitmapFileHeader.m_size += calculatePixelArraySize();
}

Bitmap::Bitmap(LONG imageWidth, LONG imageHeight, WORD bitCount)
  :m_bitmapFileHeader(),
  m_bitmapInfoHeader(),
  p_pixelArray(NULL),
  p_file(NULL)
{
  m_bitmapInfoHeader.m_width = imageWidth;
  m_bitmapInfoHeader.m_height = imageHeight;
  m_bitmapInfoHeader.m_bitCount = bitCount;
  m_bitmapFileHeader.m_size += calculatePixelArraySize();
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

void Bitmap::setPixelArray(unsigned char *pixelArray)
{
  DWORD pixelArraySize = calculatePixelArraySize();
  if(pixelArraySize > 0)
  {
    if(p_pixelArray == NULL)
      p_pixelArray = (unsigned char*)malloc(pixelArraySize);

    //memset(p_pixelArray, 0xff, m_pixelArraySize);
    memcpy(p_pixelArray, pixelArray, pixelArraySize);
  }
}

void Bitmap::setWidth(LONG width)
{
  this->m_bitmapInfoHeader.m_width = width;
}

void Bitmap::setHeight(LONG height)
{
  this->m_bitmapInfoHeader.m_height = -height;
}

void Bitmap::setSize(LONG width, LONG height)
{
  this->m_bitmapInfoHeader.m_width = width;
  this->m_bitmapInfoHeader.m_height = -height;
}

void Bitmap::setBitCount(WORD bitCount)
{
  this->m_bitmapInfoHeader.m_bitCount = bitCount;
}

void Bitmap::writeToFile(char *filename)
{
  DWORD pixelArraySize = calculatePixelArraySize();

  if (!(fopen_s(&p_file, filename, "wb")) && (pixelArraySize > 0))
  {
    // set proper size of the bitmap file including pixel array size.
    if(m_bitmapFileHeader.m_size == (14 + 40))
      m_bitmapFileHeader.m_size += pixelArraySize;

    fwrite(&m_bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, p_file);
    fwrite(&m_bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, p_file);
    if( convertRGBAToFileFormat() )
      fwrite(p_pixelArray, sizeof(unsigned char), pixelArraySize, p_file);

    fclose(p_file);
  }
}

void Bitmap::readFromFile(char *filename)
{

}

DWORD Bitmap::calculatePixelArraySize()
{
  DWORD pixelArraySize = 0;

  if((abs(m_bitmapInfoHeader.m_width) > 0) && 
      (abs(m_bitmapInfoHeader.m_height) > 0) && 
      (m_bitmapInfoHeader.m_bitCount > 0))
  {
    // get Row size
    DWORD rowSize = (DWORD)(floor((((abs(m_bitmapInfoHeader.m_bitCount) * abs(m_bitmapInfoHeader.m_width)) + 31)/32)) * 4);

    // get Pixel Array Size
    pixelArraySize = rowSize * abs(m_bitmapInfoHeader.m_height);
  }

  return(pixelArraySize);
}

void Bitmap::setPixel(int row, int col, const RGBApixel &rgbaPixel)
{
  m_pixels[row][col] = rgbaPixel;
}

void Bitmap::setPixel(int row, int col, int red, int green, int blue)
{
  RGBApixel rgbaPixel((unsigned char)red, (unsigned char)green, (unsigned char)blue);

  m_pixels[row][col] = rgbaPixel;
}

void Bitmap::setPixel(int row, int col, int red, int green, int blue, int alpha)
{
  RGBApixel rgbaPixel((unsigned char)red, (unsigned char)green, (unsigned char)blue, (unsigned char)alpha);

  m_pixels[row][col] = rgbaPixel;
}

RGBApixel Bitmap::getPixel(int row, int col)
{
  return(m_pixels[row][col]);
}

bool Bitmap::convertRGBAToFileFormat()
{
  bool status = false;
  DWORD pixelArraySize = calculatePixelArraySize();

  if(pixelArraySize > 0)
  {
    if(p_pixelArray != NULL)
      p_pixelArray = (unsigned char*)malloc(pixelArraySize);

    if(p_pixelArray != NULL)
    {
      int c = 0;
      for(int i = 0; i < m_bitmapInfoHeader.m_width; ++i)
      {
        for(int j = 0; j < m_bitmapInfoHeader.m_height; ++j)
        {
          p_pixelArray[ c + 0 ] = m_pixels[i][j].red;
          p_pixelArray[ c + 1 ] = m_pixels[i][j].green;
          p_pixelArray[ c + 2 ] = m_pixels[i][j].blue;

          c += 3;
        }
      }

      status = true;
    }
  }

  return(status);
}
