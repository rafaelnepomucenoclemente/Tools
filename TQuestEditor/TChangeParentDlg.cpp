// TChangeParentDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TQuestEditor.h"
#include "TChangeParentDlg.h"


// CTChangeParentDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTChangeParentDlg, CDialog)
CTChangeParentDlg::CTChangeParentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTChangeParentDlg::IDD, pParent)
	, m_dwParentID(0)
{
}

CTChangeParentDlg::~CTChangeParentDlg()
{
}

void CTChangeParentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PARENTID, m_dwParentID);
}


BEGIN_MESSAGE_MAP(CTChangeParentDlg, CDialog)
END_MESSAGE_MAP()


// CTChangeParentDlg �޽��� ó�����Դϴ�.

BOOL CTChangeParentDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	HICON hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon( hIcon, FALSE);
	SetIcon( hIcon, TRUE);

	return TRUE;
}
