// dllmain.h : 模块类的声明。

class CImageToolsModule : public ATL::CAtlDllModuleT< CImageToolsModule >
{
public :
	DECLARE_LIBID(LIBID_ImageToolsLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_IMAGETOOLS, "{965EAA7A-DADA-40C6-91B1-290F81647713}")
};

extern class CImageToolsModule _AtlModule;
