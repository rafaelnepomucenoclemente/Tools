#pragma once


// CFindQuestTitleDlg ��ȭ �����Դϴ�.

class CFindQuestTitleDlg : public CDialog
{
	DECLARE_DYNAMIC(CFindQuestTitleDlg)

public:
	CFindQuestTitleDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFindQuestTitleDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_FIND_QUEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strSearchText;
	afx_msg void OnBnClickedOk();
	void GetSearchString(CString* pStr);
	//BOOL m_bSearchType;
	void GetSearchType(INT* nType);
	//BYTE m_bSearchType;
	int m_nSearchType;
};
