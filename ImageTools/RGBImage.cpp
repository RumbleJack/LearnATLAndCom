#include "StdAfx.h"
#include "RGBImage.h"


CRGBImage::CRGBImage(void)
	: CRawImage <COM_STRUCT_CLR_RGB> ()
{
}

CRGBImage::CRGBImage(int Width, int Height)
	: CRawImage <COM_STRUCT_CLR_RGB> (Width, Height)
{
}

CRGBImage::~CRGBImage(void)
{
}

int CRGBImage::ImportImageBlock(int x0, int y0, int Width, int Height, BYTE *pPixels)
{
	int CopyHeight = min(Height, mHeight-y0) ;
	int CopyWidth = min(Width, mWidth - x0) ;
	if(CopyHeight > 0 && CopyWidth > 0)
	{
		COM_STRUCT_CLR_RGB *pImgLn = mPixels.GetPtrToArray() + y0 * mWidth + x0;
		BYTE *pSrcImgLn = pPixels ;
		for(int y = 0 ; y < CopyHeight ; ++y, pImgLn += mWidth, pSrcImgLn += Width)
		{
			for(int x = 0 ; x < CopyWidth ; ++x)
				(pImgLn + x)->red = (pImgLn + x)->green = (pImgLn + x)->blue = *(pSrcImgLn + x) ;
		}
		return CopyWidth * CopyHeight ;
	}
	return 0 ;
}

int CRGBImage::ImportImageBlock(int x0, int y0, int Width, int Height, COM_STRUCT_CLR_BGR *pPixels)
{
	int CopyHeight = min(Height, mHeight-y0) ;
	int CopyWidth = min(Width, mWidth - x0) ;
	if(CopyHeight > 0 && CopyWidth > 0)
	{
		COM_STRUCT_CLR_RGB *pImgLn = mPixels.GetPtrToArray() + y0 * mWidth + x0;
		COM_STRUCT_CLR_BGR *pSrcImgLn = pPixels ;
		for(int y = 0 ; y < CopyHeight ; ++y, pImgLn += mWidth, pSrcImgLn += Width)
		{
			for(int x = 0 ; x < CopyWidth ; ++x)
			{
				(pImgLn + x)->red = (pSrcImgLn + x)->red ;
				(pImgLn + x)->green = (pSrcImgLn + x)->green ;
				(pImgLn + x)->blue = (pSrcImgLn + x)->blue ;
			}
		}
		return CopyWidth * CopyHeight ;
	}
	return 0 ;
}