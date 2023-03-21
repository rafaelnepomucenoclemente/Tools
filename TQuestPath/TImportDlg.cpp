// TImportDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TImportDlg.h"


// CTImportDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTImportDlg, CDialog)
CTImportDlg::CTImportDlg( CWnd *pParent /*=NULL*/)
: CDialog(CTImportDlg::IDD, pParent)
{
	m_pDOC = NULL;
}

CTImportDlg::~CTImportDlg()
{
}

void CTImportDlg::DoDataExchange( CDataExchange *pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTImportDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_QUEST, OnBnClickedButtonQuest)
	ON_BN_CLICKED(IDC_BUTTON_PATH, OnBnClickedButtonPath)
END_MESSAGE_MAP()


// CTImportDlg �޽��� ó�����Դϴ�.

BOOL CTImportDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	HICON hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon( hIcon, FALSE);
	SetIcon( hIcon, TRUE);

	return TRUE;
}

void CTImportDlg::OnBnClickedButtonQuest()
{
	if(m_pDOC)
		m_pDOC->ImportTQUEST();
}

void CTImportDlg::OnBnClickedButtonPath()
{
	if(m_pDOC)
		m_pDOC->ImportTPATH();
}
