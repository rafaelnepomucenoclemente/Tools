// TRCImporter.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error PCH���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����Ͻʽÿ�.
#endif

#include "resource.h"		// �� ��ȣ


// CTRCImporterApp:
// �� Ŭ������ ������ ���ؼ��� TRCImporter.cpp�� �����Ͻʽÿ�.
//

class CTRCImporterApp : public CWinApp
{
public:
	CTRCImporterApp();

// ������
	public:
	virtual BOOL InitInstance();

// ����

	DECLARE_MESSAGE_MAP()
};

extern CTRCImporterApp theApp;
