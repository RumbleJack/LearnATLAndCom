// TestToolsView.cpp : CTestToolsView ���ʵ��

#include "stdafx.h"

// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "TestTools.h"
#endif

#include "TestToolsDoc.h"
#include "TestToolsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTestToolsView
IMPLEMENT_DYNCREATE(CTestToolsView, CView)

BEGIN_MESSAGE_MAP(CTestToolsView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestToolsView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTestToolsView ����/����

CTestToolsView::CTestToolsView()
{
	// TODO: �ڴ˴���ӹ������

}

CTestToolsView::~CTestToolsView()
{
}

BOOL CTestToolsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CTestToolsView ����
void CTestToolsView::OnDraw(CDC* /*pDC*/)
{
	CTestToolsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CTestToolsView ��ӡ
void CTestToolsView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestToolsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CTestToolsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CTestToolsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CTestToolsView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestToolsView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestToolsView ���
#ifdef _DEBUG
void CTestToolsView::AssertValid() const
{
	CView::AssertValid();
}

void CTestToolsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestToolsDoc* CTestToolsView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestToolsDoc)));
	return (CTestToolsDoc*)m_pDocument;
}
#endif //_DEBUG

// CTestToolsView ��Ϣ�������
