#pragma once


// CSetJointSizeDlg ��ȭ �����Դϴ�.

class CSetJointSizeDlg : public CDialog
{
	DECLARE_DYNAMIC(CSetJointSizeDlg)

public:
	CSetJointSizeDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSetJointSizeDlg();

public:
	CSize m_vTJOINT;

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_SETJOINT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
protected:
	virtual void OnOK();
};
