
// student_info.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cstudent_infoApp:
// �йش����ʵ�֣������ student_info.cpp
//

class Cstudent_infoApp : public CWinApp
{
public:
	Cstudent_infoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cstudent_infoApp theApp;