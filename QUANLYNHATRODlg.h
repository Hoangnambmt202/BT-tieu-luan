
// QUANLYNHATRODlg.h : header file
//

#pragma once


// CQUANLYNHATRODlg dialog
class CQUANLYNHATRODlg : public CDialogEx
{
// Construction
public:
	CQUANLYNHATRODlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QUANLYNHATRO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
		CEdit edit_ten;
	CEdit edit_namsinh;
	CEdit edit_sdt;
	CEdit edit_vaophong;
	CListCtrl list_danhsach;
public:
	afx_msg void OnBnClickedBtnThem();
	afx_msg void OnStnClickedPictureMap();
};
