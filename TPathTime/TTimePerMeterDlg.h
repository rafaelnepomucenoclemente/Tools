#pragma once


// CTTimePerMeterDlg ��ȭ �����Դϴ�.

class CTTimePerMeterDlg : public CDialog
{
	DECLARE_DYNAMIC(CTTimePerMeterDlg)

public:
	CTTimePerMeterDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTTimePerMeterDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_SETTIME };

public:
	float m_fTIME;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
