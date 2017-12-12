
// TestToolsDoc.cpp : CTestToolsDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "TestTools.h"
#endif

#include "TestToolsDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTestToolsDoc

IMPLEMENT_DYNCREATE(CTestToolsDoc, CDocument)

BEGIN_MESSAGE_MAP(CTestToolsDoc, CDocument)
	ON_COMMAND(ID_IMAGETOOLS_CREATION, &CTestToolsDoc::OnImagetoolsCreation)
END_MESSAGE_MAP()


// CTestToolsDoc 构造/析构

CTestToolsDoc::CTestToolsDoc()
{
	// TODO: 在此添加一次性构造代码

}

CTestToolsDoc::~CTestToolsDoc()
{
}

BOOL CTestToolsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CTestToolsDoc 序列化

void CTestToolsDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CTestToolsDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CTestToolsDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CTestToolsDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CTestToolsDoc 诊断

#ifdef _DEBUG
void CTestToolsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTestToolsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTestToolsDoc 命令


void CTestToolsDoc::OnImagetoolsCreation()
{
	IImageToDrawWithLabelLayerPtr ImgTools ;
	if(SUCCEEDED(ImgTools.CreateInstance(__uuidof(ImageToDrawWithLabelLayer), NULL, CLSCTX_INPROC_SERVER)))
	{
		AfxMessageBox(_T("interface IImageTools is successfully created")) ;

		ImgTools->CreateImage(500, 500) ;
		long Width, Height ;
		ImgTools->GetImageSize(&Width, &Height) ;
		CString Note ;
		Note.Format(_T("created image size(%d, %d)"), Width, Height) ;
		AfxMessageBox(Note) ;
		ImgTools.Release() ;
	}
	else
		AfxMessageBox(_T("Failed to create interface IImageTools")) ;
}
