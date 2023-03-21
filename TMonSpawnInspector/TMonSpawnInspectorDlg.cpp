// TMonSpawnInspectorDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "TMonSpawnInspector.h"
#include "TMonSpawnInspectorDlg.h"
#include "TMonSpawnInspectorCnPDlg.h"
#include "TMonSpawnInspectorMAP.h"
#include "TMonSpawnInspectorObjBase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTMonSpawnInspectorDlg ��ȭ ����

CTMonSpawnInspectorDlg::CTMonSpawnInspectorDlg(CWnd* pParent /*=NULL*/)
: CDialog(CTMonSpawnInspectorDlg::IDD, pParent)
, m_strCLIENTPATH(_T(""))
, m_strDESTPATH(_T(""))
, m_bStopWorking(FALSE)
, m_bReviseHeight(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CTMonSpawnInspectorDlg::~CTMonSpawnInspectorDlg()
{
}

void CTMonSpawnInspectorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_CLIENT, m_btnClientPath);
	DDX_Control(pDX, IDC_BUTTON_DEST, m_btnDestPath);
	DDX_Text(pDX, IDC_EDIT_CLIENT, m_strCLIENTPATH);
	DDX_Text(pDX, IDC_EDIT_DEST, m_strDESTPATH);
	DDX_Control(pDX, IDC_COMBO_INPUT_TYPE, m_cmbInputMethod);
	DDX_Control(pDX, IDC_WORKING_TEXT, m_stcWorkingText);
	DDX_Control(pDX, IDC_WORKING_PROGRESS, m_ctrlWorkingProgress);
	DDX_Check(pDX, IDC_CHECK_REVISE_HEIGHT, m_bReviseHeight);
}

BEGIN_MESSAGE_MAP(CTMonSpawnInspectorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_CLIENT, OnBnClickedButtonClient)
	ON_BN_CLICKED(IDC_BUTTON_DEST, OnBnClickedButtonDest)
	ON_BN_CLICKED(IDC_BUTTON_INSPECTION, OnBnClickedButtonInspection)
END_MESSAGE_MAP()


// CTMonSpawnInspectorDlg �޽��� ó����

BOOL CTMonSpawnInspectorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	HICON hIcon = AfxGetApp()->LoadIcon(IDI_ICON_FOLDER);
	m_btnClientPath.SetIcon(hIcon);
	m_btnDestPath.SetIcon(hIcon);

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CTMonSpawnInspectorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸����� 
// �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
// �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CTMonSpawnInspectorDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�. 
HCURSOR CTMonSpawnInspectorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTMonSpawnInspectorDlg::OnBnClickedButtonClient()
{
	CTShell dlg;

	TCHAR szCurPath[MAX_PATH];
	::GetCurrentDirectory( MAX_PATH, szCurPath );

	dlg.m_strSelDir = szCurPath;
	dlg.m_strTitle = _T("Client Folder");

	if( dlg.BrowseForFolder(this) == IDOK )
	{
		UpdateData();
		m_strCLIENTPATH = dlg.m_strPath;
		UpdateData(FALSE);
	}
}

void CTMonSpawnInspectorDlg::OnBnClickedButtonDest()
{
	CFileDialog dlg(
		FALSE,
		_T("*.csv"),
		"result.csv",
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		_T("Report File(CSV) (*.csv)|*.csv||"));

	TCHAR szCurPath[MAX_PATH];
	::GetCurrentDirectory( MAX_PATH, szCurPath );

	dlg.m_ofn.lpstrInitialDir = szCurPath;
	if( dlg.DoModal() == IDOK )
	{
		UpdateData();
		m_strDESTPATH = dlg.GetPathName();
		UpdateData(FALSE);
	}
}

void CTMonSpawnInspectorDlg::OnBnClickedButtonInspection()
{
	UpdateData();

	// �ʱ�ȭ
	m_vTSPAWNDATA.clear();
	m_vTRESULT.clear();
	m_vTSORTEDMAP.clear();

	SetProgressText("");
	SetProgressClear();

	// 1. Ŭ���̾�Ʈ ��� ����
	if( m_strCLIENTPATH == "" )
	{
		AfxMessageBox( "Ŭ���̾�Ʈ ��ΰ� ��ȿ���� �ʽ��ϴ�.", MB_OK );
		return ;
	}

	// 2. ������� ��� ����
	if( m_strDESTPATH == "" )
	{
		AfxMessageBox( "��� ������ ��ȿ���� �ʽ��ϴ�.", MB_OK );
		return ;
	}

	// 3. �Է¹�� ����
	INT nInputMethod = m_cmbInputMethod.GetCurSel();
	// -1 : None
	// 0 : ����
	// 1 : Copy & Paste

	switch( nInputMethod )
	{
	case -1:
		{
			AfxMessageBox( "�Է¹���� �����Ͻʽÿ�.", MB_OK );
			return ;
		}

		// 3.1 �Է¹�� : ����
	case 0:
		{
			TCHAR szCurPath[MAX_PATH];
			GetCurrentDirectory( MAX_PATH, szCurPath );
			BOOL bRet = OnInputFromFile();
			SetCurrentDirectory( szCurPath );

			if( FALSE == bRet )
				return ;
			else
				break;
		}

		// 3.2 �Է¹�� : Copy & Paste
	case 1:
		{
			if( FALSE == OnInputFromEditBox() )
				return ;
			else
				break;
		}
	}

	// 4. ��Ʈ�� ǥ�ø� �۾����� ����
	SetControlWorkingMode(TRUE);

	if( TRUE == ProcInspectData() ) // 5. ������ �˻�
		ProcWriteReport(); // 6. �Ϸ� - ����Ʈ �ۼ�

	// 7. ��Ʈ�� ǥ�ø� �ʱ���·� ����
	SetControlWorkingMode(FALSE);
}

BOOL CTMonSpawnInspectorDlg::AddSpawnData(
	LPCTSTR szLine)
{
	if( szLine[0] == '\0' ||
		szLine[0] == '\t' ||
		szLine[0] == '\r' || 
		szLine[0] == '\n' )
	{
		TSPAWNDATA SPAWNDATA;
		SPAWNDATA.bEmptyLine = TRUE;

		m_vTSPAWNDATA.push_back( SPAWNDATA );
		return TRUE;
	}

	DWORD wID = 0;
	DWORD wGroup = 0;
	DWORD wLocalID = 0;
	DWORD wMapID = 0;
	FLOAT fPosX = 0.0f;
	FLOAT fPosY = 0.0f;
	FLOAT fPosZ = 0.0f;
	DWORD wDir = 0;
	DWORD bCount = 0;
	DWORD bRange = 0;
	DWORD bArea = 0;
	DWORD bProb = 0;
	DWORD bLink = 0;
	DWORD dwDelay = 0;
	DWORD bRoamType = 0;
	DWORD bCountry = 0;
	DWORD dwRegion = 0;
	DWORD bEvent = 0;
	DWORD wPartyID = 0;

	sscanf( szLine, "%d %d %d %d %f %f %f %d %d %d %d %d %d %d %d %d %d %d %d",
		&wID,
		&wGroup,
		&wLocalID,
		&wMapID,
		&fPosX,
		&fPosY,
		&fPosZ,
		&wDir,
		&bCount,
		&bRange,
		&bArea,
		&bProb,
		&bLink,
		&dwDelay,
		&bRoamType,
		&bCountry,
		&dwRegion,
		&bEvent,
		&wPartyID );

	TSPAWNDATA SPAWNDATA;

	SPAWNDATA.wSpawnID = (WORD)wID;
	SPAWNDATA.wMapID = (WORD)wMapID;
	SPAWNDATA.fPosX = fPosX;
	SPAWNDATA.fPosY = fPosY;
	SPAWNDATA.fPosZ = fPosZ;
	SPAWNDATA.bRange = (BYTE)bRange;
	SPAWNDATA.bEmptyLine = FALSE;

	m_vTSPAWNDATA.push_back( SPAWNDATA );

	return TRUE;
}

VOID CTMonSpawnInspectorDlg::SetControlWorkingMode(
	BOOL bWorkingMode)
{
	CWnd* pWnd = NULL;

	if( bWorkingMode ) // �۾� ��� �� ���
	{
		// �ʱ�ȭ�� ��Ʈ�ѵ��� Hide
		pWnd = GetDlgItem( IDC_STATIC1 );
		if( pWnd ) pWnd->ShowWindow( SW_HIDE );

		pWnd = GetDlgItem( IDC_STATIC2 );
		if( pWnd ) pWnd->ShowWindow( SW_HIDE );

		pWnd = GetDlgItem( IDC_STATIC3 );
		if( pWnd ) pWnd->ShowWindow( SW_HIDE );

		pWnd = GetDlgItem( IDC_COMBO_INPUT_TYPE );
		if( pWnd ) pWnd->ShowWindow( SW_HIDE ); 

		pWnd = GetDlgItem( IDC_EDIT_CLIENT );
		if( pWnd ) pWnd->ShowWindow( SW_HIDE ); 

		pWnd = GetDlgItem( IDC_EDIT_DEST );
		if( pWnd ) pWnd->ShowWindow( SW_HIDE ); 

		pWnd = GetDlgItem( IDC_WORKING_PROGRESS );
		if( pWnd ) pWnd->ShowWindow( SW_HIDE ); 

		pWnd = GetDlgItem( IDC_BUTTON_INSPECTION );
		if( pWnd ) pWnd->ShowWindow( SW_HIDE ); 

		pWnd = GetDlgItem( IDOK );
		if( pWnd ) pWnd->ShowWindow( SW_HIDE );

		pWnd = GetDlgItem( IDC_BUTTON_CLIENT );
		if( pWnd ) pWnd->ShowWindow( SW_HIDE );

		pWnd = GetDlgItem( IDC_BUTTON_DEST );
		if( pWnd ) pWnd->ShowWindow( SW_HIDE );
		
		pWnd = GetDlgItem( IDC_CHECK_REVISE_HEIGHT );
		if( pWnd ) pWnd->ShowWindow( SW_HIDE );

		// �۾� �߿� ǥ���� ��Ʈ�ѵ��� Show
		pWnd = GetDlgItem( IDC_WORKING_TEXT );
		if( pWnd ) pWnd->ShowWindow( SW_SHOW );

		pWnd = GetDlgItem( IDC_WORKING_PROGRESS );
		if( pWnd ) pWnd->ShowWindow( SW_SHOW );
	}
	else // �۾� ��尡 �ƴ� ���
	{
		CWnd* pWnd = NULL;

		// �ʱ�ȭ�� ��Ʈ�ѵ��� Show
		pWnd = GetDlgItem( IDC_STATIC1 );
		if( pWnd ) pWnd->ShowWindow( SW_SHOW );

		pWnd = GetDlgItem( IDC_STATIC2 );
		if( pWnd ) pWnd->ShowWindow( SW_SHOW );

		pWnd = GetDlgItem( IDC_STATIC3 );
		if( pWnd ) pWnd->ShowWindow( SW_SHOW );

		pWnd = GetDlgItem( IDC_COMBO_INPUT_TYPE );
		if( pWnd ) pWnd->ShowWindow( SW_SHOW ); 

		pWnd = GetDlgItem( IDC_EDIT_CLIENT );
		if( pWnd ) pWnd->ShowWindow( SW_SHOW ); 

		pWnd = GetDlgItem( IDC_EDIT_DEST );
		if( pWnd ) pWnd->ShowWindow( SW_SHOW ); 

		pWnd = GetDlgItem( IDC_WORKING_PROGRESS );
		if( pWnd ) pWnd->ShowWindow( SW_SHOW ); 

		pWnd = GetDlgItem( IDC_BUTTON_INSPECTION );
		if( pWnd ) pWnd->ShowWindow( SW_SHOW ); 

		pWnd = GetDlgItem( IDOK );
		if( pWnd ) pWnd->ShowWindow( SW_SHOW );

		pWnd = GetDlgItem( IDC_BUTTON_CLIENT );
		if( pWnd ) pWnd->ShowWindow( SW_SHOW );

		pWnd = GetDlgItem( IDC_BUTTON_DEST );
		if( pWnd ) pWnd->ShowWindow( SW_SHOW );
		
		pWnd = GetDlgItem( IDC_CHECK_REVISE_HEIGHT );
		if( pWnd ) pWnd->ShowWindow( SW_SHOW );

		// �۾� �߿� ǥ���� ��Ʈ�ѵ��� Hide
		pWnd = GetDlgItem( IDC_WORKING_TEXT );
		if( pWnd ) pWnd->ShowWindow( SW_HIDE );

		pWnd = GetDlgItem( IDC_WORKING_PROGRESS );
		if( pWnd ) pWnd->ShowWindow( SW_HIDE );
	}
}

void CTMonSpawnInspectorDlg::OnBnClickedWorkingStop()
{
	m_bStopWorking = TRUE;
}

BOOL CTMonSpawnInspectorDlg::OnInputFromFile()
{
	// ����Ÿ ���� �����ϱ�
	CFileDialog dlg(
		FALSE,
		_T("*.*"),
		"�Է��� ����Ÿ ������ �����Ͽ� �ֽʽÿ�",
		OFN_HIDEREADONLY,
		_T("Text File (*.txt)|*.txt||"));

	CString strPath("");

	TCHAR szCurPath[MAX_PATH];
	::GetCurrentDirectory( MAX_PATH, szCurPath );

	dlg.m_ofn.lpstrInitialDir = szCurPath;
	if( dlg.DoModal() == IDOK )
	{
		// ����Ÿ ���Ͽ��� ����Ÿ ��������
		strPath = dlg.GetPathName();

		CStdioFile file;
		if( !file.Open( strPath, CStdioFile::modeRead ) )
		{
			AfxMessageBox( "������ ��ȿ���� �ʽ��ϴ�", MB_OK );
			return FALSE;
		}

		SetControlWorkingMode(TRUE);
		SetProgressText( "���Ͽ��� ����Ÿ�� �д� �� �Դϴ�." );
		SetProgressRange( 0, (INT)file.GetLength() );

		INT nLineCount = 0;
		INT nBegin = 0;
		DWORD dwWorkCount = 0;
		while(1)
		{
			CString strLine;
			if( FALSE == file.ReadString(strLine) )
				break;

			if( FALSE == AddSpawnData( strLine ) )
			{
				CString strError;
				strError.Format( "%d ���ο��� ������ ������ϴ�.", ++nLineCount );
				AfxMessageBox( strError, MB_OK );
				file.Close();
				SetControlWorkingMode(FALSE);
				return FALSE;
			}

			nBegin += strLine.GetLength();
			m_ctrlWorkingProgress.SetPos( nBegin );

			if( !PeekAndPump( dwWorkCount, 20 ) )	 // 20���ο� �ѹ��� �޽��� ����
			{
				file.Close();
				return FALSE;
			}

			if( m_bStopWorking )
			{
				file.Close();
				SetControlWorkingMode(FALSE);
				m_bStopWorking = FALSE;
				return FALSE;
			}
		}

		file.Close();
		return TRUE;
	}
	return FALSE; // ���ϼ���â���� ��ҹ�ư�� ������ ���.
}

BOOL CTMonSpawnInspectorDlg::OnInputFromEditBox()
{
	CString strSource;

	CTMonSpawnInspectorCnPDlg dlg;
	dlg.m_pDest = &strSource;

	if( dlg.DoModal() == IDOK )
	{
		if( 0 != strSource.GetLength() )
		{
			SetControlWorkingMode(TRUE);

			m_stcWorkingText.SetWindowText("����Ÿ�� �д� �� �Դϴ�.");
			m_ctrlWorkingProgress.SetRange32( 0, strSource.GetLength() );

			INT nBegin = 0;
			INT nLineCount = 0;
			DWORD dwWorkCount = 0;
			while(1)
			{
				INT nEnd = strSource.Find( _T('\n'), nBegin );

				if( nEnd == -1 )
					break;

				CString strLine = strSource.Mid( nBegin, nEnd-nBegin );

				if( FALSE == AddSpawnData( strLine ) )
				{
					CString strError;
					strError.Format( "%d ���ο��� ������ ������ϴ�.", ++nLineCount );
					AfxMessageBox( strError, MB_OK );
					SetControlWorkingMode(FALSE);
					return FALSE;
				}

				nBegin = nEnd+1;
				m_ctrlWorkingProgress.SetPos( nBegin );

				if( !PeekAndPump( dwWorkCount, 100 ) ) // 100���� �ѹ��÷� �޽��� ����
					return FALSE;

				if( m_bStopWorking )
				{
					SetControlWorkingMode(FALSE);
					m_bStopWorking = FALSE;
					return FALSE;
				}
			}
			return TRUE;
		}
	}
	return FALSE;
}

INT CTMonSpawnInspectorDlg::ProcSortDataByMapID()
{
	DWORD dwProgress = 0;
	SetProgressText( "��������Ÿ�� �ʺ��� ����" );
	SetProgressRange( 0, (INT)m_vTSPAWNDATA.size() );

	for( VTSPAWNDATA::iterator it = m_vTSPAWNDATA.begin();
		it != m_vTSPAWNDATA.end();
		++it )
	{
		if( it->bEmptyLine == FALSE )
			InsertSpawnByMapID( it->wMapID, (*it) );

		SetProgressPos( ++dwProgress );
	}

	return TRUE;
}

INT CTMonSpawnInspectorDlg::ProcInspectData()
{
	// 1. ���ҽ� �ʱ�ȭ
	CTMonSpawnInspectorMAP* pMAP = new CTMonSpawnInspectorMAP;

	if( FALSE == pMAP->InitResource( "TClient" ) )
	{
		AfxMessageBox( "���Ӹ��ҽ� �ʱ�ȭ ����", MB_OK );
		return FALSE;
	}

	// 2. ��������Ÿ�� �ʾ��̵𺰷� ����
	if( FALSE ==  ProcSortDataByMapID() )
	{
		pMAP->TermResource();
		delete pMAP;
		return FALSE;
	}

	// 3. (�з���) �ʺ��� ���鼭 ��������Ÿ�� ó������.
	VTSORTEDMAP::iterator MapItr, MapEnd;
	MapItr = m_vTSORTEDMAP.begin();
	MapEnd = m_vTSORTEDMAP.end();

	for(; MapItr != MapEnd ; ++MapItr )
	{
		// ���� �ε����� ���� ��� ���Ͽ� ����Ǿ��ִ��� �����ε����� �����´�.
		LPTMAPINFO pMAPINFO = pMAP->GetMapINFO( MapItr->wMapID );

		CString strMSG;
		strMSG.Format( "%d �� �ε�",
			MapItr->wMapID );

		SetProgressText( strMSG );
		SetProgressClear();

		// �ʷε� - �����ε����� ���� ����.
		CTMonSpawnInspectorHUGEMAP* HUGEMAP = 	(CTMonSpawnInspectorHUGEMAP*)pMAP->m_Res.LockMAP( pMAPINFO->m_dwMapID );

		SetProgressRange(0,1);
		SetProgressPos(1);

		if( HUGEMAP == NULL )
		{
			CString strError;
			strError.Format( "%d���� ���� �� �߽��ϴ�.",
				MapItr->wMapID );
			AfxMessageBox( strError, MB_OK );
			continue;
		}

		VTSORTEDUNIT vUnits;			// ���� ��� ���������͸� ���ֺ��� �з��Ͽ� �����ų ��.

		// 4. �ʾȿ����� ���ֺ��� ��������Ÿ�� �з��Ѵ�.
		{
			DWORD dwProgress = 0;

			CString strMSG;
			strMSG.Format( "%d �ʿ� �ִ� ��������Ÿ�� ���ֺ��� �з�",
				MapItr->wMapID );

			SetProgressText( strMSG );
			SetProgressClear();

			LTSPAWNDATA::iterator SpawnItr, SpawnEnd;
			SpawnItr = MapItr->lSpawnData.begin();
			SpawnEnd = MapItr->lSpawnData.end();

			for(; SpawnItr != SpawnEnd ; ++SpawnItr )
			{
				// ��ġ������ �ʾ��� ��� ���ֿ� �����ϴ��� �˾ֳ���.
				INT nUnitIndex = HUGEMAP->GetUNITID( D3DXVECTOR3( SpawnItr->fPosX, SpawnItr->fPosY, SpawnItr->fPosZ ) );

				// �׸��� �� �˾Ƴ� �����ε����� �´� ���� ��������Ÿ�� �־�����.
				LTSPAWNDATA& lSpawnData = FindSpawnArrayByUnitIndex( vUnits, nUnitIndex, HUGEMAP->m_nUnitX, HUGEMAP->m_nUnitZ );
				lSpawnData.push_back( *SpawnItr );

				SetProgressPos( ++dwProgress );
			}

			if( dwProgress != MapItr->lSpawnData.size() )
			{
				CString strError;
				strError.Format( "%d�ʿ��� �� ��������Ÿ ������ ���ֺ��� �з��� ������������ ������ ���� �ʽ��ϴ�.",
					MapItr->wMapID );
				AfxMessageBox( strError, MB_OK );
			}

			MapItr->lSpawnData.clear();
		}

		// 5. ���� ���ֺ��� ��������Ÿ�� ���ĵư� ���ֺ��� �ε��ϸ鼭 ��������Ÿ�� ���� �˻��Ѵ�.
		{
			VTSORTEDUNIT::iterator UnitItr, UnitEnd;
			UnitItr = vUnits.begin();
			UnitEnd = vUnits.end();

			for(; UnitItr != UnitEnd ; ++UnitItr )
			{
				INT nUnitID = UnitItr->nUnitIndex;

				SetProgressText( "" );
				SetProgressClear();

				// ���� �ε��� �� �ִ� �������� �˻��Ѵ�.
				if( FALSE == HUGEMAP->CheckAvailableLoadUNIT( nUnitID ) )
				{
					LTSPAWNDATA::iterator SpawnItr, SpawnEnd;
					SpawnItr = UnitItr->lSpawnData.begin();
					SpawnEnd = UnitItr->lSpawnData.end();

					// ������ �ε��� �� ������ �� ���ֿ� �ִ� ��� ��������Ÿ�� ������ ����.
					for(; SpawnItr != SpawnEnd ; ++SpawnItr )
					{
						TRESULT RESULT;					
						RESULT.SpawnData = *SpawnItr;
						RESULT.bResult = TRESULT_INVALID_UNIT;
						m_vTRESULT.push_back( RESULT );
					}
					continue;
				}

				strMSG.Format( "%d���� %d,%d ���� �ε�", MapItr->wMapID, UnitItr->nUnitX, UnitItr->nUnitZ );
				SetProgressText( strMSG );
				SetProgressClear();

				// �� �����ε����� ���������� ������ �ε��Ѵ�.
				HUGEMAP->LoadUNIT( nUnitID );

				strMSG.Format( "%d���� %d,%d���� �ʱ�ȭ", MapItr->wMapID, UnitItr->nUnitX, UnitItr->nUnitZ );
				SetProgressText( strMSG );
				SetProgressClear();

				// �ε��� �� ���־ȿ� (�ν��Ͻ�����Ÿ)������Ʈ���� �ʱ�ȭ�� �����Ѵ�.
				pMAP->LoadMAPOBJ( HUGEMAP );

				// ���� ���־ȿ� ����ִ� (�ν��Ͻ�����Ÿ)������Ʈ���� ��ü�� �����Ǿ�
				// pMAP->m_vCOLL�� ����ƴ�.

				LTSPAWNDATA::iterator SpawnItr, SpawnEnd;
				SpawnItr = UnitItr->lSpawnData.begin();
				SpawnEnd = UnitItr->lSpawnData.end();

				strMSG.Format( "%d���� %d,%d������ ���� �˻�", MapItr->wMapID, UnitItr->nUnitX, UnitItr->nUnitZ );

				DWORD dwProgress = 0;
				SetProgressText( strMSG );
				SetProgressRange( 0, (INT)UnitItr->lSpawnData.size() );

				DWORD dwWorkCount = 0;

				// ���� �� ���ֿ� ���� ��������Ÿ���� ��� �˻��غ���.
				// (pMAP->m_vCOLL�� �ִ� ��ü��� �浹�ϴ��� �˻�)
				for(; SpawnItr != SpawnEnd ; ++SpawnItr )
				{
					D3DXVECTOR3 vPos( SpawnItr->fPosX, SpawnItr->fPosY, SpawnItr->fPosZ );
					FLOAT fRange = SpawnItr->bRange;

					BOOL bValidPoint = FALSE;
					BOOL bValidHeight = FALSE;

					FLOAT fResultHeight = 0.0f;
					FLOAT fResultLandHeight = 0.0f;

					bValidPoint = pMAP->IsValidPoint( vPos, fRange );					// �� ��ġ�� �ֺ��� ������Ʈ�� ��� ��ȿ�Ѱ�?
					bValidHeight = pMAP->IsValidHeight( HUGEMAP, vPos, fRange, &fResultHeight, &fResultLandHeight );	// �� ��ġ�� ���̰��� ��ȿ�Ѱ�?

					if( !bValidPoint || !bValidHeight ) // �浹�ȴٸ� ���!
					{
						TRESULT RESULT;

						RESULT.SpawnData = *SpawnItr;
						RESULT.bResult = 0;
						RESULT.fResultHeight = fResultHeight;
						RESULT.fResultLandHeight = fResultLandHeight;

						if( !bValidPoint )
						{
							RESULT.bResult |= TRESULT_INVALID_POINT;
						}

						if( !bValidHeight )
						{
							RESULT.bResult |= TRESULT_INVALID_HEIGHT;
						}

						m_vTRESULT.push_back( RESULT );
					}

					SetProgressPos( ++dwProgress );

				} // end for(; SpawnItr != SpawnEnd ; ++SpawnItr )

				// ���� �� ���ֿ� �����ϴ� ��� ���������ʹ� �˻������Ƿ�
				// �Ҵ��ߴ� �ڿ��� �����ϰ� ���� �������� �Ѿ��.
				pMAP->ClearCOLL();					// ���� pMAP->LoadMAPOBJ���� �Ҵ��� �ڿ� ����
				HUGEMAP->UnloadUNIT();

			} // end for(; UnitItr != UnitEnd ; ++UnitItr )
		}

		// ���� pMAP->m_Res.LockMAP���� �Ҵ��� �ڿ� ����
		HUGEMAP->Release();
		for( int i=0 ; i < 9 ; ++i )
			HUGEMAP->m_UNIT[ i ].Release();

		// ������
		delete HUGEMAP;
	}

	// ������
	pMAP->TermResource();
	delete pMAP;
	return TRUE;
}

INT CTMonSpawnInspectorDlg::ProcWriteReport()
{
	SetProgressText( "����Ʈ �ۼ�" );
	SetProgressClear();

	if( 0 == m_vTRESULT.size() )
	{
		AfxMessageBox( "��� ������ ���� ��ġ�� ��ȿ�մϴ�!", MB_OK );
		SetProgressRange(0,1);
		SetProgressPos(1);
		return TRUE;
	}

	FILE* fp = fopen( m_strDESTPATH, "wt" );
	if( !fp )
	{
		CString strError;
		strError.Format( "%s�� ������ ���� �� �� �����ϴ�.", m_strDESTPATH );
		AfxMessageBox( strError, MB_OK );
		return FALSE;
	}

	fprintf( fp, "%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
		"���� ����",
		"���� ��",
		"POS X",
		"POS Y",
		"POS Z",
		"���� �ݰ�",
		"����",
		"��������",
		"������");

	DWORD dwProgress = 0;
	SetProgressRange( 0, (INT)m_vTRESULT.size() );

	for( VTRESULT::iterator itRESULT = m_vTRESULT.begin();
		itRESULT != m_vTRESULT.end();
		++itRESULT )
	{
		CString strError;

		if( (itRESULT->bResult & TRESULT_INVALID_POINT) == TRESULT_INVALID_POINT )
			strError += "������Ʈ �浹;";

		if( (itRESULT->bResult & TRESULT_INVALID_HEIGHT) == TRESULT_INVALID_HEIGHT )
			strError += "�߸��� ����;";

		if( (itRESULT->bResult & TRESULT_INVALID_UNIT) == TRESULT_INVALID_UNIT )
			strError += "���� ����;";

		// �۾�
		fprintf( fp, "%d,%d,%f,%f,%f,%d,%s,%f,%f\n",
			itRESULT->SpawnData.wSpawnID,
			itRESULT->SpawnData.wMapID,
			itRESULT->SpawnData.fPosX,
			itRESULT->SpawnData.fPosY,
			itRESULT->SpawnData.fPosZ,
			itRESULT->SpawnData.bRange,
			(LPCTSTR)strError,
			itRESULT->fResultHeight,
			itRESULT->fResultLandHeight);

		SetProgressPos(++dwProgress);
	}

	fclose(fp);

	if( m_bReviseHeight )
		ProcWriteReviseHeightReport();

	// �Ϸ�
	CString strError;
	strError.Format( "�� %d���� ������ġ���� ������ ����Ǿ����ϴ�.\n%s ������ Ȯ���Ͻʽÿ�",
		(DWORD)m_vTRESULT.size(),
		m_strDESTPATH );

	AfxMessageBox( strError, MB_OK );

	return TRUE;
}

class Cond_Same_ID
{
public:
	WORD m_wSpawnId;

	bool operator()(const TSPAWNDATA &spawnData)
	{
		if( m_wSpawnId == spawnData.wSpawnID )
			return true;
		else
			return false;
	};

	Cond_Same_ID( WORD wSpawnId )
		: m_wSpawnId(wSpawnId)
	{}
};

INT CTMonSpawnInspectorDlg::ProcWriteReviseHeightReport()
{
	INT nCount = 0;
	
	SetProgressClear();
	SetProgressText( "������ ���̰� ����Ʈ �ۼ�" );

	SetProgressRange( 0, (INT)m_vTRESULT.size() );
	
	// 1. �߸��� �ֵ��� ã�Ƽ� ������ �־�����.
	for( VTRESULT::iterator itRESULT = m_vTRESULT.begin();
		itRESULT != m_vTRESULT.end();
		++itRESULT )
	{
		// �̰ɷ� m_vTSPAWNDATA ���� ã�´�.

		// �׳� �����˻�����.
		VTSPAWNDATA::iterator it = 	std::find_if(
													m_vTSPAWNDATA.begin(),
													m_vTSPAWNDATA.end(),
													Cond_Same_ID(itRESULT->SpawnData.wSpawnID) );

		if( it != m_vTSPAWNDATA.end() )
			it->fPosY = itRESULT->fResultHeight; //fResultHeight <- ��� �ǹٸ� ���̰�
		else
			AfxMessageBox( "���� �� ���� ��");

		SetProgressPos( nCount++ );
	}
	
	nCount = 0;

	SetProgressClear();
	SetProgressRange( 0, (INT)m_vTSPAWNDATA.size() );

	// 2. (���̰��� �����)������ �״�� ���. (CnP�� �� �� �ְԲ�)
	CString strDESTPATH = m_strDESTPATH + "_height.txt";

	FILE* fp = fopen( strDESTPATH, "wt" );
	if( !fp )
	{
		CString strError;
		strError.Format( "%s�� ������ ���� �� �� �����ϴ�.", strDESTPATH );
		AfxMessageBox( strError, MB_OK );
		return FALSE;
	}
	
	for( VTSPAWNDATA::iterator itSPAWNDATA = m_vTSPAWNDATA.begin();
		itSPAWNDATA != m_vTSPAWNDATA.end();
		++itSPAWNDATA )
	{
		if( itSPAWNDATA->bEmptyLine )
			fprintf( fp, "\n");
		else
			fprintf( fp, "%.2f\n", itSPAWNDATA->fPosY);

		SetProgressPos( nCount++ );
	}

	fclose(fp);

	return TRUE;
}

VOID CTMonSpawnInspectorDlg::InsertSpawnByMapID(
	WORD wMapID,
	TSPAWNDATA& data)
{
	// �ʾ��̵�� �ʸ���Ʈ���� ã�Ƽ� �ش� ���������͸� ����.
	for(VTSORTEDMAP::iterator itTSORTEDMAP = m_vTSORTEDMAP.begin();
		itTSORTEDMAP != m_vTSORTEDMAP.end();
		++itTSORTEDMAP)
	{
		if( itTSORTEDMAP->wMapID == wMapID )
		{
			itTSORTEDMAP->lSpawnData.push_back( data );
			return ;
		}
	}

	// ����ְ����ϴ� ��������Ÿ�� ���� ����Ʈ�� ������ �߰�.
	m_vTSORTEDMAP.push_back( TSORTEDMAP(wMapID) );
	itTSORTEDMAP = --m_vTSORTEDMAP.end();
	itTSORTEDMAP->lSpawnData.push_back( data );
	return ;
}


LTSPAWNDATA& CTMonSpawnInspectorDlg::FindSpawnArrayByUnitIndex(
	VTSORTEDUNIT& vUnits,
	INT nUnitIndex,
	INT nUnitX,
	INT nUnitZ )
{
	for( VTSORTEDUNIT::iterator itSORTEDUNIT = vUnits.begin();
		itSORTEDUNIT != vUnits.end();
		++itSORTEDUNIT )
	{
		if( itSORTEDUNIT->nUnitIndex == nUnitIndex &&
			itSORTEDUNIT->nUnitX == nUnitX &&
			itSORTEDUNIT->nUnitZ == nUnitZ )
			return itSORTEDUNIT->lSpawnData;
	}

	vUnits.push_back( TSORTEDUNIT(nUnitIndex,nUnitX,nUnitZ) );
	itSORTEDUNIT = --vUnits.end();
	return itSORTEDUNIT->lSpawnData;
}