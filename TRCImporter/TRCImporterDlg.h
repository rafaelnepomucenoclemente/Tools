// TRCImporterDlg.h : ��� ����
//

#pragma once

#define GERMANY 0
#define ENGLISH 1
#define JAPAN 2

// CTRCImporterDlg ��ȭ ����
class CTRCImporterDlg : public CDialog
{
// ����
public:
	CTRCImporterDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	enum { IDD = IDD_TRCIMPORTER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CString m_strRCPath;
	CString m_strCSV;
	int m_nNation;
	afx_msg void OnBnClickedOk();
	int Import(CString strCSVPath, CString strRCPath, CString strTargetPath, int nNation);
	afx_msg void OnBnClickedButton4();
	CString m_strTargetPath;
};
