#pragma once


// CTChangeParentDlg ��ȭ �����Դϴ�.

class CTChangeParentDlg : public CDialog
{
	DECLARE_DYNAMIC(CTChangeParentDlg)

public:
	CTChangeParentDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTChangeParentDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_CHGPARENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	DWORD m_dwParentID;
};
