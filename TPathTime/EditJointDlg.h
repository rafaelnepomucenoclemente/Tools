#pragma once


// CEditJointDlg ��ȭ �����Դϴ�.

class CEditJointDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditJointDlg)

public:
	CEditJointDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CEditJointDlg();

public:
	LPTJOINT m_pTJOINT;
	DWORD m_dwID;

	BOOL m_vJOINT[8];
	CRect m_vRECT;

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_EDITJOINT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
protected:
	virtual void OnOK();
};
