// TPathWndBase.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TPathWndBase.h"


// CTPathWndBase ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTPathWndBase, CDialog)

CTPathWndBase::CTPathWndBase( UINT nIDTemplate, CWnd *pParent /*=NULL*/)
: CDialog( nIDTemplate, pParent)
{
}

CTPathWndBase::~CTPathWndBase()
{
}

CTQuestPathDoc* CTPathWndBase::GetDocument() const
{
	CView *pView = (CView *) GetParent();
	return pView ? (CTQuestPathDoc *) pView->GetDocument() : NULL;
}

void CTPathWndBase::ShowWnd( BYTE bShow)
{
	if(bShow)
		UpdateTMAP();

	ShowWindow(bShow ? SW_SHOW : SW_HIDE);
}


BEGIN_MESSAGE_MAP(CTPathWndBase, CDialog)
END_MESSAGE_MAP()


// CTPathWndBase �޽��� ó�����Դϴ�.
