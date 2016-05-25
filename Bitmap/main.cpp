#include <iostream>
#include <math.h>

#include "bitmap.h"

using namespace std;

int main(int argc, char **argv)
{
  int bmpWidth = 200;
  int bmpHeight = 150;

  DWORD rowSize = (DWORD)(floor((((24 * bmpWidth) + 31)/32)) * 4);
  DWORD pixelArraySize = rowSize * bmpHeight;
  unsigned char *buf = new unsigned char[ pixelArraySize ];
  //memset(buf, 0xff, pixelArraySize);

  int c = 0;
  for ( int i = 0; i < bmpHeight; i++ )
  {
    for ( int j = 0; j < bmpWidth; j++ )
      {
        int red = (((j%3) == 0) ? 255 : 0);
        int green = (((j/3) == 1) ? 255 : 0);
        int blue = (((j/3) == 2) ? 255 : 0);

        buf[ c + 0 ] = (unsigned char) red;
        buf[ c + 1 ] = (unsigned char) green;
        buf[ c + 2 ] = (unsigned char) blue;

        c += 3;
      }
  }

  Bitmap bmp(bmpWidth, bmpHeight);
  for ( int i = 0; i < bmpHeight; i++ )
  {
    for ( int j = 0; j < bmpWidth; j++ )
    {
      int red = (((j%3) == 0) ? 255 : 0);
      int green = (((j/3) == 1) ? 255 : 0);
      int blue = (((j/3) == 2) ? 255 : 0);

      bmp.setPixel((i + 1), (j + 1), red, green, blue);
    }
  }

  //bmp.setPixelArray(buf);
  bmp.writeToFile("test.bmp");

  //system("pause");
  return(0);
}
