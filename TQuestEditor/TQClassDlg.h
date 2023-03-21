#pragma once
#include "afxcmn.h"


// CTQClassDlg ��ȭ �����Դϴ�.

class CTQClassDlg : public CDialog
{
	DECLARE_DYNAMIC(CTQClassDlg)

public:
	CTQClassDlg( CWnd* pParent = NULL);
	virtual ~CTQClassDlg();

	enum { IDD = IDD_DIALOG_EDIT_CLASS };

public:
	LPMAPTQCLASS m_pTQCLASS;
	CDatabase *m_pDB;

protected:
	virtual void DoDataExchange( CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()
public:
	CTListCtrl m_cLIST;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonAddClass();
	afx_msg void OnBnClickedButtonDelClass();
	afx_msg void OnBnClickedButtonEditClass();
};
