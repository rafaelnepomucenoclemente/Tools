// ClassTitleDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TQuestEditor.h"
#include "ClassTitleDlg.h"
#include ".\classtitledlg.h"


// CClassTitleDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CClassTitleDlg, CDialog)
CClassTitleDlg::CClassTitleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClassTitleDlg::IDD, pParent)
	, m_strClassTitle(_T(""))
{
}

CClassTitleDlg::~CClassTitleDlg()
{
}

void CClassTitleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TITLE_CLASS, m_strClassTitle);
}


BEGIN_MESSAGE_MAP(CClassTitleDlg, CDialog)
END_MESSAGE_MAP()

void CClassTitleDlg::OnCancel()
{
}
