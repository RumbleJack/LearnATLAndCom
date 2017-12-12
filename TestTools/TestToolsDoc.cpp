
// TestToolsDoc.cpp : CTestToolsDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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


// CTestToolsDoc ����/����

CTestToolsDoc::CTestToolsDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CTestToolsDoc::~CTestToolsDoc()
{
}

BOOL CTestToolsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CTestToolsDoc ���л�

void CTestToolsDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CTestToolsDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
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

// ������������֧��
void CTestToolsDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
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

// CTestToolsDoc ���

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


// CTestToolsDoc ����


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
