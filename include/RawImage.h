#pragma once
#include <Windows.h>
#include "SafeArray.h"

template <class T_PXL>
class CRawImage
{
public :
	CRawImage()
		: mWidth(0)
		, mHeight(0)
	{
	}

	CRawImage(int Width, int Height)
		: mWidth(Width)
		, mHeight(Height)
		, mPixels(mWidth*mHeight)
	{
	}
	
	~CRawImage()
	{
	}

	BOOL Create(int Width, int Height)
	{
		if(Width > 0 && Height > 0)
		{
			mWidth = Width ;
			mHeight = Height ;
			mPixels.Create(mWidth * mHeight) ;
			return TRUE ;
		}
		else
		{
			Destroy() ;
			return FALSE ;
		}
	}
	
	void Destroy()
	{
		mWidth = mHeight = 0 ;
		mPixels.FreeAll() ;
	}

	// return: cnt of copied pixels
	int ImportImageBlock(int x0, int y0, int Width, int Height, T_PXL *pPixels) 
	{
		int CopyWidth = min(Width, mWidth - x0) ;
		int CopyHeight = min(Height, mHeight - y0) ;
		if(CopyWidth > 0 && CopyHeight > 0)
		{
			T_PXL *pTargPxl = mPixels.GetPtrToArray() + y0 * mWidth + x0 ;
			for(int i = 0 ; i < CopyHeight ; ++i, pTargPxl += mWidth, pPixels += Width)
				memcpy(pTargPxl, pPixels, CopyWidth * sizeof(T_PXL)) ;
			
			return CopyWidth * CopyHeight ;
		}
		else
			return 0 ;
	}

	int ExportImageBlock(int x0, int y0, int Width, int Height, T_PXL *pPixels) 
	{
		memset(pPixels, 0, Width * Height * sizeof(T_PXL)) ;
		int CopyWidth = min(Width, mWidth - x0) ;
		int CopyHeight = min(Height, mHeight - y0) ;
		if(CopyWidth > 0 && CopyHeight > 0)
		{
			T_PXL *pTargPxl = mPixels.GetPtrToArray() + y0 * mWidth + x0 ;
			for(int i = 0 ; i < CopyHeight ; ++i, pTargPxl += mWidth, pPixels += Width)
				memcpy(pPixels, pTargPxl, CopyWidth * sizeof(T_PXL)) ;
			
			return CopyWidth * CopyHeight ;
		}
		else
			return 0 ;
	}

	BOOL SetPixel(int x, int y, T_PXL PxlVal)
	{
		if(CheckValidPixelPosition(x, y))
		{
			mPixels[x+y*mWidth] = PxlVal ;
			return TRUE ;
		}
		else
			return FALSE ;
	}

	BOOL CheckEmpty()
	{
		return mWidth <= 0 || mHeight <= 0 || mPixels.GetArraySize() <= 0 ;
	}

	BOOL CheckValid()
	{
		return mWidth > 0 && mHeight > 0 && mPixels.GetArraySize() > 0 ;
	}

	BOOL CheckValidPixelPosition(int x, int y)
	{
		return x >= 0 && x < mWidth && y >= 0 && y < mHeight ;
	}

	BOOL GetPixel(int x, int y, T_PXL *pPxlVal)
	{
		if(CheckValidPixelPosition(x, y))
		{
			*pPxlVal = mPixels[x+y*mWidth] ;
			return TRUE ;
		}
		else
			return FALSE ;
	}
		
	void Reset()
	{
		if(CheckValid())
			memset(mPixels.GetPtrToArray(), 0, mWidth * mHeight * sizeof(T_PXL)) ;
	}

	BOOL ImportFullSizeImage(T_PXL *pPixels)
	{
		if(CheckValid())
		{
			mPixels.Copy(pPixels) ;
			return TRUE ;
		}
		else
			return FALSE ;
	}

	BOOL ExportFullSizeImage(T_PXL *pPixels)
	{
		if(CheckValid())
		{
			mPixels.ExportData(pPixels) ;
			return TRUE ;
		}
		else
			return FALSE ;
	}
	T_PXL *GetPtrToImageData()
	{
		return mPixels.GetPtrToArray() ;
	}
	void GetImageSize(int *pWidth, int *pHeight)
	{
		*pWidth = mWidth ;
		*pHeight = mHeight ;
	}

protected :
	int	mWidth, mHeight ;
	CSafeArray <T_PXL> mPixels ;
} ;