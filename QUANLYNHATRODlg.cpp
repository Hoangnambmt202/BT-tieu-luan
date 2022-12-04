
// QUANLYNHATRODlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "QUANLYNHATRO.h"
#include "QUANLYNHATRODlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CQUANLYNHATRODlg dialog



CQUANLYNHATRODlg::CQUANLYNHATRODlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_QUANLYNHATRO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CQUANLYNHATRODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_TEN, edit_ten);
	DDX_Control(pDX, IDC_EDIT_NAMSINH, edit_namsinh);
	DDX_Control(pDX, IDC_EDIT_SDT, edit_sdt);
	DDX_Control(pDX, IDC_EDIT_VAOPHONG, edit_vaophong);
	DDX_Control(pDX, IDC_LIST_DANHSACH, list_danhsach);
}

BEGIN_MESSAGE_MAP(CQUANLYNHATRODlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_THEM, &CQUANLYNHATRODlg::OnBnClickedBtnThem)
	ON_STN_CLICKED(IDC_PICTURE_MAP, &CQUANLYNHATRODlg::OnStnClickedPictureMap)
END_MESSAGE_MAP()


// CQUANLYNHATRODlg message handlers

BOOL CQUANLYNHATRODlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	list_danhsach.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	list_danhsach.InsertColumn(0, _T("Ten"), LVCFMT_LEFT, 100);
	list_danhsach.InsertColumn(1, _T("Nam sinh"), LVCFMT_LEFT, 80 );
	list_danhsach.InsertColumn(2, _T("SDT"), LVCFMT_LEFT, 100);
	list_danhsach.InsertColumn(3, _T("So phong"), LVCFMT_LEFT, 80);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CQUANLYNHATRODlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CQUANLYNHATRODlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CQUANLYNHATRODlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CQUANLYNHATRODlg::OnBnClickedBtnThem()
{
	UpdateData(TRUE);
	CString str_ten;
	edit_ten.GetWindowText(str_ten);

	CString str_namsinh;
	edit_namsinh.GetWindowText(str_namsinh);

	CString	str_sdt;
	edit_sdt.GetWindowText(str_sdt);

	CString str_vaophong;
	edit_vaophong.GetWindowText(str_vaophong);

	list_danhsach.InsertItem(0, str_ten);
	list_danhsach.SetItemText(0, 1, str_namsinh);
	list_danhsach.SetItemText(0, 2, str_sdt);
	list_danhsach.SetItemText(0, 3,str_vaophong );
	

	UpdateData(FALSE);
}


void CQUANLYNHATRODlg::OnStnClickedPictureMap()
{
	// TODO: Add your control notification handler code here
}
