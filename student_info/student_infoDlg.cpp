
// student_infoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "student_info.h"
#include "student_infoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// Cstudent_infoDlg 对话框




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


// Cstudent_infoDlg 消息处理程序

BOOL Cstudent_infoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cstudent_infoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cstudent_infoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CString csName, csStudentID, csYear, csMonth, csDay;
int nGender = 0;  //1 for man and 2 for woman

void Cstudent_infoDlg::OnBnClickedButtonOk()
{
  // TODO: 在此添加控件通知处理程序代码
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
    MessageBox(_T("信息不能为空哦ε=ε=ε=(~￣▽￣)~"), _T("叮！"), MB_OK | MB_ICONWARNING);
    return;
  }

  TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|Word文件(*.doc)|*.doc|所有文件(*.*)|*.*||");
  CFileDialog fileDlg(FALSE, _T("txt"), _T(csName + "信息"), OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, szFilter, this);
  CString csFilePath;
  // 显示保存文件对话框   
  if (IDOK == fileDlg.DoModal())
  {  
    csFilePath = fileDlg.GetPathName();
  }
  else
  {
    return;
  }

  //保存学生信息文件
  CStdioFile iofKeyFile;
  iofKeyFile.Open(_T(csFilePath), CFile::modeCreate | CFile::modeWrite);
  iofKeyFile.WriteString(_T("学生姓名： " + csName      + "\n"));
  iofKeyFile.WriteString(_T("学生学号： " + csStudentID + "\n"));
  if (1 == nGender)
  {
    iofKeyFile.WriteString(_T("学生姓别： 男\n"));
  }
  else if (2 == nGender)
  {
    iofKeyFile.WriteString(_T("学生姓别： 女\n"));
  }
  else
  {
    iofKeyFile.WriteString(_T("学生姓别： 未知\n"));
  }
  iofKeyFile.WriteString(_T("学生生日： " + csYear + "年" + csMonth + "月" + csDay + "日\n"));
  iofKeyFile.WriteString(_T("学生专业： " + csCollege + "-" + csMajor + "\n"));  
  iofKeyFile.Close();

  MessageBox(_T("学生信息保存成功: " + csFilePath), _T("叮！"), MB_OK);
}


void Cstudent_infoDlg::OnBnClickedRadioMan()
{
  // TODO: 在此添加控件通知处理程序代码
  nGender = 1;
}


void Cstudent_infoDlg::OnBnClickedRadioWoman()
{
  // TODO: 在此添加控件通知处理程序代码
  nGender = 2;
}


void Cstudent_infoDlg::OnBnClickedButtonChoosemajor()
{
  // TODO: 在此添加控件通知处理程序代码
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
        csCollege.Format(_T("宇航学院"));
        csMajor.Format(_T("飞卓"));
      }
      else
      {
        csCollege.Format(_T("机电学院"));
        csMajor.Format(_T("爆炸"));
      }
      break;
    }
    case 1:
    {
      if (0 == nCollege)
      {
        csCollege.Format(_T("宇航学院"));
        csMajor.Format(_T("飞动"));
      }
      else
      {
        csCollege.Format(_T("机电学院"));
        csMajor.Format(_T("机电一体化"));
      }
      break;
    }
    case 2:
    {
      if (0 == nCollege)
      {
        csCollege.Format(_T("宇航学院"));
        csMajor.Format(_T("探测"));
      }
      break;
    }
  }
  SetDlgItemText(IDC_EDIT_Major, csCollege + "-" + csMajor);
}


void Cstudent_infoDlg::OnBnClickedButtonChoosephoto()
{
  // TODO: 在此添加控件通知处理程序代码
  //打开文件 定义四种格式的文件bmp gif jpg tiff
  CString filter;
  filter = "所有文件(*.bmp,*.jpg,*.gif,*tiff)|*.bmp;*.jpg;*.gif;*.tiff| BMP(*.bmp)|*.bmp| JPG(*.jpg)|*.jpg| GIF(*.gif)|*.gif| TIFF(*.tiff)|*.tiff||";
  CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, filter, NULL);

  //按下确定按钮 dlg.DoModal() 函数显示对话框
  if (dlg.DoModal() == IDOK)
  {
    //打开对话框获取图像信息
    CString BmpName = dlg.GetPathName();     //获取文件路径名   如D:\pic\abc.bmp
    CString EntName = dlg.GetFileExt();      //获取文件扩展名
    EntName.MakeLower();                     //将文件扩展名转换为一个小写字符

    if (EntName.Compare(_T("bmp")) == 0)
    {
      //定义变量存储图片信息
      BITMAPINFO *pBmpInfo;       //记录图像细节
      BYTE *pBmpData;             //图像数据
      BITMAPFILEHEADER bmpHeader; //文件头
      BITMAPINFOHEADER bmpInfo;   //信息头
      CFile bmpFile;              //记录打开文件

      //以只读的方式打开文件 读取bmp图片各部分 bmp文件头 信息 数据
      if (!bmpFile.Open(BmpName, CFile::modeRead | CFile::typeBinary))
        return;
      if (bmpFile.Read(&bmpHeader, sizeof(BITMAPFILEHEADER)) != sizeof(BITMAPFILEHEADER))
        return;
      if (bmpFile.Read(&bmpInfo, sizeof(BITMAPINFOHEADER)) != sizeof(BITMAPINFOHEADER))
        return;
      pBmpInfo = (BITMAPINFO *)new char[sizeof(BITMAPINFOHEADER)];
      //为图像数据申请空间
      memcpy(pBmpInfo, &bmpInfo, sizeof(BITMAPINFOHEADER));
      DWORD dataBytes = bmpHeader.bfSize - bmpHeader.bfOffBits;
      pBmpData = (BYTE*)new char[dataBytes];
      bmpFile.Read(pBmpData, dataBytes);
      bmpFile.Close();

      //显示图像
      CWnd *pWnd = GetDlgItem(IDC_STATIC_PIC); //获得pictrue控件窗口的句柄
      CRect rect;
      pWnd->GetClientRect(&rect); //获得pictrue控件所在的矩形区域
      CDC *pDC = pWnd->GetDC(); //获得pictrue控件的DC
      pDC->SetStretchBltMode(COLORONCOLOR);
      StretchDIBits(pDC->GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0,
        bmpInfo.biWidth, bmpInfo.biHeight, pBmpData, pBmpInfo, DIB_RGB_COLORS, SRCCOPY);
    }
  }
}

void Cstudent_infoDlg::OnCbnSelchangeComboDatayear()
{
  // TODO: 在此添加控件通知处理程序代码
  //if year date has been changeed enable the month data and reset all select
  m_ComboDataMonth.EnableWindow(TRUE);
  m_ComboDataMonth.SetCurSel(-1);
  m_ComboDataDay.SetCurSel(-1);
}


void Cstudent_infoDlg::OnCbnSelchangeComboDatamonth()
{
  // TODO: 在此添加控件通知处理程序代码
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
  // TODO: 在此添加控件通知处理程序代码
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