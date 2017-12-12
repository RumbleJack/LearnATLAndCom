

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Tue Dec 12 10:10:43 2017
 */
/* Compiler settings for ImageTools.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ImageTools_i_h__
#define __ImageTools_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IImageToDrawWithLabelLayer_FWD_DEFINED__
#define __IImageToDrawWithLabelLayer_FWD_DEFINED__
typedef interface IImageToDrawWithLabelLayer IImageToDrawWithLabelLayer;
#endif 	/* __IImageToDrawWithLabelLayer_FWD_DEFINED__ */


#ifndef __ImageToDrawWithLabelLayer_FWD_DEFINED__
#define __ImageToDrawWithLabelLayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class ImageToDrawWithLabelLayer ImageToDrawWithLabelLayer;
#else
typedef struct ImageToDrawWithLabelLayer ImageToDrawWithLabelLayer;
#endif /* __cplusplus */

#endif 	/* __ImageToDrawWithLabelLayer_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ImageTools_0000_0000 */
/* [local] */ 

typedef /* [public][public][public][helpstring][uuid] */  DECLSPEC_UUID("ff06c904-e2ac-4928-a634-e245ac375843") 
enum __MIDL___MIDL_itf_ImageTools_0000_0000_0001
    {	COM_GRAY_BYTE	= 0,
	COM_CLR_RGB	= 0x1,
	COM_CLR_BGR	= 0x2
    } 	COM_ENUM_PIXEL_STYLE;

typedef /* [public][public][public][public][public] */ struct __MIDL___MIDL_itf_ImageTools_0000_0000_0002
    {
    BYTE red;
    BYTE green;
    BYTE blue;
    } 	COM_STRUCT_CLR_RGB;

typedef /* [public] */ struct __MIDL___MIDL_itf_ImageTools_0000_0000_0003
    {
    BYTE blue;
    BYTE green;
    BYTE red;
    } 	COM_STRUCT_CLR_BGR;

typedef /* [public][public][public][public] */ struct __MIDL___MIDL_itf_ImageTools_0000_0000_0004
    {
    BYTE red;
    BYTE green;
    BYTE blue;
    BYTE alpha;
    } 	COM_STRUCT_CLR_RGBA;

typedef /* [public] */ struct __MIDL___MIDL_itf_ImageTools_0000_0000_0005
    {
    BYTE blue;
    BYTE green;
    BYTE red;
    BYTE alpha;
    } 	COM_STRUCT_CLR_BGRA;



extern RPC_IF_HANDLE __MIDL_itf_ImageTools_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ImageTools_0000_0000_v0_0_s_ifspec;

#ifndef __IImageToDrawWithLabelLayer_INTERFACE_DEFINED__
#define __IImageToDrawWithLabelLayer_INTERFACE_DEFINED__

/* interface IImageToDrawWithLabelLayer */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IImageToDrawWithLabelLayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7F9F4B4C-D912-40F3-887F-E4C917A0186F")
    IImageToDrawWithLabelLayer : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CheckValid( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateImage( 
            /* [in] */ LONG Width,
            /* [in] */ LONG Height) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Destroy( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetImageSize( 
            /* [in] */ LONG *pWidth,
            /* [in] */ LONG *pHeight) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnableLabelLayer( 
            /* [in] */ LONG Enable) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CheckLabelLayerEnabled( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ResetLabelLayer( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetDefaultLabelColor( 
            /* [in] */ BYTE Red,
            /* [in] */ BYTE Green,
            /* [in] */ BYTE Blue,
            /* [in] */ BYTE Alpha) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetLabelLayerPixel( 
            /* [in] */ LONG x,
            /* [in] */ LONG y) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetLabelLayerPixelToColor( 
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ BYTE Red,
            /* [in] */ BYTE Green,
            /* [in] */ BYTE Blue,
            /* [in] */ BYTE Alpha) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ResetImage( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetImageLayerPixel( 
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ BYTE red,
            /* [in] */ BYTE green,
            /* [in] */ BYTE blue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetImageLayerPixel( 
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ BYTE *pRed,
            /* [in] */ BYTE *pGreen,
            /* [in] */ BYTE *pBlue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ImportFullSizeImage( 
            /* [in] */ COM_ENUM_PIXEL_STYLE PixelStyle,
            /* [in] */ BYTE *pPixel) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ImportImage( 
            /* [in] */ COM_ENUM_PIXEL_STYLE PixelStyle,
            /* [in] */ LONG x0,
            /* [in] */ LONG y0,
            /* [in] */ LONG Width,
            /* [in] */ LONG Height,
            /* [in] */ BYTE *pPixel) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ExportImageLayer( 
            /* [in] */ LONG x0,
            /* [in] */ LONG y0,
            /* [in] */ LONG Width,
            /* [in] */ LONG Height,
            /* [in] */ COM_STRUCT_CLR_RGB *pDataBuf) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ImportLabelLayer( 
            /* [in] */ LONG x0,
            /* [in] */ LONG y0,
            /* [in] */ LONG Width,
            /* [in] */ LONG Height,
            /* [in] */ COM_STRUCT_CLR_RGBA *pLayer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ExportLabelLayer( 
            /* [in] */ LONG x0,
            /* [in] */ LONG y0,
            /* [in] */ LONG Width,
            /* [in] */ LONG Height,
            /* [in] */ COM_STRUCT_CLR_RGBA *pBuf) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ExportImageToDraw( 
            /* [in] */ LONG x0,
            /* [in] */ LONG y0,
            /* [in] */ LONG Width,
            /* [in] */ LONG Height,
            /* [in] */ COM_STRUCT_CLR_RGB *pBuf) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DrawLine( 
            /* [in] */ LONG x0,
            /* [in] */ LONG y0,
            /* [in] */ LONG dx,
            /* [in] */ LONG dy) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DrawRect( 
            /* [in] */ LONG x0,
            /* [in] */ LONG y0,
            /* [in] */ LONG Width,
            /* [in] */ LONG Height,
            /* [in] */ LONG Fill) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DrawCircle( 
            /* [in] */ FLOAT xCenter,
            /* [in] */ FLOAT yCenter,
            /* [in] */ FLOAT Radius,
            /* [in] */ LONG Fill) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPtrToImageLayerData( 
            /* [out] */ COM_STRUCT_CLR_RGB **ppImage) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPtrToLabelLayerData( 
            /* [out] */ COM_STRUCT_CLR_RGBA **ppLable) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPtrToImageToDraw( 
            /* [out] */ COM_STRUCT_CLR_RGB **ppImage) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE MergeLabelLayerToImage( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IImageToDrawWithLabelLayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IImageToDrawWithLabelLayer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IImageToDrawWithLabelLayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IImageToDrawWithLabelLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CheckValid )( 
            IImageToDrawWithLabelLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateImage )( 
            IImageToDrawWithLabelLayer * This,
            /* [in] */ LONG Width,
            /* [in] */ LONG Height);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Destroy )( 
            IImageToDrawWithLabelLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetImageSize )( 
            IImageToDrawWithLabelLayer * This,
            /* [in] */ LONG *pWidth,
            /* [in] */ LONG *pHeight);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnableLabelLayer )( 
            IImageToDrawWithLabelLayer * This,
            /* [in] */ LONG Enable);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CheckLabelLayerEnabled )( 
            IImageToDrawWithLabelLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ResetLabelLayer )( 
            IImageToDrawWithLabelLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetDefaultLabelColor )( 
            IImageToDrawWithLabelLayer * This,
            /* [in] */ BYTE Red,
            /* [in] */ BYTE Green,
            /* [in] */ BYTE Blue,
            /* [in] */ BYTE Alpha);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetLabelLayerPixel )( 
            IImageToDrawWithLabelLayer * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetLabelLayerPixelToColor )( 
            IImageToDrawWithLabelLayer * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ BYTE Red,
            /* [in] */ BYTE Green,
            /* [in] */ BYTE Blue,
            /* [in] */ BYTE Alpha);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ResetImage )( 
            IImageToDrawWithLabelLayer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetImageLayerPixel )( 
            IImageToDrawWithLabelLayer * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ BYTE red,
            /* [in] */ BYTE green,
            /* [in] */ BYTE blue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetImageLayerPixel )( 
            IImageToDrawWithLabelLayer * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ BYTE *pRed,
            /* [in] */ BYTE *pGreen,
            /* [in] */ BYTE *pBlue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ImportFullSizeImage )( 
            IImageToDrawWithLabelLayer * This,
            /* [in] */ COM_ENUM_PIXEL_STYLE PixelStyle,
            /* [in] */ BYTE *pPixel);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ImportImage )( 
            IImageToDrawWithLabelLayer * This,
            /* [in] */ COM_ENUM_PIXEL_STYLE PixelStyle,
            /* [in] */ LONG x0,
            /* [in] */ LONG y0,
            /* [in] */ LONG Width,
            /* [in] */ LONG Height,
            /* [in] */ BYTE *pPixel);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ExportImageLayer )( 
            IImageToDrawWithLabelLayer * This,
            /* [in] */ LONG x0,
            /* [in] */ LONG y0,
            /* [in] */ LONG Width,
            /* [in] */ LONG Height,
            /* [in] */ COM_STRUCT_CLR_RGB *pDataBuf);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ImportLabelLayer )( 
            IImageToDrawWithLabelLayer * This,
            /* [in] */ LONG x0,
            /* [in] */ LONG y0,
            /* [in] */ LONG Width,
            /* [in] */ LONG Height,
            /* [in] */ COM_STRUCT_CLR_RGBA *pLayer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ExportLabelLayer )( 
            IImageToDrawWithLabelLayer * This,
            /* [in] */ LONG x0,
            /* [in] */ LONG y0,
            /* [in] */ LONG Width,
            /* [in] */ LONG Height,
            /* [in] */ COM_STRUCT_CLR_RGBA *pBuf);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ExportImageToDraw )( 
            IImageToDrawWithLabelLayer * This,
            /* [in] */ LONG x0,
            /* [in] */ LONG y0,
            /* [in] */ LONG Width,
            /* [in] */ LONG Height,
            /* [in] */ COM_STRUCT_CLR_RGB *pBuf);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DrawLine )( 
            IImageToDrawWithLabelLayer * This,
            /* [in] */ LONG x0,
            /* [in] */ LONG y0,
            /* [in] */ LONG dx,
            /* [in] */ LONG dy);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DrawRect )( 
            IImageToDrawWithLabelLayer * This,
            /* [in] */ LONG x0,
            /* [in] */ LONG y0,
            /* [in] */ LONG Width,
            /* [in] */ LONG Height,
            /* [in] */ LONG Fill);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DrawCircle )( 
            IImageToDrawWithLabelLayer * This,
            /* [in] */ FLOAT xCenter,
            /* [in] */ FLOAT yCenter,
            /* [in] */ FLOAT Radius,
            /* [in] */ LONG Fill);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPtrToImageLayerData )( 
            IImageToDrawWithLabelLayer * This,
            /* [out] */ COM_STRUCT_CLR_RGB **ppImage);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPtrToLabelLayerData )( 
            IImageToDrawWithLabelLayer * This,
            /* [out] */ COM_STRUCT_CLR_RGBA **ppLable);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPtrToImageToDraw )( 
            IImageToDrawWithLabelLayer * This,
            /* [out] */ COM_STRUCT_CLR_RGB **ppImage);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *MergeLabelLayerToImage )( 
            IImageToDrawWithLabelLayer * This);
        
        END_INTERFACE
    } IImageToDrawWithLabelLayerVtbl;

    interface IImageToDrawWithLabelLayer
    {
        CONST_VTBL struct IImageToDrawWithLabelLayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IImageToDrawWithLabelLayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IImageToDrawWithLabelLayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IImageToDrawWithLabelLayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IImageToDrawWithLabelLayer_CheckValid(This)	\
    ( (This)->lpVtbl -> CheckValid(This) ) 

#define IImageToDrawWithLabelLayer_CreateImage(This,Width,Height)	\
    ( (This)->lpVtbl -> CreateImage(This,Width,Height) ) 

#define IImageToDrawWithLabelLayer_Destroy(This)	\
    ( (This)->lpVtbl -> Destroy(This) ) 

#define IImageToDrawWithLabelLayer_GetImageSize(This,pWidth,pHeight)	\
    ( (This)->lpVtbl -> GetImageSize(This,pWidth,pHeight) ) 

#define IImageToDrawWithLabelLayer_EnableLabelLayer(This,Enable)	\
    ( (This)->lpVtbl -> EnableLabelLayer(This,Enable) ) 

#define IImageToDrawWithLabelLayer_CheckLabelLayerEnabled(This)	\
    ( (This)->lpVtbl -> CheckLabelLayerEnabled(This) ) 

#define IImageToDrawWithLabelLayer_ResetLabelLayer(This)	\
    ( (This)->lpVtbl -> ResetLabelLayer(This) ) 

#define IImageToDrawWithLabelLayer_SetDefaultLabelColor(This,Red,Green,Blue,Alpha)	\
    ( (This)->lpVtbl -> SetDefaultLabelColor(This,Red,Green,Blue,Alpha) ) 

#define IImageToDrawWithLabelLayer_SetLabelLayerPixel(This,x,y)	\
    ( (This)->lpVtbl -> SetLabelLayerPixel(This,x,y) ) 

#define IImageToDrawWithLabelLayer_SetLabelLayerPixelToColor(This,x,y,Red,Green,Blue,Alpha)	\
    ( (This)->lpVtbl -> SetLabelLayerPixelToColor(This,x,y,Red,Green,Blue,Alpha) ) 

#define IImageToDrawWithLabelLayer_ResetImage(This)	\
    ( (This)->lpVtbl -> ResetImage(This) ) 

#define IImageToDrawWithLabelLayer_SetImageLayerPixel(This,x,y,red,green,blue)	\
    ( (This)->lpVtbl -> SetImageLayerPixel(This,x,y,red,green,blue) ) 

#define IImageToDrawWithLabelLayer_GetImageLayerPixel(This,x,y,pRed,pGreen,pBlue)	\
    ( (This)->lpVtbl -> GetImageLayerPixel(This,x,y,pRed,pGreen,pBlue) ) 

#define IImageToDrawWithLabelLayer_ImportFullSizeImage(This,PixelStyle,pPixel)	\
    ( (This)->lpVtbl -> ImportFullSizeImage(This,PixelStyle,pPixel) ) 

#define IImageToDrawWithLabelLayer_ImportImage(This,PixelStyle,x0,y0,Width,Height,pPixel)	\
    ( (This)->lpVtbl -> ImportImage(This,PixelStyle,x0,y0,Width,Height,pPixel) ) 

#define IImageToDrawWithLabelLayer_ExportImageLayer(This,x0,y0,Width,Height,pDataBuf)	\
    ( (This)->lpVtbl -> ExportImageLayer(This,x0,y0,Width,Height,pDataBuf) ) 

#define IImageToDrawWithLabelLayer_ImportLabelLayer(This,x0,y0,Width,Height,pLayer)	\
    ( (This)->lpVtbl -> ImportLabelLayer(This,x0,y0,Width,Height,pLayer) ) 

#define IImageToDrawWithLabelLayer_ExportLabelLayer(This,x0,y0,Width,Height,pBuf)	\
    ( (This)->lpVtbl -> ExportLabelLayer(This,x0,y0,Width,Height,pBuf) ) 

#define IImageToDrawWithLabelLayer_ExportImageToDraw(This,x0,y0,Width,Height,pBuf)	\
    ( (This)->lpVtbl -> ExportImageToDraw(This,x0,y0,Width,Height,pBuf) ) 

#define IImageToDrawWithLabelLayer_DrawLine(This,x0,y0,dx,dy)	\
    ( (This)->lpVtbl -> DrawLine(This,x0,y0,dx,dy) ) 

#define IImageToDrawWithLabelLayer_DrawRect(This,x0,y0,Width,Height,Fill)	\
    ( (This)->lpVtbl -> DrawRect(This,x0,y0,Width,Height,Fill) ) 

#define IImageToDrawWithLabelLayer_DrawCircle(This,xCenter,yCenter,Radius,Fill)	\
    ( (This)->lpVtbl -> DrawCircle(This,xCenter,yCenter,Radius,Fill) ) 

#define IImageToDrawWithLabelLayer_GetPtrToImageLayerData(This,ppImage)	\
    ( (This)->lpVtbl -> GetPtrToImageLayerData(This,ppImage) ) 

#define IImageToDrawWithLabelLayer_GetPtrToLabelLayerData(This,ppLable)	\
    ( (This)->lpVtbl -> GetPtrToLabelLayerData(This,ppLable) ) 

#define IImageToDrawWithLabelLayer_GetPtrToImageToDraw(This,ppImage)	\
    ( (This)->lpVtbl -> GetPtrToImageToDraw(This,ppImage) ) 

#define IImageToDrawWithLabelLayer_MergeLabelLayerToImage(This)	\
    ( (This)->lpVtbl -> MergeLabelLayerToImage(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IImageToDrawWithLabelLayer_INTERFACE_DEFINED__ */



#ifndef __ImageToolsLib_LIBRARY_DEFINED__
#define __ImageToolsLib_LIBRARY_DEFINED__

/* library ImageToolsLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ImageToolsLib;

EXTERN_C const CLSID CLSID_ImageToDrawWithLabelLayer;

#ifdef __cplusplus

class DECLSPEC_UUID("A812CDCA-8752-415C-87AA-12B5A0AC5D27")
ImageToDrawWithLabelLayer;
#endif
#endif /* __ImageToolsLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


