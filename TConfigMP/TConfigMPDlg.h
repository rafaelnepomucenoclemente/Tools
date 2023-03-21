// TConfigMPDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


#define TMAX_CHECK_CODE_SIZE			((BYTE) 7)
#define TMIN_CHECK_CODE_SIZE			((BYTE) 3)
#define TESSPROC_COUNT					(2)


// CTConfigMPDlg ��ȭ ����
class CTConfigMPDlg : public CDialog
{
// ����
public:
	CTConfigMPDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	enum { IDD = IDD_TCONFIGMP_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����

public:
	CString m_strMAINPEFOLDER;
	CString m_strDESTFOLDER;
	CString m_strSRCFOLDER;

	CString m_strMainPE;
	CString m_strDEST;
	CString m_strSRC;

	CButton m_cMainPE;
	CButton m_cDEST;
	CButton m_cSRC;

protected:
	PIMAGE_NT_HEADERS GetNTHeader( LPBYTE pDATA);

protected:
	CString ReadString( CStdioFile *pFILE);
	void WriteString(
		CString *pTEXT,
		CFile *pFile,
		LPBYTE pMASK,
		LPBYTE pMIDX,
		BYTE bMASK);

	void WriteDATA(
		LPVOID pDATA,
		CFile *pFile,
		LPBYTE pMASK,
		LPBYTE pMIDX,
		BYTE bMASK,
		int nSIZE);

	BYTE BuildPEINFO(
		CFile *pFile,
		LPBYTE pMASK,
		LPBYTE pMIDX,
		BYTE bMASK);

	void BuildMODULEINFO(
		CFile *pFile,
		LPBYTE pMASK,
		LPBYTE pMIDX,
		BYTE bMASK);

protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonMainPe();
	afx_msg void OnBnClickedButtonDest();
	afx_msg void OnBnClickedButtonSrc();
	afx_msg void OnBnClickedCompile();
};
