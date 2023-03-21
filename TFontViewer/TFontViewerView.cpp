// TFontViewerView.cpp : CTFontViewerView Ŭ������ ����
//

#include "stdafx.h"
#include "TFontViewer.h"

#include "TFontViewerDoc.h"
#include "TFontViewerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTFontViewerView

IMPLEMENT_DYNCREATE(CTFontViewerView, CView)

BEGIN_MESSAGE_MAP(CTFontViewerView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTFontViewerView ����/�Ҹ�

CTFontViewerView::CTFontViewerView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CTFontViewerView::~CTFontViewerView()
{
}

BOOL CTFontViewerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	// Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CTFontViewerView �׸���

void CTFontViewerView::OnDraw(CDC* /*pDC*/)
{
	CTFontViewerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CTFontViewerView �μ�

BOOL CTFontViewerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CTFontViewerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CTFontViewerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CTFontViewerView ����

#ifdef _DEBUG
void CTFontViewerView::AssertValid() const
{
	CView::AssertValid();
}

void CTFontViewerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTFontViewerDoc* CTFontViewerView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTFontViewerDoc)));
	return (CTFontViewerDoc*)m_pDocument;
}
#endif //_DEBUG


// CTFontViewerView �޽��� ó����
