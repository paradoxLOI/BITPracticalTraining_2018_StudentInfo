#pragma once
#include "afxwin.h"


// CMajorDlg �Ի���

class CMajorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMajorDlg)

public:
	CMajorDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMajorDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_Major };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
  CComboBox m_ComboCollege;
  virtual BOOL OnInitDialog();
  afx_msg void OnCbnSelchangeComboCollege();
  CListBox m_ListMajor;
  afx_msg void OnBnClickedOk();
};

extern int nCollege;
extern int nMajor;