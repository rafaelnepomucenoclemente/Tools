// SnapDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TPathTime.h"
#include "SnapDlg.h"


// CSnapDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CSnapDlg, CDialog)
CSnapDlg::CSnapDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSnapDlg::IDD, pParent)
	, m_nSNAP(0)
{
}

CSnapDlg::~CSnapDlg()
{
}

void CSnapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SNAP, m_nSNAP);
}


BEGIN_MESSAGE_MAP(CSnapDlg, CDialog)
END_MESSAGE_MAP()


// CSnapDlg �޽��� ó�����Դϴ�.

BOOL CSnapDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	HICON hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon( hIcon, FALSE);
	SetIcon( hIcon, TRUE);

	m_nSNAP = theApp.m_nSNAP;
	UpdateData(FALSE);

	return TRUE;
}
