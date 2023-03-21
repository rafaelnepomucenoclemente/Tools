// FindQuestTitleDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TQuestEditor.h"
#include "FindQuestTitleDlg.h"
#include ".\findquesttitledlg.h"


// CFindQuestTitleDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFindQuestTitleDlg, CDialog)
CFindQuestTitleDlg::CFindQuestTitleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFindQuestTitleDlg::IDD, pParent)
	, m_strSearchText(_T(""))
	, m_nSearchType(0)
{
}

CFindQuestTitleDlg::~CFindQuestTitleDlg()
{
}

void CFindQuestTitleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SEARCH_TEXT, m_strSearchText);
	//DDX_Radio(pDX, IDC_RADIO_SEARCHTYPE_SENTENCE, m_bSearchType);
	//DDX_Radio(pDX, IDC_RADIO_SEARCHTYPE_SENTENCE, m_bSearchType);
	DDX_Radio(pDX, IDC_RADIO_SEARCHTYPE_SENTENCE, m_nSearchType);
}


BEGIN_MESSAGE_MAP(CFindQuestTitleDlg, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CFindQuestTitleDlg �޽��� ó�����Դϴ�.

void CFindQuestTitleDlg::OnBnClickedOk()
{
	UpdateData();
	if( m_strSearchText.IsEmpty() )
	{
		AfxMessageBox("Input String!", MB_OK | MB_ICONWARNING);
		return;
	}
    OnOK();
}

void CFindQuestTitleDlg::GetSearchString(CString* pStr)
{
	(*pStr) = m_strSearchText;
}

void CFindQuestTitleDlg::GetSearchType(INT* nType)
{
	(*nType) = m_nSearchType;
}
