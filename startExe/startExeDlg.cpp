
// startExeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "startExe.h"
#include "startExeDlg.h"
#include "afxdialogex.h"
#include "verity/MyVerify.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CstartExeDlg �Ի���



CstartExeDlg::CstartExeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_STARTEXE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CstartExeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_INPUT, m_eidt_input);
	DDX_Control(pDX, IDC_EDIT_SHOW, m_edit_show);
}

BEGIN_MESSAGE_MAP(CstartExeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_START, &CstartExeDlg::OnBnClickedButtonStart)
END_MESSAGE_MAP()


// CstartExeDlg ��Ϣ�������

BOOL CstartExeDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��


	m_edit_show.SetWindowText(MyVerify::GetInstance()->ReturnPcMac());

	


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CstartExeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CstartExeDlg::OnPaint()
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
HCURSOR CstartExeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CstartExeDlg::OnBnClickedButtonStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strInput;
	m_eidt_input.GetWindowText(strInput);
	strInput.Trim();
	if (strInput.IsEmpty())
	{
		MessageBox(_T("������ע����!"));
		return;
	}
	//
	if (MyVerify::GetInstance()->WriteAndVerityExe(strInput))
	{
		//У��ɹ� ��������
		if (MyVerify::GetInstance()->VerityExe())
		{
			TCHAR bufPath[MAX_PATH] = { 0 };
			GetModuleFileName(NULL, bufPath, MAX_PATH);

			//1. �鿴��Ȩ�ļ��Ƿ����
			CString strFile = bufPath;
			int index = strFile.ReverseFind('\\');
			strFile = strFile.Left(index + 1) + _T("startExe.dll");
			PROCESS_INFORMATION pi;
			STARTUPINFO si;
			memset(&si, 0, sizeof(si));
			si.cb = sizeof(si);
			si.wShowWindow = SW_SHOW;
			si.dwFlags = 0;
			BOOL fRet = CreateProcess(strFile, NULL, NULL, FALSE, NULL, NULL, NULL, NULL, &si, &pi);

			//exit(0);
			CDialog::OnOK();
		}
	}
	else
		MessageBox(_T("��������ȷ��ע����!"));
	
}


BOOL CstartExeDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE) return TRUE;
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		OnBnClickedButtonStart();
		return TRUE;
	}
	else
		return CDialog::PreTranslateMessage(pMsg);
}
