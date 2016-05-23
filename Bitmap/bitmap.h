#ifndef BITMAP_H
#define BITMAP_H

#include <stdio.h>
#include <iostream>

using namespace std;

// typedef
typedef unsigned short  WORD;
typedef unsigned long   DWORD;
typedef signed long     LONG;

// define
#define BI_RGB          0L


// I don't know what is the use of this??
// Please find it.
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


class Bitmap
{
public:
  Bitmap();
  Bitmap(const BITMAPFILEHEADER &bmpFileHeader, const BITMAPINFOHEADER &bmpInfoHeader);
  Bitmap(const Bitmap &other);
  ~Bitmap(void);

  Bitmap& operator=(const Bitmap &other);

  // Methods
  void setFileHeader(const BITMAPFILEHEADER &bmpFileHeader);
  BITMAPFILEHEADER getFileHeader() const;
  void setInfoHeader(const BITMAPINFOHEADER &bmpInfoHeader);
  BITMAPINFOHEADER getInfoHeader() const;
  void setPixelArray(unsigned char *pixelArray);

  void setBitmapSize(DWORD size);
  void setPixelArraySize(unsigned int size);
  void setBitmapWidth(LONG width);
  void setBitmapHeight(LONG height);
  void setBitCount(WORD bitCount);

  void write(char *filename);
  void show(char *filename);

private:
  BITMAPFILEHEADER  m_bitmapFileHeader;
  BITMAPINFOHEADER  m_bitmapInfoHeader;
  unsigned char*    p_pixelArray;
  FILE*             p_file;
  DWORD             m_pixelArraySize;
};

#endif
