// TImpErrBoundDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TImpErrBoundDlg.h"


// CTImpErrBoundDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTImpErrBoundDlg, CDialog)
CTImpErrBoundDlg::CTImpErrBoundDlg( CWnd *pParent /*=NULL*/)
: CDialog(CTImpErrBoundDlg::IDD, pParent)
, m_dwBound(0)
{
}

CTImpErrBoundDlg::~CTImpErrBoundDlg()
{
}

void CTImpErrBoundDlg::DoDataExchange( CDataExchange *pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_BOUND, m_dwBound);
}


BEGIN_MESSAGE_MAP(CTImpErrBoundDlg, CDialog)
END_MESSAGE_MAP()


// CTImpErrBoundDlg �޽��� ó�����Դϴ�.

BOOL CTImpErrBoundDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	HICON hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon( hIcon, FALSE);
	SetIcon( hIcon, TRUE);
	UpdateData(FALSE);

	return TRUE;
}

void CTImpErrBoundDlg::OnOK()
{
	UpdateData();
	CDialog::OnOK();
}
