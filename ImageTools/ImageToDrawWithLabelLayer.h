// ImageToDrawWithLabelLayer.h : CImageToDrawWithLabelLayer ������

#pragma once
#include "resource.h"       // ������

#include "RGBImage.h"
#include "RGBAImage.h"

#include "ImageTools_i.h"
#define MAX_CNT_LABEL_LAYER	8

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
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

	//����ע����ԴID
	DECLARE_REGISTRY_RESOURCEID(IDR_IMAGETODRAWWITHLABELLAYER)

	//Com���ӳ��
	BEGIN_COM_MAP(CImageToDrawWithLabelLayer)
		COM_INTERFACE_ENTRY(IImageToDrawWithLabelLayer)
	END_COM_MAP()

	//������Ŀ���չ���
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

	// ��ǩͼ��
	CRGBAImage	mLabel;
	COM_STRUCT_CLR_RGBA mLabelColor;
	BOOL		mLabelFlag;

	CRGBImage	mLabeledImage;
	
public:
	// STDMETHOD��������һ������HRESULT���͵��鷽��,���÷�ʽΪ__stdcall
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

// __uuidof��ȡGUID��GUID��һ�����㷨���ɵĶ����Ƴ���Ϊ128λ�����ֱ�ʶ������һ��UUID(Universally Unique Identifier)
OBJECT_ENTRY_AUTO(__uuidof(ImageToDrawWithLabelLayer), CImageToDrawWithLabelLayer)
