// ImageWithLabelLayer.h : CImageWithLabelLayer ������

#pragma once
#include "resource.h"       // ������



#include "ImageTools_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;


// CImageWithLabelLayer

class ATL_NO_VTABLE CImageWithLabelLayer :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CImageWithLabelLayer, &CLSID_ImageWithLabelLayer>,
	public IImageWithLabelLayer
{
public:
	CImageWithLabelLayer()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_IMAGEWITHLABELLAYER)


BEGIN_COM_MAP(CImageWithLabelLayer)
	COM_INTERFACE_ENTRY(IImageWithLabelLayer)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



	STDMETHOD(Create)(LONG Width, LONG Height);
};

OBJECT_ENTRY_AUTO(__uuidof(ImageWithLabelLayer), CImageWithLabelLayer)
