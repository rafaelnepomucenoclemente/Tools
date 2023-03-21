// TRCImporterDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "TRCImporter.h"
#include "TRCImporterDlg.h"
#include ".\trcimporterdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTRCImporterDlg ��ȭ ����



CTRCImporterDlg::CTRCImporterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTRCImporterDlg::IDD, pParent)
	, m_strRCPath(_T(""))
	, m_strCSV(_T(""))
	, m_nNation(0)
	, m_strTargetPath(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTRCImporterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strRCPath);
	DDX_Text(pDX, IDC_EDIT2, m_strCSV);
	DDX_CBIndex(pDX, IDC_COMBO1, m_nNation);
	DDX_Text(pDX, IDC_EDIT3, m_strTargetPath);
}

BEGIN_MESSAGE_MAP(CTRCImporterDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton3)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON4, OnBnClickedButton4)
END_MESSAGE_MAP()


// CTRCImporterDlg �޽��� ó����

BOOL CTRCImporterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	// �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	
	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸����� 
// �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
// �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CTRCImporterDlg::OnPaint() 
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
HCURSOR CTRCImporterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTRCImporterDlg::OnBnClickedButton2()
{
	CFileDialog dlg(
		TRUE,
		_T("*.txt"),
		NULL,
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		_T("RC Text Files (*.rc)|*.rc|All Files (*.*)|*.*||"));

	if( dlg.DoModal() == IDOK )
	{
		m_strRCPath = dlg.GetPathName();
		UpdateData(FALSE);
	}
}

void CTRCImporterDlg::OnBnClickedButton3()
{
	CFileDialog dlg(
		TRUE,
		_T("*.txt"),
		NULL,
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		_T("CSV Text Files (*.csv)|*.csv|All Files (*.*)|*.*||"));

	if( dlg.DoModal() == IDOK )
	{
		m_strCSV = dlg.GetPathName();
		UpdateData(FALSE);
	}
}

void CTRCImporterDlg::OnBnClickedButton4()
{
	CFileDialog dlg(
		TRUE,
		_T("*.txt"),
		NULL,
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		_T("RC Text Files (*.rc)|*.rc|All Files (*.*)|*.*||"));

	if( dlg.DoModal() == IDOK )
	{
		m_strTargetPath = dlg.GetPathName();
		UpdateData(FALSE);
	}
}

void CTRCImporterDlg::OnBnClickedOk()
{
	UpdateData();

	if( Import( m_strCSV, m_strRCPath, m_strTargetPath, m_nNation) )
		AfxMessageBox("Success");
	else
		AfxMessageBox("Fail");

	OnOK();
}

int ParseCSV( LPCTSTR str, std::vector<CString> *pList) 
{ 
    int cnt = 0; 
    CString buffer; 
    int mode = 0; 
    
    while(*str) 
    {  
        if(mode == 0) 
        {      
            if(*str == ',') 
            { 
                pList->push_back(buffer); 
                buffer = ""; 
            } 
            else if(*str == '\"') 
            { 
                mode = 1;            
            } 
            else 
                buffer += *str; 
        } 
        else if(mode == 1) 
        { 
            if(*str == '\"') 
            { 
                ++str; 
                if(*str == '\"') 
                    buffer += '\"'; 
                else if(*str == ',') 
                { 
                    mode = 0; 
                    pList->push_back(buffer); 
                    buffer = ""; 
                } 
                else 
                    buffer += *str; 
            } 
            else 
                buffer += *str; 
        } 
        
        ++str; 
    }    

    pList->push_back(buffer); 
    return (int)pList->size();
}

static int NONE = 0;
static int START = 1;
static int END = 2;

INT ReplaceNewText( CString& strLINE, CString& strNEW )
{
	CString strOLD;

	INT nLineLength = strLINE.GetLength();
	INT nMode = NONE;

	for( INT i=0; i<nLineLength; i++)
	{
		BYTE c = strLINE.GetAt(i);

		if(MBCS_LEAD_TEST(c))
		{
			strOLD += c;
			strOLD += strLINE.GetAt(i + 1);
			i++;

			continue;
		}
		else if( c == '"' && nMode == NONE) 
		{
			nMode = START;
			strOLD += c;
			continue;
		}
		else if( c == '"' && nMode == START)
		{
			if( i + 1 != nLineLength &&
				strLINE.GetAt(i+1) == '"')
			{
				strOLD += c;
				strOLD += strLINE.GetAt(i + 1);
				i++;

				continue;
			}
			else
			{
				nMode = END;
				strOLD += c;
				break; // ������ ����ǥ�̴�.
			}
		}
		else if( nMode == START )
		{
			strOLD += c;
			continue;
		}
	}

	if( nMode == END )
	{
		strLINE.Replace(
			strOLD,
			strNEW);
		return 1;
	}
	else
	{
		return 0;	// �ؽ�Ʈ�� �����ٿ� �ִ�.
	}
}

static LPCTSTR vNATION[][3] =
{
	{ "LANG_GERMAN", "code_page(1252)", "#ifdef GERMANY\n" }, // GERMANY
	{ "LANG_KOREAN", "code_page(949)", "#ifdef ENGLISH\n" }, // ENGLISH
	{ "LANG_JAPANESE", "code_page(932)", "#ifdef JAPAN\n" }, // JAPAN
};

int CTRCImporterDlg::Import(CString strCSVPath, CString strRCPath, CString strTargetPath, int nNation)
{
	std::map<CString,CString> m_mapIDtoTRANS;

	// CSV���� �Ľ�
	{
		CStdioFile vSRC;

		if( vSRC.Open( strCSVPath, CFile::modeRead|CFile::typeText) )
		{
			CString strDATA;
			std::vector<CString> vELEM;

			while(vSRC.ReadString(strDATA))
			{
				vELEM.clear();

				ParseCSV( (LPCTSTR)strDATA, &vELEM );
				if( vELEM.size() >= 3 )
				{
					CString& strID = vELEM[0];
					CString strTRANS = vELEM[2];

					if( strID.IsEmpty() )
						continue;

					strTRANS.Replace( "\"", "\"\"");

					CString strTEXT("\"A\"");
					strTEXT.Replace( "A", strTRANS);

					m_mapIDtoTRANS.insert(
						std::map<CString,CString>::value_type(
							strID, strTEXT));
				}
			}

			vSRC.Close();
		}
		else
			return FALSE;
	}

	{
		BOOL bChangedLocal = FALSE;
		BOOL bChangedCodePage = FALSE;

		CStdioFile vSRC;
		CStdioFile vDEST;

		if( vDEST.Open( strTargetPath, CFile::modeCreate|CFile::modeWrite|CFile::typeText) &&
			vSRC.Open( strRCPath, CFile::modeRead|CFile::typeText) )
		{
			CString strLINE;

			vDEST.WriteString( vNATION[ nNation ][2] );

			while(vSRC.ReadString(strLINE))
			{
				int iStart=0;
				CString strTOKEN = strLINE.Tokenize( " \t\n\r", iStart);

				std::map<CString,CString>::iterator it =
					m_mapIDtoTRANS.find( strTOKEN);

				if( it != m_mapIDtoTRANS.end() )
				{
					//ã�Ҵ�.
					CString& strNEW = it->second;
					if( !ReplaceNewText( strLINE, strNEW ) )
					{
						vDEST.WriteString(strLINE);
						vDEST.WriteString("\n");
						// �����ٿ� �ؽ�Ʈ�� �ֱ���.
						strLINE.Empty();
						vSRC.ReadString(strLINE);
						if( 0 == ReplaceNewText( strLINE, strNEW) )
							ASSERT(1); // ū�ϳ�����.
					}
				}
				
				if( !bChangedLocal )
				{
					if( strLINE.Find( "LANG_KOREAN", 0 ) != -1 )
					{
						strLINE.Replace( "LANG_KOREAN", vNATION[ nNation][0] );
						bChangedLocal = TRUE;
					}
				}

				if( !bChangedCodePage )
				{
					if( strLINE.Find( "code_page(949)", 0 ) != -1 )
					{
						strLINE.Replace( "code_page(949)", vNATION[ nNation][ 1 ] );
						bChangedCodePage = TRUE;
					}
				}

				vDEST.WriteString( strLINE);
				vDEST.WriteString( "\n");
			}

			vDEST.WriteString( "\n#endif" );

			vSRC.Close();
			vDEST.Close();
		}
		else
			return FALSE;
	}

	return TRUE;
}