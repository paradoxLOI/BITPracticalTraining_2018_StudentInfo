#pragma once
#include "afxwin.h"


// CMajorDlg 对话框

class CMajorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMajorDlg)

public:
	CMajorDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMajorDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_Major };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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