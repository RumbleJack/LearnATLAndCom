// ImageToDrawWithLabelLayer.cpp : CImageToDrawWithLabelLayer 的实现

#include "stdafx.h"
#include "ImageToDrawWithLabelLayer.h"
#include "PubRet.h"

// CImageToDrawWithLabelLayer



STDMETHODIMP CImageToDrawWithLabelLayer::CheckValid(void)
{
	if(mWidth > 0 && mHeight > 0)
		return S_OK;
	else
		return MAKE_OWN_FAIL_RESULT(ERR_CODE_EMPTY) ;
}


STDMETHODIMP CImageToDrawWithLabelLayer::CreateImage(LONG Width, LONG Height)
{
	mWidth = Width ;
	mHeight = Height ;
	if(mWidth > 0 && mHeight > 0)
	{
		mBaseImage.Create(mWidth, mHeight) ;
		mLabel.Create(mWidth, mHeight) ;
		mLabeledImage.Create(mWidth, mHeight) ;
		ResetImage() ;
		return ResetLabelLayer() ;
	}
	else
	{
		Destroy() ;
		return MAKE_OWN_FAIL_RESULT(ERR_CODE_PARAMETER) ;
	}
}


STDMETHODIMP CImageToDrawWithLabelLayer::GetImageSize(LONG* pWidth, LONG* pHeight)
{
	*pWidth = mWidth ;
	*pHeight = mHeight ;

	return mWidth > 0 && mHeight > 0 ? S_OK : MAKE_OWN_FAIL_RESULT(ERR_CODE_EMPTY) ;
}


STDMETHODIMP CImageToDrawWithLabelLayer::ImportFullSizeImage(COM_ENUM_PIXEL_STYLE PixelStyle, BYTE * pPixel)
{
	if(mBaseImage.CheckValid())
	{
		switch(PixelStyle)
		{
		case COM_GRAY_BYTE :
			mBaseImage.ImportImageBlock(0, 0, mWidth, mHeight, pPixel) ;
			break ;
		case COM_CLR_RGB :
			mBaseImage.ImportFullSizeImage((COM_STRUCT_CLR_RGB *)pPixel) ;
			break ;
		case COM_CLR_BGR :
			mBaseImage.ImportImageBlock(0, 0, mWidth, mHeight, (COM_STRUCT_CLR_BGR *)pPixel) ;
			break ;
		}
		return S_OK ;
	}
	else
		return MAKE_OWN_FAIL_RESULT(ERR_CODE_EMPTY) ;
}


STDMETHODIMP CImageToDrawWithLabelLayer::ImportImage(COM_ENUM_PIXEL_STYLE PixelStyle, LONG x0, LONG y0, LONG Width, LONG Height, BYTE * pPixel)
{
	
	if(mBaseImage.CheckValid())
	{
		switch(PixelStyle)
		{
		case COM_GRAY_BYTE :
			mBaseImage.ImportImageBlock(x0, y0, Width, Height, pPixel) ;
			break ;
		case COM_CLR_RGB :
			mBaseImage.ImportImageBlock(x0, y0, Width, Height, (COM_STRUCT_CLR_RGB *)pPixel) ;
			break ;
		case COM_CLR_BGR :
			mBaseImage.ImportImageBlock(x0, y0, Width, Height, (COM_STRUCT_CLR_BGR *)pPixel) ;
			break ;
		}
		return S_OK ;
	}
	else
		return MAKE_OWN_FAIL_RESULT(ERR_CODE_EMPTY) ;
}


STDMETHODIMP CImageToDrawWithLabelLayer::ResetImage()
{
	if(mWidth > 0 && mHeight > 0)
	{
		mBaseImage ;
		mLabeledImage.Reset() ;
		return S_OK;
	}
	return MAKE_OWN_FAIL_RESULT(ERR_CODE_EMPTY) ;
}


STDMETHODIMP CImageToDrawWithLabelLayer::Destroy(void)
{
	mWidth = 0 ;
	mHeight = 0 ;
	mBaseImage.Destroy() ;
	mLabel.Destroy() ;
	mLabeledImage.Destroy() ;
	return S_OK;
}


STDMETHODIMP CImageToDrawWithLabelLayer::SetImageLayerPixel(LONG x, LONG y, BYTE red, BYTE green, BYTE blue)
{
	return mBaseImage.SetPixel(x, y, red, green, blue) ? S_OK : MAKE_OWN_FAIL_RESULT(ERR_CODE_PARAMETER) ;
}


STDMETHODIMP CImageToDrawWithLabelLayer::ExportImageLayer(LONG x0, LONG y0, LONG Width, LONG Height, COM_STRUCT_CLR_RGB * pDataBuf)
{
	memset(pDataBuf, 0, Width * Height * sizeof(COM_STRUCT_CLR_RGB)) ;
	if(mBaseImage.ExportImageBlock(x0, y0, Width, Height, pDataBuf) > 0)
		return S_OK;
	else
		return MAKE_OWN_FAIL_RESULT(ERR_CODE_EMPTY) ;
}


STDMETHODIMP CImageToDrawWithLabelLayer::GetImageLayerPixel(LONG x, LONG y, BYTE* pRed, BYTE* pGreen, BYTE* pBlue)
{
	COM_STRUCT_CLR_RGB PixelVal ;
	if(mBaseImage.GetPixel(x, y, &PixelVal))
	{
		*pRed = PixelVal.red ;
		*pGreen = PixelVal.green ;
		*pBlue = PixelVal.blue ;
		return S_OK;
	}
	else
		return MAKE_OWN_FAIL_RESULT(ERR_CODE_PARAMETER) ;
}


STDMETHODIMP CImageToDrawWithLabelLayer::ResetLabelLayer()
{
	if(mLabel.CheckValid())
	{
		mLabel.Reset() ;
		return S_OK;
	}
	else
		return MAKE_OWN_FAIL_RESULT(ERR_CODE_EMPTY) ;
}

STDMETHODIMP CImageToDrawWithLabelLayer::SetDefaultLabelColor(BYTE Red, BYTE Green, BYTE Blue, BYTE Alpha)
{
	mLabelColor.red = Red ;
	mLabelColor.green = Green ;
	mLabelColor.blue = Blue ;
	mLabelColor.alpha = Alpha ;
	return S_OK ;
}

STDMETHODIMP CImageToDrawWithLabelLayer::SetLabelLayerPixel(LONG x, LONG y)
{
	if(mLabel.SetPixel(x, y, mLabelColor))
		return S_OK;
	else
		return MAKE_OWN_FAIL_RESULT(ERR_CODE_PARAMETER) ;
}

STDMETHODIMP CImageToDrawWithLabelLayer::SetLabelLayerPixelToColor(LONG x, LONG y, BYTE Red, BYTE Green, BYTE Blue, BYTE Alpha)
{
	COM_STRUCT_CLR_RGBA PxlVal = {Red, Green, Blue, Alpha} ;
	if(mLabel.SetPixel(x, y, PxlVal))
		return S_OK;
	else
		return MAKE_OWN_FAIL_RESULT(ERR_CODE_PARAMETER) ;
}


STDMETHODIMP CImageToDrawWithLabelLayer::ImportLabelLayer(LONG x0, LONG y0, LONG Width, LONG Height, COM_STRUCT_CLR_RGBA* pLayer)
{
	if(mLabel.ImportImageBlock(x0, y0, Width, Height, pLayer) > 0)
		return S_OK;
	else
		return MAKE_OWN_FAIL_RESULT(ERR_CODE_EMPTY) ;
}


STDMETHODIMP CImageToDrawWithLabelLayer::ExportLabelLayer(LONG x0, LONG y0, LONG Width, LONG Height, COM_STRUCT_CLR_RGBA* pBuf)
{
	if(mLabel.ExportImageBlock(x0, y0, Width, Height, pBuf) > 0)
		return S_OK;
	else
		return MAKE_OWN_FAIL_RESULT(ERR_CODE_EMPTY) ;
}


STDMETHODIMP CImageToDrawWithLabelLayer::ExportImageToDraw(LONG x0, LONG y0, LONG Width, LONG Height, COM_STRUCT_CLR_RGB * pBuf)
{
	if(mLabeledImage.ExportImageBlock(x0, y0, Width, Height, pBuf) > 0)
		return S_OK;
	else
		return MAKE_OWN_FAIL_RESULT(ERR_CODE_EMPTY) ;
}


STDMETHODIMP CImageToDrawWithLabelLayer::EnableLabelLayer(LONG Enable)
{
	mLabelFlag = (Enable != 0) ;

	return S_OK;
}


STDMETHODIMP CImageToDrawWithLabelLayer::CheckLabelLayerEnabled()
{
	return mLabelFlag ? S_OK : MAKE_OWN_FAIL_RESULT(ERR_CODE_FALSE);
}


STDMETHODIMP CImageToDrawWithLabelLayer::DrawLine(LONG x0, LONG y0, LONG dx, LONG dy)
{
	// TODO: 在此添加实现代码

	return S_OK;
}


STDMETHODIMP CImageToDrawWithLabelLayer::DrawRect(LONG x0, LONG y0, LONG Width, LONG Height, LONG Fill)
{
	// TODO: 在此添加实现代码

	return S_OK;
}


STDMETHODIMP CImageToDrawWithLabelLayer::DrawCircle(FLOAT xCenter, FLOAT yCenter, FLOAT Radius, LONG Fill)
{
	// TODO: 在此添加实现代码

	return S_OK;
}


STDMETHODIMP CImageToDrawWithLabelLayer::GetPtrToImageLayerData(COM_STRUCT_CLR_RGB ** ppImage)
{
	if(mBaseImage.CheckValid())
	{
		*ppImage = mBaseImage.GetPtrToImageData() ;
		return S_OK;
	}
	else
	{
		*ppImage = NULL ;
		return MAKE_OWN_FAIL_RESULT(ERR_CODE_EMPTY) ;
	}
}


STDMETHODIMP CImageToDrawWithLabelLayer::GetPtrToLabelLayerData(COM_STRUCT_CLR_RGBA ** ppLable)
{
	if(mLabel.CheckValid())
	{
		*ppLable = mLabel.GetPtrToImageData() ;
		return S_OK;
	}
	else
	{
		*ppLable = NULL ;
		return MAKE_OWN_FAIL_RESULT(ERR_CODE_EMPTY) ;
	}
}


STDMETHODIMP CImageToDrawWithLabelLayer::GetPtrToImageToDraw(COM_STRUCT_CLR_RGB ** ppImage)
{
	if(mLabeledImage.CheckValid())
	{
		*ppImage = mLabeledImage.GetPtrToImageData() ;
		return S_OK;
	}
	else
	{
		*ppImage = NULL ;
		return MAKE_OWN_FAIL_RESULT(ERR_CODE_EMPTY) ;
	}
}


STDMETHODIMP CImageToDrawWithLabelLayer::MergeLabelLayerToImage(void)
{
	if(mBaseImage.CheckValid() && mLabeledImage.CheckValid())
	{
		if(mLabel.CheckValid() && mLabelFlag)
		{
			int Width, Height ;
			mBaseImage.GetImageSize(&Width, &Height) ;
			COM_STRUCT_CLR_RGB *pBaseImg = mBaseImage.GetPtrToImageData() ;
			COM_STRUCT_CLR_RGB *pMergeImg = mLabeledImage.GetPtrToImageData() ;
			COM_STRUCT_CLR_RGBA *pLabel = mLabel.GetPtrToImageData() ;
			for(int i = 0 ; i < Width * Height ; ++i, ++pBaseImg, ++pMergeImg, ++pLabel)
			{
				if(pLabel->alpha == 0)
					*pMergeImg = *pBaseImg ;
				else
				{
					pMergeImg->red = (BYTE)(pBaseImg->red * (255 - pLabel->alpha) + pLabel->red * pLabel->alpha) / 255 ;
					pMergeImg->green = (BYTE)(pBaseImg->green  * (255 - pLabel->alpha) + pLabel->green * pLabel->alpha) / 255 ;
					pMergeImg->blue = (BYTE)(pBaseImg->blue * (255 - pLabel->alpha) + pLabel->blue * pLabel->alpha) / 255 ;
				}
			}
		}
		else
			mLabeledImage.ImportFullSizeImage(mBaseImage.GetPtrToImageData()) ;
		return S_OK;
	}
	else
		return MAKE_OWN_FAIL_RESULT(ERR_CODE_EMPTY) ;
}
