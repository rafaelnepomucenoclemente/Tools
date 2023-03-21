// MainFrm.cpp : CMainFrame Ŭ������ ����
//

#include "stdafx.h"
#include "TFontViewer.h"
#include "MainFrm.h"
#include "TFontTestView.h"
#include "TFontDialogView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ���� �� ǥ�ñ�
		ID_INDICATOR_CAPS,
		ID_INDICATOR_NUM,
		ID_INDICATOR_SCRL,
};


// CMainFrame ����/�Ҹ�
LPDIRECT3DSWAPCHAIN9	CMainFrame::m_pSWAPCHAIN	= NULL;
CD3DDevice				CMainFrame::m_3DDevice;
BYTE					CMainFrame::m_bRender		= TRUE;
FLOAT					CMainFrame::m_fFOV			= 1.0f;

CMainFrame::CMainFrame()
: m_pFontDialog(NULL)
, m_pFontView(NULL)
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	InitDevice();

	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("���� ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("���� ǥ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}
	// TODO: ���� ������ ��ŷ�� �� ���� �Ϸ��� �� �� ���� �����Ͻʽÿ�.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY); 
	DockControlBar(&m_wndToolBar);

	D3DMATERIAL9 mtrl;
	ZeroMemory( &mtrl, sizeof(D3DMATERIAL9));
	mtrl.Diffuse.r = mtrl.Ambient.r = 1.0f;
	mtrl.Diffuse.g = mtrl.Ambient.g = 1.0f;
	mtrl.Diffuse.b = mtrl.Ambient.b = 1.0f;
	mtrl.Diffuse.a = mtrl.Ambient.a = 1.0f;
	m_3DDevice.m_pDevice->SetMaterial(&mtrl);

	m_3DDevice.m_pDevice->SetSoftwareVertexProcessing(FALSE);
	m_3DDevice.m_pDevice->SetVertexShader(NULL);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	// Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	cs.style =  WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		| WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE | WS_SYSMENU;


	return TRUE;
}


// CMainFrame ����

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

//--------------------------------------------------------------------------
// OnCreateClient ������
// �� ������
//--------------------------------------------------------------------------
BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	BOOL bResult = m_SplitWnd[0].CreateStatic( this, 2, 1);

	if(bResult)
	{
		m_SplitWnd[0].CreateView( 0, 0, RUNTIME_CLASS(CTFontDialogView), CSize(10,10), pContext );		// ���̾�α� ��
		m_SplitWnd[0].CreateView( 1, 0, RUNTIME_CLASS(CTFontTestView), CSize(10,10), pContext );		// ������ ��
	}

	//// ��(������) ������ ���
	m_pFontDialog	= (CTFontDialogView*)	m_SplitWnd[0].GetPane( 0, 0 );
	m_pFontView = (CTFontTestView*)	m_SplitWnd[0].GetPane( 1, 0 );

	// ��(������) ũ�� �� ����
	ResizeSplitWnd();

	return TRUE;
}

//--------------------------------------------------------------------------
// ResizeSplitWnd
// ���ҵ� ȭ�� ũ�� �� ����
//--------------------------------------------------------------------------
void CMainFrame::ResizeSplitWnd()
{
	// DialogBar ���� ũ��
	m_SplitWnd[0].SetRowInfo( 0, 165, 100 );

	// ȭ�� ũ�� �� ���
	m_SplitWnd[0].RecalcLayout();

}

void CMainFrame::ReleaseDevice()
{
	if(m_pSWAPCHAIN)
	{
		m_pSWAPCHAIN->Release();
		m_pSWAPCHAIN = NULL;
	}

	m_3DDevice.ReleaseDevice();
}

void CMainFrame::RestoreDevice()
{
	LPDIRECT3DSURFACE9 pBACK = NULL;

	if(m_pSWAPCHAIN)
	{
		m_pSWAPCHAIN->Release();
		m_pSWAPCHAIN = NULL;
	}

	while( m_3DDevice.m_pD3D && m_3DDevice.m_pDevice )
		if(m_3DDevice.Reset())
			break;
	D3DMATERIAL9 mtrl;

	ZeroMemory( &mtrl, sizeof(D3DMATERIAL9));
	mtrl.Diffuse.r = mtrl.Ambient.r = 1.0f;
	mtrl.Diffuse.g = mtrl.Ambient.g = 1.0f;
	mtrl.Diffuse.b = mtrl.Ambient.b = 1.0f;
	mtrl.Diffuse.a = mtrl.Ambient.a = 1.0f;
	m_3DDevice.m_pDevice->SetMaterial(&mtrl);

	m_3DDevice.m_pDevice->SetSoftwareVertexProcessing(FALSE);
	m_3DDevice.m_pDevice->SetVertexShader(NULL);

	m_3DDevice.m_pDevice->CreateAdditionalSwapChain(
		&m_3DDevice.m_vPRESENT,
		&m_pSWAPCHAIN);

	m_pSWAPCHAIN->GetBackBuffer( 0, D3DBACKBUFFER_TYPE_MONO, &pBACK);
	m_3DDevice.m_pDevice->SetRenderTarget( 0, pBACK);
	pBACK->Release();
}

void CMainFrame::InitDevice()
{
	CWnd *pDeskTop = GetDesktopWindow();
	CRect rcScreen;

	LPDIRECT3DSURFACE9 pBACK = NULL;

	pDeskTop->GetWindowRect(&rcScreen);
	ReleaseDevice();

	m_3DDevice.m_option.m_dwBehavior |= D3DCREATE_MULTITHREADED;
	m_3DDevice.m_option.m_dwScreenX = rcScreen.Width();
	m_3DDevice.m_option.m_dwScreenY = rcScreen.Height();
	m_3DDevice.m_option.m_bWindowedMode = TRUE;
	CTachyonRes::m_pDEVICE = &m_3DDevice;

	m_3DDevice.InitDevices(pDeskTop);

	m_3DDevice.m_pDevice->CreateAdditionalSwapChain(
		&m_3DDevice.m_vPRESENT,
		&m_pSWAPCHAIN);

	m_pSWAPCHAIN->GetBackBuffer( 0, D3DBACKBUFFER_TYPE_MONO, &pBACK);
	m_3DDevice.m_pDevice->SetRenderTarget( 0, pBACK);
	pBACK->Release();

	CD3DLight::SetDevice(m_3DDevice.m_pDevice);

}

BOOL CMainFrame::LoadImageFile(const CString& strFILE, CD3DImage* pIMG)
{
	CFile vFILE;
	if( vFILE.Open( strFILE, CFile::modeRead|CFile::typeBinary) )
	{
		DWORD dwSIZE = DWORD(vFILE.GetLength());
		if( dwSIZE )
		{
			LPBYTE pDATA = new BYTE[dwSIZE];
			vFILE.Read( pDATA, dwSIZE);

			pIMG->LoadImageFile(
				m_3DDevice.m_pDevice,
				pDATA,
				dwSIZE);

			delete [] pDATA;
			return TRUE;
		}
	}

	return FALSE;
}

void CMainFrame::SetFont( LOGFONT* of, BOOL bOutline, BOOL bShadow, DWORD dwColor, INT nFontRender, CRect rt )
{
	m_pFontView->SetFont( of, bOutline, bShadow, dwColor, nFontRender, rt );
}

void CMainFrame::SetText( CString str )
{
	m_pFontView->SetText( str ) ;
}

void CMainFrame::LoadImage( CString str )
{
	m_pFontView->LoadImage( str );
}