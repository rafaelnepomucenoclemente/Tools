#pragma once


// CTImpErrBoundDlg ��ȭ �����Դϴ�.

class CTImpErrBoundDlg : public CDialog
{
	DECLARE_DYNAMIC(CTImpErrBoundDlg)

public:
	CTImpErrBoundDlg( CWnd *pParent = NULL);
	virtual ~CTImpErrBoundDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_ERRBOUND };

protected:
	virtual void DoDataExchange( CDataExchange *pDX);
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
public:
	DWORD m_dwBound;
};
