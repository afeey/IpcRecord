
// IpcRecord.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CIpcRecordApp:
// �йش����ʵ�֣������ IpcRecord.cpp
//

class CIpcRecordApp : public CWinApp
{
public:
	CIpcRecordApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CIpcRecordApp theApp;