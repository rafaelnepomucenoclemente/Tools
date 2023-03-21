#pragma once
#include "afxcmn.h"


// CFindQuestListDlg ��ȭ �����Դϴ�.

typedef vector<HTREEITEM> VECHITEM;
typedef map< int, HTREEITEM> MAPITEM;

class CFindQuestListDlg : public CDialog
{
	DECLARE_DYNAMIC(CFindQuestListDlg)

public:
	CFindQuestListDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFindQuestListDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_LIST_FIND_QUEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

public:
	CListCtrl m_cFindQuestList;
	void InitListData(CTreeCtrl *pTree, VECHITEM* vHItem);
private:
	MAPITEM		m_mapITEMLIST;
	CTreeCtrl*	m_pTree;
	VECHITEM*	m_pHItem;
	HTREEITEM	m_pSelectedItem;
public:
	afx_msg void OnSelectedItem();
	afx_msg void OnSelectedItem(NMHDR *pNMHDR, LRESULT *pResult);
	void GetSelectedItem(HTREEITEM* pSelectedItem);
};
