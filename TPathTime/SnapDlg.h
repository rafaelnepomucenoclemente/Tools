#pragma once


// CSnapDlg ��ȭ �����Դϴ�.

class CSnapDlg : public CDialog
{
	DECLARE_DYNAMIC(CSnapDlg)

public:
	CSnapDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSnapDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_SETSNAP };

public:
	int m_nSNAP;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
