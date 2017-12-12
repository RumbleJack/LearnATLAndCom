#pragma once
#include "ImageTools_i.h"
#include "rawimage.h"
class CRGBImage :
	public CRawImage <COM_STRUCT_CLR_RGB>
{
public:
	CRGBImage(void);
	CRGBImage(int Width, int Height);
	~CRGBImage(void);
	int ImportImageBlock(int x0, int y0, int Width, int Height, BYTE *pPixels) ;
	int ImportImageBlock(int x0, int y0, int Width, int Height, COM_STRUCT_CLR_BGR *pPixels) ;
	int ImportImageBlock(int x0, int y0, int Width, int Height, COM_STRUCT_CLR_RGB *pPixels)
	{
		return CRawImage <COM_STRUCT_CLR_RGB> ::ImportImageBlock(x0, y0, Width, Height, pPixels) ;
	}
	BOOL SetPixel(int x, int y, BYTE Gray)
	{
		COM_STRUCT_CLR_RGB PxlVal = {Gray, Gray, Gray} ;
		return CRawImage <COM_STRUCT_CLR_RGB> ::SetPixel(x, y, PxlVal) ;
	}
	BOOL SetPixel(int x, int y, COM_STRUCT_CLR_RGB PxlVal)
	{
		return CRawImage <COM_STRUCT_CLR_RGB> ::SetPixel(x, y, PxlVal) ;
	}
	BOOL SetPixel(int x, int y, BYTE Red, BYTE Green, BYTE Blue)
	{
		COM_STRUCT_CLR_RGB PxlVal = {Red, Green, Blue} ;
		return CRawImage <COM_STRUCT_CLR_RGB> ::SetPixel(x, y, PxlVal) ;
	}
};

