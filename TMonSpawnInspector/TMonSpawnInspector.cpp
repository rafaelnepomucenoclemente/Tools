// TMonSpawnInspector.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "TMonSpawnInspector.h"
#include "TMonSpawnInspectorMAP.h"
#include "TMonSpawnInspectorObjBase.h"
#include "TMonSpawnInspectorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTMonSpawnInspectorApp

BEGIN_MESSAGE_MAP(CTMonSpawnInspectorApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CTMonSpawnInspectorApp ����

CTMonSpawnInspectorApp::CTMonSpawnInspectorApp()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CTMonSpawnInspectorApp ��ü�Դϴ�.

CTMonSpawnInspectorApp theApp;


// CTMonSpawnInspectorApp �ʱ�ȭ

BOOL CTMonSpawnInspectorApp::InitInstance()
{
	CWinApp::InitInstance();

	SetRegistryKey(_T("TMonSpawnInspector"));

	m_pMainWnd = &GetMainDlg();

	INT_PTR nResponse = GetMainDlg().DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	return FALSE;
}
