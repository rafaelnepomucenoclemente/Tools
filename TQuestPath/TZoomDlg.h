#pragma once


// CTZoomDlg ��ȭ �����Դϴ�.

class CTZoomDlg : public CDialog
{
	DECLARE_DYNAMIC(CTZoomDlg)

public:
	CString m_strSCALE;

public:
	CTZoomDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTZoomDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_SCALE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
};
