// MainFrm.h : CMainFrame Ŭ������ �������̽�
//


#pragma once
class CMainFrame : public CFrameWnd
{
	
protected: // serialization������ ��������ϴ�.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Ư��
protected:
	CSplitterWnd m_wndSplitter[2];
	BYTE m_bReady;
	BYTE m_bInit;

public:
	CStatusBar* GetStatusBar();

// �۾�
public:

// ������
public:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ����
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // ��Ʈ�� ������ ���Ե� ����Դϴ�.
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize( UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()
};
