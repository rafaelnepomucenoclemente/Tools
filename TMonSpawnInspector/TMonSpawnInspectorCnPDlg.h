#pragma once
#include "afxwin.h"

class CTMonSpawnInspectorCnPDlg : public CDialog
{
	DECLARE_DYNAMIC(CTMonSpawnInspectorCnPDlg)

public:
	CTMonSpawnInspectorCnPDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTMonSpawnInspectorCnPDlg();

	CString*		m_pDest;

	// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CNP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedOk();
	CEdit m_edtDATA;
};
