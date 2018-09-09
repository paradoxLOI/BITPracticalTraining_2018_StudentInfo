
// student_infoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "student_info.h"
#include "student_infoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cstudent_infoDlg �Ի���




Cstudent_infoDlg::Cstudent_infoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cstudent_infoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cstudent_infoDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_COMBO_DataYear, m_ComboDataYear);
  DDX_Control(pDX, IDC_COMBO_DataMonth, m_ComboDataMonth);
  DDX_Control(pDX, IDC_COMBO_DataDay, m_ComboDataDay);
  DDX_Control(pDX, IDC_EDIT_Major, m_EditMajor);
  DDX_Control(pDX, IDC_EDIT_Name, m_EditName);
  DDX_Control(pDX, IDC_EDIT_StudentID, m_EditID);
}

BEGIN_MESSAGE_MAP(Cstudent_infoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
  ON_BN_CLICKED(IDC_BUTTON_Ok, &Cstudent_infoDlg::OnBnClickedButtonOk)
  ON_BN_CLICKED(IDC_RADIO_Man, &Cstudent_infoDlg::OnBnClickedRadioMan)
  ON_BN_CLICKED(IDC_RADIO_Woman, &Cstudent_infoDlg::OnBnClickedRadioWoman)
  ON_BN_CLICKED(IDC_BUTTON_ChooseMajor, &Cstudent_infoDlg::OnBnClickedButtonChoosemajor)
  ON_BN_CLICKED(IDC_BUTTON_ChoosePhoto, &Cstudent_infoDlg::OnBnClickedButtonChoosephoto)
  ON_CBN_SELCHANGE(IDC_COMBO_DataYear, &Cstudent_infoDlg::OnCbnSelchangeComboDatayear)
  ON_CBN_SELCHANGE(IDC_COMBO_DataMonth, &Cstudent_infoDlg::OnCbnSelchangeComboDatamonth)
  ON_BN_CLICKED(IDC_BUTTON_Reset, &Cstudent_infoDlg::OnBnClickedButtonReset)
END_MESSAGE_MAP()


// Cstudent_infoDlg ��Ϣ�������

BOOL Cstudent_infoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
  //Birth day list init
  CString csDataYear, csDataMonth, csDataDay;
  for (int iYear = 2018; iYear >= 1900; iYear--)
  {
    csDataYear.Format(_T("%d"), iYear);
    m_ComboDataYear.AddString(_T(csDataYear));
  }
  for (int iMonth = 1; iMonth <= 12; iMonth++)
  {
    csDataMonth.Format(_T("%d"), iMonth);
    m_ComboDataMonth.AddString(_T(csDataMonth));
  }
  for (int iDay = 1; iDay <= 31; iDay++)
  {
    csDataDay.Format(_T("%d"), iDay);
    m_ComboDataDay.AddString(_T(csDataDay));
  }
  //disable the month and day before year has been choosed
  m_ComboDataMonth.EnableWindow(FALSE);
  m_ComboDataDay.EnableWindow(FALSE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

CString csCollege, csMajor;

void Cstudent_infoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cstudent_infoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cstudent_infoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CString csName, csStudentID, csYear, csMonth, csDay;
int nGender = 0;  //1 for man and 2 for woman

void Cstudent_infoDlg::OnBnClickedButtonOk()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
  int     nYear, nMonth, nDay;
  
  GetDlgItemText(IDC_EDIT_Name,      csName);
  GetDlgItemText(IDC_EDIT_StudentID, csStudentID);
  
  nYear  = 2018 - m_ComboDataYear.GetCurSel(); //count from 2018 to 1900
  nMonth = m_ComboDataMonth.GetCurSel() + 1;
  nDay   = m_ComboDataDay.GetCurSel()   + 1;
  csYear.Format(_T("%d"),    nYear);
  csMonth.Format(_T("%02d"), nMonth);
  csDay.Format(_T("%02d"),   nDay);

  if (EmptyInfoCheck())
  {
    MessageBox(_T("��Ϣ����Ϊ��Ŷ��=��=��=(~������)~"), _T("����"), MB_OK | MB_ICONWARNING);
    return;
  }

  TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|Word�ļ�(*.doc)|*.doc|�����ļ�(*.*)|*.*||");
  CFileDialog fileDlg(FALSE, _T("txt"), _T(csName + "��Ϣ"), OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, szFilter, this);
  CString csFilePath;
  // ��ʾ�����ļ��Ի���   
  if (IDOK == fileDlg.DoModal())
  {  
    csFilePath = fileDlg.GetPathName();
  }
  else
  {
    return;
  }

  //����ѧ����Ϣ�ļ�
  CStdioFile iofKeyFile;
  iofKeyFile.Open(_T(csFilePath), CFile::modeCreate | CFile::modeWrite);
  iofKeyFile.WriteString(_T("ѧ�������� " + csName      + "\n"));
  iofKeyFile.WriteString(_T("ѧ��ѧ�ţ� " + csStudentID + "\n"));
  if (1 == nGender)
  {
    iofKeyFile.WriteString(_T("ѧ���ձ� ��\n"));
  }
  else if (2 == nGender)
  {
    iofKeyFile.WriteString(_T("ѧ���ձ� Ů\n"));
  }
  else
  {
    iofKeyFile.WriteString(_T("ѧ���ձ� δ֪\n"));
  }
  iofKeyFile.WriteString(_T("ѧ�����գ� " + csYear + "��" + csMonth + "��" + csDay + "��\n"));
  iofKeyFile.WriteString(_T("ѧ��רҵ�� " + csCollege + "-" + csMajor + "\n"));  
  iofKeyFile.Close();

  MessageBox(_T("ѧ����Ϣ����ɹ�: " + csFilePath), _T("����"), MB_OK);
}


void Cstudent_infoDlg::OnBnClickedRadioMan()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
  nGender = 1;
}


void Cstudent_infoDlg::OnBnClickedRadioWoman()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
  nGender = 2;
}


void Cstudent_infoDlg::OnBnClickedButtonChoosemajor()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
  INT_PTR nRes;             
  CMajorDlg majorDlg;           
  nRes = majorDlg.DoModal();  //show the choose major dialog
  if (IDCANCEL == nRes)     
    return;              
  UpdateData(TRUE);

  //exchange the college and major information with choose major dialog by nCollege and nMajor(extern)
  switch (nMajor)
  {
    case 0:
    {
      if (0 == nCollege)
      {
        csCollege.Format(_T("�ѧԺ"));
        csMajor.Format(_T("��׿"));
      }
      else
      {
        csCollege.Format(_T("����ѧԺ"));
        csMajor.Format(_T("��ը"));
      }
      break;
    }
    case 1:
    {
      if (0 == nCollege)
      {
        csCollege.Format(_T("�ѧԺ"));
        csMajor.Format(_T("�ɶ�"));
      }
      else
      {
        csCollege.Format(_T("����ѧԺ"));
        csMajor.Format(_T("����һ�廯"));
      }
      break;
    }
    case 2:
    {
      if (0 == nCollege)
      {
        csCollege.Format(_T("�ѧԺ"));
        csMajor.Format(_T("̽��"));
      }
      break;
    }
  }
  SetDlgItemText(IDC_EDIT_Major, csCollege + "-" + csMajor);
}


void Cstudent_infoDlg::OnBnClickedButtonChoosephoto()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
  //���ļ� �������ָ�ʽ���ļ�bmp gif jpg tiff
  CString filter;
  filter = "�����ļ�(*.bmp,*.jpg,*.gif,*tiff)|*.bmp;*.jpg;*.gif;*.tiff| BMP(*.bmp)|*.bmp| JPG(*.jpg)|*.jpg| GIF(*.gif)|*.gif| TIFF(*.tiff)|*.tiff||";
  CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, filter, NULL);

  //����ȷ����ť dlg.DoModal() ������ʾ�Ի���
  if (dlg.DoModal() == IDOK)
  {
    //�򿪶Ի����ȡͼ����Ϣ
    CString BmpName = dlg.GetPathName();     //��ȡ�ļ�·����   ��D:\pic\abc.bmp
    CString EntName = dlg.GetFileExt();      //��ȡ�ļ���չ��
    EntName.MakeLower();                     //���ļ���չ��ת��Ϊһ��Сд�ַ�

    if (EntName.Compare(_T("bmp")) == 0)
    {
      //��������洢ͼƬ��Ϣ
      BITMAPINFO *pBmpInfo;       //��¼ͼ��ϸ��
      BYTE *pBmpData;             //ͼ������
      BITMAPFILEHEADER bmpHeader; //�ļ�ͷ
      BITMAPINFOHEADER bmpInfo;   //��Ϣͷ
      CFile bmpFile;              //��¼���ļ�

      //��ֻ���ķ�ʽ���ļ� ��ȡbmpͼƬ������ bmp�ļ�ͷ ��Ϣ ����
      if (!bmpFile.Open(BmpName, CFile::modeRead | CFile::typeBinary))
        return;
      if (bmpFile.Read(&bmpHeader, sizeof(BITMAPFILEHEADER)) != sizeof(BITMAPFILEHEADER))
        return;
      if (bmpFile.Read(&bmpInfo, sizeof(BITMAPINFOHEADER)) != sizeof(BITMAPINFOHEADER))
        return;
      pBmpInfo = (BITMAPINFO *)new char[sizeof(BITMAPINFOHEADER)];
      //Ϊͼ����������ռ�
      memcpy(pBmpInfo, &bmpInfo, sizeof(BITMAPINFOHEADER));
      DWORD dataBytes = bmpHeader.bfSize - bmpHeader.bfOffBits;
      pBmpData = (BYTE*)new char[dataBytes];
      bmpFile.Read(pBmpData, dataBytes);
      bmpFile.Close();

      //��ʾͼ��
      CWnd *pWnd = GetDlgItem(IDC_STATIC_PIC); //���pictrue�ؼ����ڵľ��
      CRect rect;
      pWnd->GetClientRect(&rect); //���pictrue�ؼ����ڵľ�������
      CDC *pDC = pWnd->GetDC(); //���pictrue�ؼ���DC
      pDC->SetStretchBltMode(COLORONCOLOR);
      StretchDIBits(pDC->GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0,
        bmpInfo.biWidth, bmpInfo.biHeight, pBmpData, pBmpInfo, DIB_RGB_COLORS, SRCCOPY);
    }
  }
}

void Cstudent_infoDlg::OnCbnSelchangeComboDatayear()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
  //if year date has been changeed enable the month data and reset all select
  m_ComboDataMonth.EnableWindow(TRUE);
  m_ComboDataMonth.SetCurSel(-1);
  m_ComboDataDay.SetCurSel(-1);
}


void Cstudent_infoDlg::OnCbnSelchangeComboDatamonth()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
  //if month date has been changeed enable the day data and reset day select
  m_ComboDataDay.EnableWindow(TRUE);
  m_ComboDataDay.SetCurSel(-1);

  int nYear  = 2018 - m_ComboDataYear.GetCurSel();
  int nMonth = m_ComboDataMonth.GetCurSel() + 1;
  
  //adjust day num by month
  if (4 == nMonth || 6 == nMonth || 9 == nMonth || 11 == nMonth)   //30 day
  {
    m_ComboDataDay.DeleteString(30);      //delete day 31
  }
  else if (2 == nMonth)
  {
    if (nYear % 4 == 0 && (nYear % 100 != 0 || nYear % 400 == 0)) //29 days
    {
        m_ComboDataDay.DeleteString(30);
        m_ComboDataDay.DeleteString(29);  //delete day 30
    }
    else                                                          //28 days
    {
      m_ComboDataDay.DeleteString(30);
      m_ComboDataDay.DeleteString(29);
      m_ComboDataDay.DeleteString(28);    //delete day 29
    }
  }
  else                                                            //31 days
  {
    if (28 == m_ComboDataDay.GetCount())
    {
      m_ComboDataDay.AddString(_T("29")); //add day 29
      m_ComboDataDay.AddString(_T("30")); //add day 30
      m_ComboDataDay.AddString(_T("31")); //add day 31
    }
    else if (29 == m_ComboDataDay.GetCount())
    {
      m_ComboDataDay.AddString(_T("30")); //add day 30
      m_ComboDataDay.AddString(_T("31")); //add day 31
    }
    else if (30 == m_ComboDataDay.GetCount())
    {
      m_ComboDataDay.AddString(_T("31")); //add day 31
    }
    else
    {
      
    }
  }
}


void Cstudent_infoDlg::OnBnClickedButtonReset()
{
  // TODO: �ڴ���ӿؼ�֪ͨ����������
  //reset all select
  SetDlgItemText(IDC_EDIT_Name,      NULL);
  SetDlgItemText(IDC_EDIT_StudentID, NULL);
  SetDlgItemText(IDC_EDIT_Major,     NULL);
  m_ComboDataYear.SetCurSel(-1);
  m_ComboDataMonth.SetCurSel(-1);
  m_ComboDataDay.SetCurSel(-1);
}

bool Cstudent_infoDlg::EmptyInfoCheck()
{
    if (csName.IsEmpty() || csStudentID.IsEmpty() || csYear.IsEmpty()    || csMonth.IsEmpty() || 
        csDay.IsEmpty()  || !nGender              || csCollege.IsEmpty() || csMajor.IsEmpty())
    {
      return true;
    }
    else
    {
      return false;
    }
}