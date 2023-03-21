// TZoomDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TZoomDlg.h"


// CTZoomDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTZoomDlg, CDialog)

CTZoomDlg::CTZoomDlg(CWnd* pParent /*=NULL*/)
:CDialog(CTZoomDlg::IDD, pParent)
, m_strSCALE(_T(""))
{
}

CTZoomDlg::~CTZoomDlg()
{
}

void CTZoomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SCALE, m_strSCALE);
}


BEGIN_MESSAGE_MAP(CTZoomDlg, CDialog)
END_MESSAGE_MAP()


// CTZoomDlg �޽��� ó�����Դϴ�.

BOOL CTZoomDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	HICON hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon( hIcon, FALSE);
	SetIcon( hIcon, TRUE);

	return TRUE;
}

void CTZoomDlg::OnOK()
{
	CDialog::OnOK();
	FLOAT fSCALE;

	sscanf( LPCTSTR(m_strSCALE), _T("%f"), &fSCALE);
	m_strSCALE.Format( IDS_FMT_POS_DATA, fSCALE);
}
