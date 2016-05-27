//	---------------------------------------------------------------------------
//		
//		QRGenerator
//
//		Create:			15/05/2013
//		Last update:	15/05/2013
//
//		Author:	TWOTM
//
//
//		Note:
//
//		/o ULTRAMUNDUM FOUNDATION - all rights reserved
//	---------------------------------------------------------------------------


//	-------------------------------------------------------
//	Includes
//	-------------------------------------------------------

#include "stdafx.h"
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <wchar.h>

#include "qrencode.h"
#include "bitmap.h"
//	-------------------------------------------------------


//	-------------------------------------------------------
//	DEFines
//	-------------------------------------------------------

#define QRCODE_TEXT					"Creo 3.0 - Mfg model" //"http://www.ultramundum.org/index.htm";		// Text to encode into QRCode
<<<<<<< HEAD
#define OUT_FILE					"F:\\PTC_Me\\My Projects\\C++\\Others\\QRGenerator\\Release\\test.bmp"								// Output file name
=======
#define OUT_FILE					"E:\\Project\\Practice\\C++\\QRGenerator\\Release\\test.bmp"								// Output file name
>>>>>>> d521331875f6783e8856ce8fc1c2ef1ed7497ee6
#define OUT_FILE_PIXEL_PRESCALER	8											// Prescaler (number of pixels in bmp file for each QRCode pixel, on each dimension)

#define PIXEL_COLOR_R				0											// Color of bmp pixels
#define PIXEL_COLOR_G				0
#define PIXEL_COLOR_B				0xff

//	-------------------------------------------------------
//	Main
//	-------------------------------------------------------

int _tmain(int argc, _TCHAR* argv[])
{
<<<<<<< HEAD
char            *szSourceSring = QRCODE_TEXT;
unsigned int    unWidth, x, y, l, n;
unsigned char   *pSourceData;
QRcode*         pQRC;
=======
char*			szSourceSring = QRCODE_TEXT;
unsigned int	unWidth, x, y, l, n, unWidthAdjusted, unDataBytes;
unsigned char*	pRGBData, *pSourceData, *pDestData;
QRcode*			pQRC;
//FILE*			f;
>>>>>>> d521331875f6783e8856ce8fc1c2ef1ed7497ee6

/*
 * Create a symbol from the string. The library automatically parses the input
 * string and encodes in a QR Code symbol.
 * @warning This function is THREAD UNSAFE when pthread is disabled.
 * @param string input string. It must be NUL terminated.
 * @param version version of the symbol. If 0, the library chooses the minimum
 *                version for the given input data.
 * @param level error correction level.
 * @param hint tell the library how non-alphanumerical characters should be
 *             encoded. If QR_MODE_KANJI is given, kanji characters will be
 *             encoded as Shif-JIS characters. If QR_MODE_8 is given, all of
 *             non-alphanumerical characters will be encoded as is. If you want
 *             to embed UTF-8 string, choose this.
 * @param casesensitive case-sensitive(1) or not(0).
 * @return an instance of QRcode class. The version of the result QRcode may
 *         be larger than the designated version. On error, NULL is returned,
 *         and errno is set to indicate the error. See Exceptions for the
 *         details.
 * @throw EINVAL invalid input object.
 * @throw ENOMEM unable to allocate memory for input objects.
 * @throw ERANGE input data is too large.
 */

		// Compute QRCode

<<<<<<< HEAD
  if (pQRC = QRcode_encodeString(szSourceSring, 0, QR_ECLEVEL_H, QR_MODE_8, 1))
  {
    unWidth = pQRC->width;

    // Output the bmp file
    Bitmap bmp(unWidth * OUT_FILE_PIXEL_PRESCALER, unWidth * OUT_FILE_PIXEL_PRESCALER);

    // Convert QrCode bits to bmp pixels
    pSourceData = pQRC->data;
    for(y = 0; y < unWidth; y++)
    {
        for(x = 0; x < unWidth; x++)
        {
          if (*pSourceData & 1)
          {
            for(l = 0; l < OUT_FILE_PIXEL_PRESCALER; l++)
            {
              for(n = 0; n < OUT_FILE_PIXEL_PRESCALER; n++)
              {
                bmp.setPixel(l + (x * OUT_FILE_PIXEL_PRESCALER), 
                                  n + (y * OUT_FILE_PIXEL_PRESCALER), 
                                  PIXEL_COLOR_B, PIXEL_COLOR_G, PIXEL_COLOR_R);
              }
            }
          }
          pSourceData++;
        }
    }

    // write to file
    bmp.writeToFile(OUT_FILE);

    // Free data
    QRcode_free(pQRC);
  }
  else
  {
    printf("NULL returned");
    exit(-1);
  }

  return 0;
}
//	-------------------------------------------------------
=======
	if (pQRC = QRcode_encodeString(szSourceSring, 0, QR_ECLEVEL_H, QR_MODE_8, 1))
		{
		unWidth = pQRC->width;
		unWidthAdjusted = unWidth * OUT_FILE_PIXEL_PRESCALER * 3;
		if (unWidthAdjusted % 4)
			unWidthAdjusted = (unWidthAdjusted / 4 + 1) * 4;
		unDataBytes = unWidthAdjusted * unWidth * OUT_FILE_PIXEL_PRESCALER;

			// Allocate pixels buffer

		if (!(pRGBData = (unsigned char*)malloc(unDataBytes)))
			{
			printf("Out of memory");
			exit(-1);
			}
			
			// Preset to white

		memset(pRGBData, 0xff, unDataBytes);


		// Convert QrCode bits to bmp pixels

		//pSourceData = pQRC->data;
		//for(y = 0; y < unWidth; y++)
		//	{
		//	pDestData = pRGBData + unWidthAdjusted * y * OUT_FILE_PIXEL_PRESCALER;
		//	for(x = 0; x < unWidth; x++)
		//		{
		//		if (*pSourceData & 1)
		//			{
		//			for(l = 0; l < OUT_FILE_PIXEL_PRESCALER; l++)
		//				{
		//				for(n = 0; n < OUT_FILE_PIXEL_PRESCALER; n++)
		//					{
		//					*(pDestData +		n * 3 + unWidthAdjusted * l) =	PIXEL_COLOR_B;
		//					*(pDestData + 1 +	n * 3 + unWidthAdjusted * l) =	PIXEL_COLOR_G;
		//					*(pDestData + 2 +	n * 3 + unWidthAdjusted * l) =	PIXEL_COLOR_R;
		//					}
		//				}
		//			}
		//		pDestData += 3 * OUT_FILE_PIXEL_PRESCALER;
		//		pSourceData++;
		//		}
		//	}


	  // Output the bmp file
    Bitmap bmp(unWidth * OUT_FILE_PIXEL_PRESCALER, unWidth * OUT_FILE_PIXEL_PRESCALER);
    pSourceData = pQRC->data;
    for(y = 0; y < unWidth; y++)
    {
        pDestData = pRGBData + unWidthAdjusted * y * OUT_FILE_PIXEL_PRESCALER;
        for(x = 0; x < unWidth; x++)
        {
            if (*pSourceData & 1)
		        {
		            for(l = 0; l < OUT_FILE_PIXEL_PRESCALER; l++)
		            {
		                for(n = 0; n < OUT_FILE_PIXEL_PRESCALER; n++)
				            {
                        bmp.setPixel(l + (x * OUT_FILE_PIXEL_PRESCALER), n + (y * OUT_FILE_PIXEL_PRESCALER), 
                                        PIXEL_COLOR_B, PIXEL_COLOR_G, PIXEL_COLOR_R);

				                *(pDestData +		n * 3 + unWidthAdjusted * l) =	PIXEL_COLOR_B;
				                *(pDestData + 1 +	n * 3 + unWidthAdjusted * l) =	PIXEL_COLOR_G;
				                *(pDestData + 2 +	n * 3 + unWidthAdjusted * l) =	PIXEL_COLOR_R;
				            }
		            }
		        }
            pDestData += 3 * OUT_FILE_PIXEL_PRESCALER;
            pSourceData++;
        }
    }
    //bmp.setPixelArray(pRGBData);
    bmp.writeToFile(OUT_FILE);

			// Free data

		free(pRGBData);
		QRcode_free(pQRC);
		}
	else
		{
		printf("NULL returned");
		exit(-1);
		}

	return 0;
}
//	-------------------------------------------------------

>>>>>>> d521331875f6783e8856ce8fc1c2ef1ed7497ee6
