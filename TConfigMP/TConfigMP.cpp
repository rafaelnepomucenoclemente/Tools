// TConfigMP.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "TConfigMP.h"
#include "TConfigMPDlg.h"
#include ".\tconfigmp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTConfigMPApp

BEGIN_MESSAGE_MAP(CTConfigMPApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CTConfigMPApp ����

CTConfigMPApp::CTConfigMPApp()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CTConfigMPApp ��ü�Դϴ�.

CTConfigMPApp theApp;


// CTConfigMPApp �ʱ�ȭ

BOOL CTConfigMPApp::InitInstance()
{
	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControls()�� �ʿ��մϴ�. 
	// InitCommonControls()�� ������� ������ â�� ���� �� �����ϴ�.
	InitCommonControls();

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ǥ�� �ʱ�ȭ
	// �̵� ����� ������� �ʰ� ���� ���� ������ ũ�⸦ ���̷���
	// �Ʒ����� �ʿ� ���� Ư�� �ʱ�ȭ ��ƾ�� �����ؾ� �մϴ�.
	// �ش� ������ ����� ������Ʈ�� Ű�� �����Ͻʽÿ�.
	// TODO: �� ���ڿ��� ȸ�� �Ǵ� ������ �̸��� ����
	// ������ �������� �����ؾ� �մϴ�.
	SetRegistryKey(_T("Tachyon Engine"));

	CTConfigMPDlg dlg;
	m_pMainWnd = &dlg;

	dlg.m_strMAINPEFOLDER.Empty();
	dlg.m_strDESTFOLDER.Empty();
	dlg.m_strSRCFOLDER.Empty();
	LoadStdProfileSettings();

	INT_PTR nResponse = dlg.DoModal();
	m_pMainWnd = &dlg;
	SaveStdProfileSettings();
	m_pMainWnd = NULL;

	if (nResponse == IDOK)
	{
		// TODO: ���⿡ ��ȭ ���ڰ� Ȯ���� ���� �������� ��� ó����
		// �ڵ带 ��ġ�մϴ�.
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ���⿡ ��ȭ ���ڰ� ��Ҹ� ���� �������� ��� ó����
		// �ڵ带 ��ġ�մϴ�.
	}

	// ��ȭ ���ڰ� �������Ƿ� ���� ���α׷��� �޽��� ������ �������� �ʰ�
	// ���� ���α׷��� ���� �� �ֵ��� FALSE�� ��ȯ�մϴ�.
	return FALSE;
}

int CTConfigMPApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}

void CTConfigMPApp::LoadStdProfileSettings()
{
	CWinApp::LoadStdProfileSettings();

	((CTConfigMPDlg *) m_pMainWnd)->m_strMAINPEFOLDER = GetProfileString(
		_T("Config"),
		_T("MAINPE Folder"),
		_T(""));

	((CTConfigMPDlg *) m_pMainWnd)->m_strDESTFOLDER = GetProfileString(
		_T("Config"),
		_T("DEST Folder"),
		_T(""));

	((CTConfigMPDlg *) m_pMainWnd)->m_strSRCFOLDER = GetProfileString(
		_T("Config"),
		_T("SRC Folder"),
		_T(""));
}

void CTConfigMPApp::SaveStdProfileSettings()
{
	CWinApp::SaveStdProfileSettings();

	WriteProfileString(
		_T("Config"),
		_T("MAINPE Folder"),
		LPCSTR(((CTConfigMPDlg *) m_pMainWnd)->m_strMAINPEFOLDER));

	WriteProfileString(
		_T("Config"),
		_T("DEST Folder"),
		LPCSTR(((CTConfigMPDlg *) m_pMainWnd)->m_strDESTFOLDER));

	WriteProfileString(
		_T("Config"),
		_T("SRC Folder"),
		LPCSTR(((CTConfigMPDlg *) m_pMainWnd)->m_strSRCFOLDER));
}
