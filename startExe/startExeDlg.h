
// startExeDlg.h : 头文件
//

#pragma once
#include<vector>
#include "afxwin.h"
typedef  std::vector<CString>  MYVECTOR;

// CstartExeDlg 对话框
class CstartExeDlg : public CDialogEx
{
// 构造
public:
	CstartExeDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STARTEXE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
public:



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
	BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonStart();
	CEdit m_eidt_input;
	CEdit m_edit_show;
};
