#pragma once
#include "TMonSpawnInspectorHUGEMAP.h"

class CTMonSpawnInspectorDlg : public CDialog
{
	// ����
public:
	CTMonSpawnInspectorDlg(CWnd* pParent = NULL);	// ǥ�� ������
	virtual ~CTMonSpawnInspectorDlg();

	// ��ȭ ���� ������
	enum { IDD = IDD_TMSI };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����


	// ����
public:
	HICON					m_hIcon;
	CButton					m_btnClientPath;
	CButton					m_btnDestPath;
	CString					m_strCLIENTPATH;
	CString					m_strDESTPATH;
	CComboBox			m_cmbInputMethod;
	CStatic					m_stcWorkingText;
	CProgressCtrl			m_ctrlWorkingProgress;

protected:
	// �޽��� �� �Լ��� �����߽��ϴ�.
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButtonClient();
	afx_msg void OnBnClickedButtonDest();
	afx_msg void OnBnClickedButtonInspection();
	afx_msg void OnBnClickedWorkingStop();

public:
	BOOL					m_bStopWorking;			// �۾� �߰��� �ߴܽ�Ű�� ���� �÷���.

	VTSPAWNDATA		m_vTSPAWNDATA;			// ����Ÿ �ҽ�.
	VTRESULT				m_vTRESULT;					// �˻� ���.
	VTSORTEDMAP		m_vTSORTEDMAP;			// ����Ÿ �ҽ��� ������ ����Ÿ.

public:
	BOOL AddSpawnData(
		LPCTSTR szLine);

	VOID SetControlWorkingMode(
		BOOL bWorkingMode);

	BOOL OnInputFromFile();

	BOOL OnInputFromEditBox();

	INT ProcSortDataByMapID();

	INT ProcInspectData();

	INT ProcWriteReport();
	
	INT ProcWriteReviseHeightReport();

	VOID InsertSpawnByMapID(
		WORD wMapID,
		TSPAWNDATA& data);

	LTSPAWNDATA& FindSpawnArrayByUnitIndex(
		VTSORTEDUNIT& vUnits,
		INT nUnitIndex,
		INT nUnitX,
		INT nUnitZ );
	BOOL m_bReviseHeight;
};