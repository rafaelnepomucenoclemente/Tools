// TFontViewerDoc.cpp : CTFontViewerDoc Ŭ������ ����
//

#include "stdafx.h"
#include "TFontViewer.h"

#include "TFontViewerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTFontViewerDoc

IMPLEMENT_DYNCREATE(CTFontViewerDoc, CDocument)

BEGIN_MESSAGE_MAP(CTFontViewerDoc, CDocument)
END_MESSAGE_MAP()


// CTFontViewerDoc ����/�Ҹ�

CTFontViewerDoc::CTFontViewerDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CTFontViewerDoc::~CTFontViewerDoc()
{
}

BOOL CTFontViewerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ �ٽ� �ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CTFontViewerDoc serialization

void CTFontViewerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}


// CTFontViewerDoc ����

#ifdef _DEBUG
void CTFontViewerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTFontViewerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTFontViewerDoc ���
