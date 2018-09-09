// MajorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "student_info.h"
#include "MajorDlg.h"
#include "afxdialogex.h"

// CMajorDlg �Ի���

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


// CMajorDlg ��Ϣ�������
int nCollege;
int nMajor;

BOOL CMajorDlg::OnInitDialog()
{
  CDialogEx::OnInitDialog();

  // TODO:  �ڴ���Ӷ���ĳ�ʼ��
  m_ComboCollege.AddString(_T("�ѧԺ"));
  m_ComboCollege.AddString(_T("����ѧԺ"));

  return TRUE;  // return TRUE unless you set the focus to a control
  // �쳣: OCX ����ҳӦ���� FALSE
}


void CMajorDlg::OnCbnSelchangeComboCollege()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
  nCollege = m_ComboCollege.GetCurSel();
  if (0 == nCollege)
  {
    m_ListMajor.ResetContent(); //reset the list

    m_ListMajor.AddString(_T("��׿"));
    m_ListMajor.AddString(_T("�ɶ�"));
    m_ListMajor.AddString(_T("̽��"));    
  }
  else if (1 == nCollege)
  {
    m_ListMajor.ResetContent();

    m_ListMajor.AddString(_T("��ը"));
    m_ListMajor.AddString(_T("����һ�廯"));
  }
  else
  {

  }
}


void CMajorDlg::OnBnClickedOk()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
  CDialogEx::OnOK();
  //exchange the college and major information with main dialog by nCollege and nMajor(extern)
  nCollege = m_ComboCollege.GetCurSel();
  nMajor   = m_ListMajor.GetCurSel();
}
