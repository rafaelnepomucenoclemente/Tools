// TQuestPath.h : TQuestPath ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error PCH���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����Ͻʽÿ�.
#endif

#include "resource.h"       // �� ��ȣ


// CTQuestPathApp:
// �� Ŭ������ ������ ���ؼ��� TQuestPath.cpp�� �����Ͻʽÿ�.
//

class CTQuestPathApp : public CWinApp
{
public:
	CTQuestPathApp();


// ������
public:
	virtual CDocument* OpenDocumentFile(LPCTSTR lpszFileName);
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTQuestPathApp theApp;
