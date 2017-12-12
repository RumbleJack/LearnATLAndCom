// ImageToDrawWithLabelLayer.h : CImageToDrawWithLabelLayer 的声明

#pragma once
#include "resource.h"       // 主符号

#include "RGBImage.h"
#include "RGBAImage.h"

#include "ImageTools_i.h"
#define MAX_CNT_LABEL_LAYER	8

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;
// CImageToDrawWithLabelLayer

class ATL_NO_VTABLE CImageToDrawWithLabelLayer :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CImageToDrawWithLabelLayer, &CLSID_ImageToDrawWithLabelLayer>,
	public IImageToDrawWithLabelLayer
{
public:
	CImageToDrawWithLabelLayer()
		: mWidth(0)
		, mHeight(0)
		, mLabelFlag(TRUE)
	{
		mLabelColor.red = mLabelColor.green = mLabelColor.blue = mLabelColor.alpha = 255;
	}

	//声明注册资源ID
	DECLARE_REGISTRY_RESOURCEID(IDR_IMAGETODRAWWITHLABELLAYER)

	//Com组件映射
	BEGIN_COM_MAP(CImageToDrawWithLabelLayer)
		COM_INTERFACE_ENTRY(IImageToDrawWithLabelLayer)
	END_COM_MAP()

	//声明项目最终构造
	DECLARE_PROTECT_FINAL_CONSTRUCT()
	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

protected:
	int			mWidth, mHeight;
	CRGBImage	mBaseImage;

	// 标签图像
	CRGBAImage	mLabel;
	COM_STRUCT_CLR_RGBA mLabelColor;
	BOOL		mLabelFlag;

	CRGBImage	mLabeledImage;
	
public:
	// STDMETHOD，定义了一个返回HRESULT类型的虚方法,调用方式为__stdcall
	STDMETHOD(CheckValid)(void);
	STDMETHOD(CreateImage)(LONG Width, LONG Height);
	STDMETHOD(GetImageSize)(LONG* pWidth, LONG* pHeight);
	STDMETHOD(ImportFullSizeImage)(COM_ENUM_PIXEL_STYLE PixelStyle, BYTE * pPixel);
	STDMETHOD(ImportImage)(COM_ENUM_PIXEL_STYLE PixelStyle, LONG x0, LONG y0, LONG Width, LONG Height, BYTE * pPixel);
	STDMETHOD(ResetImage)();
	STDMETHOD(Destroy)(void);
	STDMETHOD(SetImageLayerPixel)(LONG x, LONG y, BYTE red, BYTE green, BYTE blue);
	STDMETHOD(ExportImageLayer)(LONG x0, LONG y0, LONG Width, LONG Height, COM_STRUCT_CLR_RGB * pDataBuf);
	STDMETHOD(GetImageLayerPixel)(LONG x, LONG y, BYTE* pRed, BYTE* pGreen, BYTE* pBlue);
	STDMETHOD(ResetLabelLayer)();
	STDMETHOD(SetDefaultLabelColor)(BYTE Red, BYTE Green, BYTE Blue, BYTE Alpha);
	STDMETHOD(SetLabelLayerPixel)(LONG x, LONG y);
	STDMETHOD(SetLabelLayerPixelToColor)(LONG x, LONG y, BYTE Red, BYTE Green, BYTE Blue, BYTE Alpha);
	STDMETHOD(ImportLabelLayer)(LONG x0, LONG y0, LONG Width, LONG Height, COM_STRUCT_CLR_RGBA* pLayer);
	STDMETHOD(ExportLabelLayer)(LONG x0, LONG y0, LONG Width, LONG Height, COM_STRUCT_CLR_RGBA* pBuf);
	STDMETHOD(ExportImageToDraw)(LONG x0, LONG y0, LONG Width, LONG Height, COM_STRUCT_CLR_RGB * pBuf);
	STDMETHOD(EnableLabelLayer)(LONG Enable);
	STDMETHOD(CheckLabelLayerEnabled)();
	STDMETHOD(DrawLine)(LONG x0, LONG y0, LONG dx, LONG dy);
	STDMETHOD(DrawRect)(LONG x0, LONG y0, LONG Width, LONG Height, LONG Fill);
	STDMETHOD(DrawCircle)(FLOAT xCenter, FLOAT yCenter, FLOAT Radius, LONG Fill);
	STDMETHOD(GetPtrToImageLayerData)(COM_STRUCT_CLR_RGB ** ppImage);
	STDMETHOD(GetPtrToLabelLayerData)(COM_STRUCT_CLR_RGBA ** ppLable);
	STDMETHOD(GetPtrToImageToDraw)(COM_STRUCT_CLR_RGB ** ppImage);
	STDMETHOD(MergeLabelLayerToImage)(void);

};

// __uuidof获取GUID，GUID是一种由算法生成的二进制长度为128位的数字标识符，是一种UUID(Universally Unique Identifier)
OBJECT_ENTRY_AUTO(__uuidof(ImageToDrawWithLabelLayer), CImageToDrawWithLabelLayer)
