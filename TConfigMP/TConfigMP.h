// TConfigMP.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error PCH���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����Ͻʽÿ�.
#endif

#include "resource.h"		// �� ��ȣ


// CTConfigMPApp:
// �� Ŭ������ ������ ���ؼ��� TConfigMP.cpp�� �����Ͻʽÿ�.
//

class CTConfigMPApp : public CWinApp
{
public:
	CTConfigMPApp();

// Overrides
	public:
	virtual void LoadStdProfileSettings();
	virtual void SaveStdProfileSettings();

	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTConfigMPApp theApp;
