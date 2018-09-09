
// student_infoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "MajorDlg.h"


// Cstudent_infoDlg �Ի���
class Cstudent_infoDlg : public CDialogEx
{
// ����
public:
	Cstudent_infoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_STUDENT_INFO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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