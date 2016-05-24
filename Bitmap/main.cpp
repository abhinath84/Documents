#include <iostream>

#include "bitmap.h"

using namespace std;

int main(int argc, char **argv)
{
  int bmpWidth = 200;
  int bmpHeight = 128;

  int unWidthAdjusted = bmpWidth * 3;
  if (unWidthAdjusted % 4)
    unWidthAdjusted = (unWidthAdjusted / 4 + 1) * 4;

  int pixelArraySize = unWidthAdjusted * bmpHeight;
  unsigned char *buf = new unsigned char[ pixelArraySize ];
  int c = 0;
  
  for ( int i = 0; i < 128; i++ )
  {
      for ( int j = 0; j < 128; j++ )
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

  Bitmap bmp;
  bmp.setBitmapWidth(bmpWidth);
  bmp.setBitmapHeight(bmpHeight);
  bmp.setPixelArraySize( pixelArraySize );
  bmp.setPixelArray(buf);
  bmp.write("test.bmp");

  //system("pause");
  return(0);
}
