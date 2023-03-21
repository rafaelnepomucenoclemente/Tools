// SetJointSizeDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TPathTime.h"
#include "SetJointSizeDlg.h"


// CSetJointSizeDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CSetJointSizeDlg, CDialog)
CSetJointSizeDlg::CSetJointSizeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetJointSizeDlg::IDD, pParent)
{
	m_vTJOINT.SetSize( 0, 0);
}

CSetJointSizeDlg::~CSetJointSizeDlg()
{
}

void CSetJointSizeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_JOINT_X, m_vTJOINT.cx);
	DDX_Text(pDX, IDC_EDIT_JOINT_Y, m_vTJOINT.cy);
}


BEGIN_MESSAGE_MAP(CSetJointSizeDlg, CDialog)
END_MESSAGE_MAP()


// CSetJointSizeDlg �޽��� ó�����Դϴ�.

BOOL CSetJointSizeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	HICON hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon( hIcon, FALSE);
	SetIcon( hIcon, TRUE);

	m_vTJOINT = theApp.m_vTJOINT;
	UpdateData(FALSE);

	return TRUE;
}

void CSetJointSizeDlg::OnOK()
{
	UpdateData();
	theApp.m_vTJOINT = m_vTJOINT;
	CDialog::OnOK();
}
