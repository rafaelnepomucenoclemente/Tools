// TEditTQClassDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TQuestEditor.h"
#include "TEditTQClassDlg.h"


// CTEditTQClassDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTEditTQClassDlg, CDialog)
CTEditTQClassDlg::CTEditTQClassDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTEditTQClassDlg::IDD, pParent)
	, m_strNAME(_T(""))
	, m_bClassMain(0)
{
	m_strTITLE.Empty();
}

CTEditTQClassDlg::~CTEditTQClassDlg()
{
}

void CTEditTQClassDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strNAME);
}


BEGIN_MESSAGE_MAP(CTEditTQClassDlg, CDialog)
END_MESSAGE_MAP()


// CTEditTQClassDlg �޽��� ó�����Դϴ�.

BOOL CTEditTQClassDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	HICON hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon( hIcon, FALSE);
	SetIcon( hIcon, TRUE);
	SetWindowText(m_strTITLE);

	return TRUE;
}
