// TBuilder.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error PCH���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����Ͻʽÿ�.
#endif

#include "resource.h"		// �� ��ȣ


// CTBuilderApp:
// �� Ŭ������ ������ ���ؼ��� TBuilder.cpp�� �����Ͻʽÿ�.
//

class CTBuilderApp : public CWinApp
{
public:
	CTBuilderApp();

// ������
	public:
	virtual void LoadStdProfileSettings();
	virtual void SaveStdProfileSettings();

	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����

	DECLARE_MESSAGE_MAP()
};

extern CTBuilderApp theApp;
