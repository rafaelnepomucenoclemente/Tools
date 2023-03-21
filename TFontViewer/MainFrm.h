// MainFrm.h : CMainFrame Ŭ������ �������̽�
//
#pragma once



class CMainFrame : public CFrameWnd
{
	
protected: // serialization������ ��������ϴ�.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

	// Ư��
public:
	CSplitterWnd		m_SplitWnd[1];
	CTFontDialogView*	m_pFontDialog;
	CTFontTestView*		m_pFontView;

public:
	static LPDIRECT3DSWAPCHAIN9 m_pSWAPCHAIN;
	static CD3DDevice m_3DDevice;
	static BYTE m_bRender;
	static FLOAT m_fFOV;	// Perspective â�� FOV ��

// �۾�
public:
	void				ResizeSplitWnd();		// �������� SplitWnd

public:
	static void RestoreDevice();
	static void ReleaseDevice();
	static void InitDevice();

	static BOOL LoadImageFile(const CString& strFILE, CD3DImage* pIMG);


	void	SetFont( LOGFONT* of, BOOL bOutline, BOOL bShadow, DWORD dwColor, INT nFontRender, CRect rt );
	void	SetText( CString str );

	void	LoadImage( CString str );
	//static void	SetFont();
	//static void	SetFont();

	



// ������
public:
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
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
};


