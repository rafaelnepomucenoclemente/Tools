#pragma once


// CTEditTQClassDlg ��ȭ �����Դϴ�.

class CTEditTQClassDlg : public CDialog
{
	DECLARE_DYNAMIC(CTEditTQClassDlg)

public:
	CTEditTQClassDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTEditTQClassDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_ADD_CLASS };

public:
	CString m_strTITLE;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strNAME;
	BYTE	m_bClassMain;
	virtual BOOL OnInitDialog();
};
