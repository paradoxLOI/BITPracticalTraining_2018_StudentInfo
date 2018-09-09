
// student_infoDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "MajorDlg.h"


// Cstudent_infoDlg 对话框
class Cstudent_infoDlg : public CDialogEx
{
// 构造
public:
	Cstudent_infoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_STUDENT_INFO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnBnClickedButtonOk();
  afx_msg void OnBnClickedRadioMan();
  afx_msg void OnBnClickedRadioWoman();
  CComboBox m_ComboDataYear;
  CComboBox m_ComboDataMonth;
  CComboBox m_ComboDataDay;
  afx_msg void OnBnClickedButtonChoosemajor();
  afx_msg void OnBnClickedButtonChoosephoto();
  afx_msg void OnCbnSelchangeComboDatayear();
  afx_msg void OnCbnSelchangeComboDatamonth();
  afx_msg void OnBnClickedButtonReset();
  CEdit m_EditMajor;
  CEdit m_EditName;
  CEdit m_EditID;
  bool EmptyInfoCheck();  //check the student information is empty or not
};