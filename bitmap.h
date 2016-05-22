#ifndef BITMAP_H
#define BITMAP_H

#include <stdio.h>
#include <iostream>

using namespace std;

// typedef
typedef unsigned short	WORD;
typedef unsigned long	DWORD;
typedef signed long		LONG;

// I don't know what is the use of this??
// Please find it.
#pragma pack(push, 2)

// BITMAPFILEHEADER
// Store the general information about  the  BITMAP Image File.
typedef struct BitmapFileHeader
{
	WORD    type;
	DWORD   size;
	WORD    reserved1;
	WORD    reserved2;
	DWORD   offBits;
}BITMAPFILEHEADER;

// BITMAPINFOHEADER
// Store the detailed information about BITMAP Image 
// and define the pixel format.
typedef struct BitmapInfoHeader
{
	DWORD      size;
	LONG       width;
	LONG       height;
	WORD       planes;
	WORD       bitCount;
	DWORD      compression;
	DWORD      sizeImage;
	LONG       xPelsPerMeter;
	LONG       yPelsPerMeter;
	DWORD      clrUsed;
	DWORD      clrImportant;
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
	void setRGBData(unsigned char *rgbData);

	void write(char *filename);
	void show(char *filename);

private:
	BITMAPFILEHEADER	m_bitmapFileHeader;
	BITMAPINFOHEADER	m_bitmapInfoHeader;
	unsigned char*		p_rgbData;
	FILE*				p_file;
};

#endif
