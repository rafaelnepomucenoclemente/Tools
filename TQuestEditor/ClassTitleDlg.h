#pragma once


// CClassTitleDlg ��ȭ �����Դϴ�.

class CClassTitleDlg : public CDialog
{
	DECLARE_DYNAMIC(CClassTitleDlg)

public:
	CClassTitleDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CClassTitleDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_CLASS_TITLE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strClassTitle;
protected:
	virtual void OnCancel();
};
