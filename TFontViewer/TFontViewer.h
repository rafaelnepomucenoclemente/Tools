// TFontViewer.h : TFontViewer ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error PCH���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����Ͻʽÿ�.
#endif

#include "resource.h"       // �� ��ȣ


// CTFontViewerApp:
// �� Ŭ������ ������ ���ؼ��� TFontViewer.cpp�� �����Ͻʽÿ�.
//

class CTFontViewerApp : public CWinApp
{
public:
	CTFontViewerApp();

	ULONG_PTR m_pGDI;

// ������
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnIdle(LONG lCount);
	virtual int ExitInstance();
};

extern CTFontViewerApp theApp;
