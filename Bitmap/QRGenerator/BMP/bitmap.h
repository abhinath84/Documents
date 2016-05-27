#ifndef BITMAP_H
#define BITMAP_H

#include <stdio.h>
#include <math.h>

#include <iostream>
#include <vector>

using namespace std;

// typedef
typedef unsigned short  WORD;
typedef unsigned long   DWORD;
typedef signed long     LONG;

// define
#define BI_RGB          0L


// To pack a class is to place its members directly after each other in memory, 
// which can mean that some or all members can be aligned on a boundary smaller 
// than the default alignment the target architecture.
#pragma pack(push, 2)


// BITMAPFILEHEADER
// Store the general information about  the  BITMAP Image File.
typedef struct BitmapFileHeader
{
  BitmapFileHeader()
  {
    this->m_type  = 0x4d42;         // "BM"
    this->m_size = (14 + 40);       //sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
    this->m_reserved1 = 0;
    this->m_reserved2 = 0;
    this->m_offBits = (14 + 40);    //sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
  }

  BitmapFileHeader(DWORD size, WORD res1, WORD res2)
  {
    this->m_type  = 0x4d42;         // "BM"
    this->m_size = size;
    this->m_reserved1 = res1;
    this->m_reserved2 = res2;
    this->m_offBits = (14 + 40);    //sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
  }

  // member variables.
  WORD    m_type;
  DWORD   m_size;
  WORD    m_reserved1;
  WORD    m_reserved2;
  DWORD   m_offBits;
}BITMAPFILEHEADER;

// BITMAPINFOHEADER
// Store the detailed information about BITMAP Image 
// and define the pixel format.
typedef struct BitmapInfoHeader
{
  BitmapInfoHeader()
  {
    this->m_size = 40;                  //sizeof(BitmapInfoHeader);
    this->m_width = 0;
    this->m_height = -0;
    this->m_planes = 1;
    this->m_bitCount = 24;
    this->m_compression = BI_RGB;
    this->m_sizeImage = 0;
    this->m_xPelsPerMeter = 0;
    this->m_yPelsPerMeter = 0;
    this->m_clrUsed = 0;
    this->m_clrImportant = 0;
  }

  BitmapInfoHeader(LONG width, LONG height, WORD bitCount, 
                    DWORD sizeImage, LONG xPelsPerMeter, 
                    LONG yPelsPerMeter, DWORD clrUsed, DWORD clrImportant)
  {
    this->m_size = 40;                  //sizeof(BitmapInfoHeader);
    this->m_width = width;
    this->m_height = -height;
    this->m_planes = 1;
    this->m_bitCount = bitCount;
    this->m_compression = BI_RGB;
    this->m_sizeImage = sizeImage;
    this->m_xPelsPerMeter = xPelsPerMeter;
    this->m_yPelsPerMeter = yPelsPerMeter;
    this->m_clrUsed = clrUsed;
    this->m_clrImportant = clrImportant;
  }

  // member variables
  DWORD      m_size;
  LONG       m_width;
  LONG       m_height;
  WORD       m_planes;
  WORD       m_bitCount;
  DWORD      m_compression;
  DWORD      m_sizeImage;
  LONG       m_xPelsPerMeter;
  LONG       m_yPelsPerMeter;
  DWORD      m_clrUsed;
  DWORD      m_clrImportant;
}BITMAPINFOHEADER;

#pragma pack(pop)


struct RGBApixel
{
  RGBApixel()
  {
    red = 0;
    green = 0;
    blue = 0;
    alpha = 0;
  }

  RGBApixel(unsigned char r, unsigned char g, unsigned char b)
  {
    red = r;
    green = g;
    blue = b;
    alpha = 0;
  }

  RGBApixel(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
  {
    red = r;
    green = g;
    blue = b;
    alpha = a;
  }

  unsigned char red;
  unsigned char green;
  unsigned char blue;
  unsigned char alpha;
};


class Bitmap
{
public:
  Bitmap();
  Bitmap(LONG imageWidth, LONG imageHeight);
  Bitmap(LONG imageWidth, LONG imageHeight, WORD bitCount);
  Bitmap(const Bitmap &other);
  ~Bitmap(void);

  Bitmap& operator=(const Bitmap &other);

  // Methods
  void setPixelArray(unsigned char *pixelArray);

  void setPixel(int row, int col, const RGBApixel &rgbaPixel);
  void setPixel(int row, int col, int red, int green, int blue);
  void setPixel(int row, int col, int red, int green, int blue, int alpha);
  RGBApixel getPixel(int row, int col);

  void setWidth(LONG width);
  void setHeight(LONG height);
  void setSize(LONG width, LONG height);
  void setBitCount(WORD bitCount);

  void writeToFile(char *filename);
  void readFromFile(char *filename);

private:
  DWORD calculatePixelArraySize();
  //bool  convertRGBAToFileFormat();
  int   getCurrentPos(int row, int col);
  void  setPixelLow(int row, int col, int red, int green, int blue, int alpha);

private:
  BITMAPFILEHEADER  m_bitmapFileHeader;
  BITMAPINFOHEADER  m_bitmapInfoHeader;
  unsigned char*    p_pixelArray;
  //vector< vector<RGBApixel> > m_pixels;
  FILE*             p_file;
};

#endif
