
// startExeDlg.h : ͷ�ļ�
//

#pragma once
#include<vector>
#include "afxwin.h"
typedef  std::vector<CString>  MYVECTOR;

// CstartExeDlg �Ի���
class CstartExeDlg : public CDialogEx
{
// ����
public:
	CstartExeDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STARTEXE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
public:



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
	BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonStart();
	CEdit m_eidt_input;
	CEdit m_edit_show;
};