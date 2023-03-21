// ShrinkTMODlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ShrinkTMO.h"
#include "ShrinkTMODlg.h"
#include ".\shrinktmodlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CShrinkTMODlg ��ȭ ����

CShrinkTMODlg::CShrinkTMODlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShrinkTMODlg::IDD, pParent)
	, m_strSRC(_T(""))
	, m_strDEST(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShrinkTMODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_SRCFOLDER, m_cSRC);
	DDX_Control(pDX, IDC_BUTTON_DEST, m_cDEST);
	DDX_Text(pDX, IDC_EDIT_SRCFOLDER, m_strSRC);
	DDX_Text(pDX, IDC_EDIT_DEST, m_strDEST);
}

BEGIN_MESSAGE_MAP(CShrinkTMODlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_DEST, OnBnClickedButtonDest)
	ON_BN_CLICKED(IDC_BUTTON_SRCFOLDER, OnBnClickedButtonSrcfolder)
	ON_BN_CLICKED(ID_REGULATE, OnBnClickedRegulate)
END_MESSAGE_MAP()


// CShrinkTMODlg �޽��� ó����

BOOL CShrinkTMODlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	HICON hIcon = AfxGetApp()->LoadIcon(IDI_ICON_FOLDER);
	m_cDEST.SetIcon(hIcon);
	m_cSRC.SetIcon(hIcon);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShrinkTMODlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialog::OnSysCommand(nID, lParam);
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸����� 
// �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
// �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CShrinkTMODlg::OnPaint() 
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
HCURSOR CShrinkTMODlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CShrinkTMODlg::OnBnClickedButtonDest()
{
	CTShell dlg;

	dlg.m_strSelDir = m_strDESTFOLDER;
	dlg.m_strTitle = _T("Target Folder");

	if( dlg.BrowseForFolder(this) == IDOK )
	{
		UpdateData();
		m_strDESTFOLDER = dlg.m_strPath;
		m_strDEST = dlg.m_strPath;
		UpdateData(FALSE);
	}
}

void CShrinkTMODlg::OnBnClickedButtonSrcfolder()
{
	CTShell dlg;

	dlg.m_strSelDir = m_strSRCFOLDER;
	dlg.m_strTitle = _T("TMO Folder");

	if( dlg.BrowseForFolder(this) == IDOK )
	{
		UpdateData();
		m_strSRCFOLDER = dlg.m_strPath;
		m_strSRC = dlg.m_strPath;
		UpdateData(FALSE);
	}
}

BYTE CShrinkTMODlg::IsTMOFile( CString strFileName)
{
	CString strExt;
	CTShell shell;

	strExt = shell.GetFileExt(strFileName);
	strExt.MakeUpper();
	strExt.TrimRight();
	strExt.TrimLeft();

	if( strExt == _T(".TMO") )
		return TRUE;

	return FALSE;
}

void CShrinkTMODlg::OnBnClickedRegulate()
{
	Regulate( m_strSRC, m_strDEST);
}

void CShrinkTMODlg::Regulate( CString strSRC, CString strDEST)
{
	CFileFind finder;
	CString strFIND;

	strDEST.TrimRight('\\');
	strSRC.TrimRight('\\');
	strFIND.Format(
		"%s\\*.*",
		strSRC);

	BOOL bFind = finder.FindFile(strFIND);
	while(bFind)
	{
		bFind = finder.FindNextFile();

		if(finder.IsDots())
			continue;

		if(finder.IsDirectory())
		{
			CreateDirectory( LPCSTR(strDEST + CString("\\") + finder.GetFileTitle()), NULL);
			Regulate(
				strSRC + CString("\\") + finder.GetFileTitle(),
				strDEST + CString("\\") + finder.GetFileTitle());

			continue;
		}

		if(IsTMOFile(finder.GetFilePath()))
		{
			CFile vDEST( LPCSTR(strDEST + CString("\\") + finder.GetFileName()), CFile::modeCreate|CFile::modeWrite|CFile::typeBinary);
			CFile vSRC( LPCSTR(finder.GetFilePath()), CFile::modeRead|CFile::typeBinary);

			Regulate( &vSRC, &vDEST);
		}
	}
}

void CShrinkTMODlg::Regulate( CFile *pSRC, CFile *pDEST)
{
	CStdioFile	file;
	CString		str;
	
	file.Open(_T("MapIndex.txt"), CFile::modeRead);
	MAPID  mapMapID;
	while(file.ReadString(str))
	{
		str.TrimRight();
		str.TrimLeft();
		if(!str.IsEmpty())
		{
			DWORD CurrentMapID;
			DWORD OldMapID;
			sscanf(str, "%d %d", &CurrentMapID, &OldMapID);
			mapMapID.insert(MAPID::value_type(CurrentMapID, OldMapID));
		}
	}
	
	VTSIMPLEOBJ vTSIMPLEOBJ;
	
	DWORD dwMaxOBJID;
	DWORD dwMaxSFXID;
	DWORD dwMaxSNDID;
	DWORD dwCount;
	DWORD dwVER;

	int nUnitCountX;
	int nTileLength;

	pSRC->Read( &dwVER, sizeof(DWORD));
	pDEST->Write( &dwVER, sizeof(DWORD));

	pSRC->Read( &dwMaxOBJID, sizeof(DWORD));
	pDEST->Write( &dwMaxOBJID, sizeof(DWORD));

	pSRC->Read( &dwMaxSFXID, sizeof(DWORD));
	pDEST->Write( &dwMaxSFXID, sizeof(DWORD));

	pSRC->Read( &dwMaxSNDID, sizeof(DWORD));
	pDEST->Write( &dwMaxSNDID, sizeof(DWORD));

	pSRC->Read( &dwCount, sizeof(DWORD));
	pDEST->Write( &dwCount, sizeof(DWORD));

	pSRC->Read( &nUnitCountX, sizeof(int));
	pDEST->Write( &nUnitCountX, sizeof(int));

	pSRC->Read( &nTileLength, sizeof(int));
	pDEST->Write( &nTileLength, sizeof(int));
	vTSIMPLEOBJ.clear();

	for( DWORD i=0; i<dwCount; i++)
	{
		DWORD dwOBJCount = 0;
		DWORD dwPOS;
		DWORD dwOBJ;
		int nEnable;

		pSRC->Read( &nEnable, sizeof(int));
		pDEST->Write( &nEnable, sizeof(int));

		dwPOS = (DWORD) pDEST->GetPosition();
		pSRC->Read( &dwOBJ, sizeof(DWORD));
		pDEST->Write( &dwOBJ, sizeof(DWORD));

		for( DWORD j=0; j<dwOBJ; j++)
		{
			D3DXVECTOR3 vSCALE;
			D3DXVECTOR3 vROT;
			D3DXVECTOR3 vPOS;

			DWORD dwItemID;
			DWORD dwID;

			pSRC->Read( &dwID, sizeof(DWORD));
			pSRC->Read( &dwItemID, sizeof(DWORD));

			pSRC->Read( &vSCALE, sizeof(D3DXVECTOR3));
			pSRC->Read( &vPOS, sizeof(D3DXVECTOR3));
			pSRC->Read( &vROT, sizeof(D3DXVECTOR3));

			if(FindMAPOBJ( &vTSIMPLEOBJ, vSCALE, vROT, vPOS, dwItemID))
			{
				int nATTR;
				int nCLK;

				pSRC->Seek( sizeof(DWORD), CFile::current);
				pSRC->Seek( sizeof(DWORD), CFile::current);
				pSRC->Seek( sizeof(DWORD), CFile::current);
				pSRC->Seek( sizeof(DWORD), CFile::current);
				pSRC->Seek( sizeof(DWORD), CFile::current);

				pSRC->Read( &nCLK, sizeof(int));
				for( int k=0; k<nCLK; k++)
				{
					pSRC->Seek( sizeof(DWORD), CFile::current);
					pSRC->Seek( sizeof(DWORD), CFile::current);
					pSRC->Seek( sizeof(DWORD), CFile::current);
				}

				pSRC->Read( &nATTR, sizeof(int));
				for( k=0; k<nATTR; k++)
				{
					BYTE bValueType;
					int nSIZE;

					LoadString(pSRC);
					pSRC->Read( &bValueType, sizeof(BYTE));
					pSRC->Read( &nSIZE, sizeof(int));
					pSRC->Seek( nSIZE, CFile::current);
				}
			}
			else
			{
				LPTSIMPLEOBJ pTSIMPLEOBJ = new TSIMPLEOBJ();
				DWORD dwDATA;

				int nATTR;
				int nCLK;

				pTSIMPLEOBJ->m_vSCALE = vSCALE;
				pTSIMPLEOBJ->m_vROT = vROT;
				pTSIMPLEOBJ->m_vPOS = vPOS;
				pTSIMPLEOBJ->m_dwItemID = dwItemID;

				vTSIMPLEOBJ.push_back(pTSIMPLEOBJ);
				dwOBJCount++;

				pDEST->Write( &dwID, sizeof(DWORD));
				pDEST->Write( &dwItemID, sizeof(DWORD));

				pDEST->Write( &vSCALE, sizeof(D3DXVECTOR3));
				pDEST->Write( &vPOS, sizeof(D3DXVECTOR3));
				pDEST->Write( &vROT, sizeof(D3DXVECTOR3));

				pSRC->Read( &dwDATA, sizeof(DWORD));
				pDEST->Write( &dwDATA, sizeof(DWORD));

				pSRC->Read( &dwDATA, sizeof(DWORD));
				pDEST->Write( &dwDATA, sizeof(DWORD));

				pSRC->Read( &dwDATA, sizeof(DWORD));
				pDEST->Write( &dwDATA, sizeof(DWORD));

				pSRC->Read( &dwDATA, sizeof(DWORD));
				pDEST->Write( &dwDATA, sizeof(DWORD));

				pSRC->Read( &dwDATA, sizeof(DWORD));
				pDEST->Write( &dwDATA, sizeof(DWORD));

				pSRC->Read( &nCLK, sizeof(int));
				pDEST->Write( &nCLK, sizeof(int));
				for( int k=0; k<nCLK; k++)
				{
					pSRC->Read( &dwDATA, sizeof(DWORD));
					pDEST->Write( &dwDATA, sizeof(DWORD));

					pSRC->Read( &dwDATA, sizeof(DWORD));
					pDEST->Write( &dwDATA, sizeof(DWORD));

					pSRC->Read( &dwDATA, sizeof(DWORD));
					pDEST->Write( &dwDATA, sizeof(DWORD));
				}

				pSRC->Read( &nATTR, sizeof(int));
				pDEST->Write( &nATTR, sizeof(int));

				for( k=0; k<nATTR; k++)
				{
					BYTE bValueType;
					int nSIZE;
					
					CFile* pTemp = pSRC;
					CString strMapID;
					WriteString( pDEST, strMapID =  LoadString(pSRC));
					
					pSRC->Read( &bValueType, sizeof(BYTE));
					pDEST->Write( &bValueType, sizeof(BYTE));

					pSRC->Read( &nSIZE, sizeof(int));
					pDEST->Write( &nSIZE, sizeof(int));

					if( nSIZE > 0 )
					{
						LPBYTE pDATA = new BYTE[nSIZE];
						pSRC->Read( pDATA, nSIZE);
					
						if("ID_MAP_ID" == strMapID)
						{
							MAPID::iterator it;
							it = mapMapID.find( *((DWORD*)pDATA) );
							DWORD dwDATA;
							if(it != mapMapID.end())
							{
								dwDATA = (*it).second;
								pDEST->Write( &dwDATA, sizeof(DWORD));
							}
							else
								pDEST->Write( pDATA, nSIZE);
						}
						else
							pDEST->Write( pDATA, nSIZE);

						delete[] pDATA;
					}
				}
			}
		}

		pDEST->Seek( dwPOS, CFile::begin);
		pDEST->Write( &dwOBJCount, sizeof(DWORD));
		pDEST->SeekToEnd();

		pSRC->Read( &dwOBJ, sizeof(DWORD));
		pDEST->Write( &dwOBJ, sizeof(DWORD));

		for( j=0; j<dwOBJ; j++)
		{
			D3DXVECTOR3 vROT;
			D3DXVECTOR3 vPOS;

			DWORD dwItemID;
			DWORD dwID;
			BYTE bBias;

			pSRC->Read( &dwID, sizeof(DWORD));
			pDEST->Write( &dwID, sizeof(DWORD));

			pSRC->Read( &dwItemID, sizeof(DWORD));
			pDEST->Write( &dwItemID, sizeof(DWORD));

			pSRC->Read( &vPOS, sizeof(D3DXVECTOR3));
			pDEST->Write( &vPOS, sizeof(D3DXVECTOR3));

			pSRC->Read( &vROT, sizeof(D3DXVECTOR3));
			pDEST->Write( &vROT, sizeof(D3DXVECTOR3));

			pSRC->Read( &bBias, sizeof(BYTE));
			pDEST->Write( &bBias, sizeof(BYTE));
		}

		pSRC->Read( &dwOBJ, sizeof(DWORD));
		pDEST->Write( &dwOBJ, sizeof(DWORD));

		for( j=0; j<dwOBJ; j++)
		{
			D3DXVECTOR3 vPOS;

			DWORD dwItemID;
			DWORD dwID;

			pSRC->Read( &dwID, sizeof(DWORD));
			pDEST->Write( &dwID, sizeof(DWORD));

			pSRC->Read( &dwItemID, sizeof(DWORD));
			pDEST->Write( &dwItemID, sizeof(DWORD));

			pSRC->Read( &vPOS, sizeof(D3DXVECTOR3));
			pDEST->Write( &vPOS, sizeof(D3DXVECTOR3));
		}
	}

	while(!vTSIMPLEOBJ.empty())
	{
		delete vTSIMPLEOBJ.back();
		vTSIMPLEOBJ.pop_back();
	}

	file.Close();
	mapMapID.clear();
}

BYTE CShrinkTMODlg::FindMAPOBJ( LPVTSIMPLEOBJ pBUF,
							    D3DXVECTOR3& vSCALE,
								D3DXVECTOR3& vROT,
								D3DXVECTOR3& vPOS,
								DWORD dwItemID)
{
	for( int i=0; i<INT(pBUF->size()); i++)
		if( (*pBUF)[i]->m_dwItemID == dwItemID &&
			(*pBUF)[i]->m_vSCALE == vSCALE &&
			(*pBUF)[i]->m_vPOS == vPOS &&
			(*pBUF)[i]->m_vROT == vROT )
			return TRUE;

	return FALSE;
}

CString CShrinkTMODlg::LoadString( CFile *pFile)
{
	CString strResult("");
	int nLength;

	pFile->Read( &nLength, sizeof(int));
	if( nLength > 0 )
	{
		pFile->Read( strResult.GetBuffer(nLength), nLength);
		strResult.ReleaseBuffer(nLength);

		return strResult.Left(nLength);
	}

	return strResult;
}

void CShrinkTMODlg::WriteString( CFile *pFile, CString& strValue)
{
	int nLength = strValue.GetLength();

	pFile->Write( &nLength, sizeof(int));
	if( nLength > 0 )
		pFile->Write( LPCSTR(strValue), nLength);
}

