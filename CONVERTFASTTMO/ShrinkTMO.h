// ShrinkTMO.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error PCH���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����Ͻʽÿ�.
#endif

#include "resource.h"		// �� ��ȣ


// CShrinkTMOApp:
// �� Ŭ������ ������ ���ؼ��� ShrinkTMO.cpp�� �����Ͻʽÿ�.
//

class CShrinkTMOApp : public CWinApp
{
public:
	CShrinkTMOApp();

// ������
	public:
	virtual void LoadStdProfileSettings();
	virtual void SaveStdProfileSettings();
	virtual BOOL InitInstance();

// ����

	DECLARE_MESSAGE_MAP()
};

extern CShrinkTMOApp theApp;
