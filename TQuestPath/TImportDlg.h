#pragma once


// CTImportDlg ��ȭ �����Դϴ�.

class CTImportDlg : public CDialog
{
	DECLARE_DYNAMIC(CTImportDlg)

public:
	CTImportDlg( CWnd *pParent = NULL);
	virtual ~CTImportDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_IMPORT };

public:
	CTQuestPathDoc *m_pDOC;

protected:
	virtual void DoDataExchange( CDataExchange *pDX);
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonQuest();
	afx_msg void OnBnClickedButtonPath();
};
