// TMonSpawnInspector.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
#error PCH���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����Ͻʽÿ�.
#endif

#include "resource.h"		// �� ��ȣ

class CTMonSpawnInspectorApp : public CWinApp
{
public:
	CTMonSpawnInspectorApp();

	// ������
public:
	virtual BOOL InitInstance();

	// ����

	DECLARE_MESSAGE_MAP()
};

extern CTMonSpawnInspectorApp theApp;
