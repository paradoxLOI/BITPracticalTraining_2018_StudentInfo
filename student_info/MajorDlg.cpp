// MajorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "student_info.h"
#include "MajorDlg.h"
#include "afxdialogex.h"

// CMajorDlg 对话框

IMPLEMENT_DYNAMIC(CMajorDlg, CDialogEx)

CMajorDlg::CMajorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMajorDlg::IDD, pParent)
{
}

CMajorDlg::~CMajorDlg()
{
}

void CMajorDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_COMBO_College, m_ComboCollege);
  DDX_Control(pDX, IDC_LIST_Major, m_ListMajor);
}


BEGIN_MESSAGE_MAP(CMajorDlg, CDialogEx)
  ON_CBN_SELCHANGE(IDC_COMBO_College, &CMajorDlg::OnCbnSelchangeComboCollege)
  ON_BN_CLICKED(IDOK, &CMajorDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMajorDlg 消息处理程序
int nCollege;
int nMajor;

BOOL CMajorDlg::OnInitDialog()
{
  CDialogEx::OnInitDialog();

  // TODO:  在此添加额外的初始化
  m_ComboCollege.AddString(_T("宇航学院"));
  m_ComboCollege.AddString(_T("机电学院"));

  return TRUE;  // return TRUE unless you set the focus to a control
  // 异常: OCX 属性页应返回 FALSE
}


void CMajorDlg::OnCbnSelchangeComboCollege()
{
  // TODO: 在此添加控件通知处理程序代码
  nCollege = m_ComboCollege.GetCurSel();
  if (0 == nCollege)
  {
    m_ListMajor.ResetContent(); //reset the list

    m_ListMajor.AddString(_T("飞卓"));
    m_ListMajor.AddString(_T("飞动"));
    m_ListMajor.AddString(_T("探测"));    
  }
  else if (1 == nCollege)
  {
    m_ListMajor.ResetContent();

    m_ListMajor.AddString(_T("爆炸"));
    m_ListMajor.AddString(_T("机电一体化"));
  }
  else
  {

  }
}


void CMajorDlg::OnBnClickedOk()
{
  // TODO: 在此添加控件通知处理程序代码
  CDialogEx::OnOK();
  //exchange the college and major information with main dialog by nCollege and nMajor(extern)
  nCollege = m_ComboCollege.GetCurSel();
  nMajor   = m_ListMajor.GetCurSel();
}
