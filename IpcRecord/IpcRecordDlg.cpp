
// IpcRecordDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "IpcRecord.h"
#include "IpcRecordDlg.h"
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


// CIpcRecordDlg 对话框

CIpcRecordDlg *g_this = NULL;	//当前对话框指针

CIpcRecordDlg::CIpcRecordDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CIpcRecordDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	//初始化
	m_UserID = 0; 
	m_Port = -1;
	m_VideoHandle = 0;
	g_this = this;
}

void CIpcRecordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_DEVICE, m_DeviceTree);
}

BEGIN_MESSAGE_MAP(CIpcRecordDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SEARCH, &CIpcRecordDlg::OnBnClickedBtnSearch)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_DEVICE, &CIpcRecordDlg::OnDblclkTreeDevice)
	ON_BN_CLICKED(IDC_BTN_RECORD, &CIpcRecordDlg::OnBnClickedBtnRecord)
END_MESSAGE_MAP()


// CIpcRecordDlg 消息处理程序

BOOL CIpcRecordDlg::OnInitDialog()
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

	//初始化
	IPAC_DEV_Init();
	IPAC_PLAYER_Init();
	IPAC_PLAYER_DisPlayerMode(FALSE);

	OnBnClickedBtnSearch();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CIpcRecordDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CIpcRecordDlg::OnPaint()
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
HCURSOR CIpcRecordDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//搜索IP
void CIpcRecordDlg::OnBnClickedBtnSearch()
{
	m_DeviceTree.DeleteAllItems();
	HTREEITEM item  = m_DeviceTree.InsertItem("设备列表",TVI_ROOT,TVI_LAST);
	IPAC_DEV_SearchDevice(SearchCallback,this,0);
}

//搜索回调
int WINAPI CIpcRecordDlg::SearchCallback(IPAC_DEV_SEARCH* pSearchData, void *pParam)
{
	HTREEITEM root = g_this->m_DeviceTree.GetRootItem();

	in_addr addr;
	addr.S_un.S_addr = pSearchData->IP;
	g_this->m_DeviceTree.InsertItem(inet_ntoa(addr),root,TVI_LAST);

	g_this->m_DeviceTree.Expand(g_this->m_DeviceTree.GetRootItem(),TVE_EXPAND);

	return 0;
}

//双击树事件
void CIpcRecordDlg::OnDblclkTreeDevice(NMHDR *pNMHDR, LRESULT *pResult)
{
	HTREEITEM item = m_DeviceTree.GetSelectedItem();
	CString ip = m_DeviceTree.GetItemText(item);
	OpenDevice(ip.GetBuffer(ip.GetLength()),8100,TRUE);

	*pResult = 0;
}

//打开设备
int CIpcRecordDlg::OpenDevice(CString ip, int port,BOOL showMsg)
{
	if (ip == "" || ip == "设备列表" ){
		return -1;
	}

	if (m_UserID && m_VideoHandle)
	{
		CloseChannel();
	}

	m_UserID = IPAC_DEV_Login(ip, port,"admin","admin",TRUE);
	if (m_UserID <=0)
	{
		if (showMsg)
		{
			MessageBox("登录失败");
		}		
		return -1;
	}

	if (m_Port==-1)
	{
		m_Port = IPAC_PLAYER_GetPort(m_Port, GetDlgItem(IDC_STATIC_VIDEO)->m_hWnd);
		IPAC_PLAYER_Play(m_Port);
	}

	IPAC_DEV_CLIENTINFO struPlayInfo;
	struPlayInfo.hPlayWnd = NULL;
	struPlayInfo.lChannel = 1;   
	struPlayInfo.lLinkMode = 0; //tcp  3; //rtsp
	struPlayInfo.nVideoPort = 8200;
	struPlayInfo.sMultiCastIP = NULL;

	BOOL bPreviewBlock = false; 
	m_VideoHandle = IPAC_DEV_RealPlay(m_UserID, &struPlayInfo, StreamCallback, (void*)0, bPreviewBlock);
	if (m_VideoHandle <= 0)
	{
		if (showMsg)
		{
			MessageBox("播放不成功");
		}		
	}else{
	
		GetDlgItem(IDC_BTN_RECORD)->EnableWindow(TRUE);
	}
	TRACE("打开通道, ip =%s \n",ip);

	return 0;
}

// 视频数据回调函数
BOOL CIpcRecordDlg::StreamCallback(LONG lRealHandle,DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser)
{
	int index = (int)pUser;

	if(dwDataType ==0x65)
	{
		pBuffer += 0xf;
		dwBufSize -= 0x0f;
	}

	IPAC_PLAYER_InputData(g_this->m_Port,(PBYTE)pBuffer,dwBufSize);

	return TRUE;
}

// 关闭通道
BOOL CIpcRecordDlg::CloseChannel()
{
	//断开通道
	if (m_VideoHandle>0)
	{
		IPAC_DEV_StopRealPlay(m_VideoHandle);
		m_VideoHandle = 0;	
		TRACE("断开视频通道\n");
	}		

	//登录注销
	if (m_UserID>0)
	{
		IPAC_DEV_Logout(m_UserID);
		m_UserID=0;
		TRACE("注销设备登录\n");
	}

	//释放播放器
	if (m_Port != -1)
	{
		IPAC_PLAYER_Stop(m_Port);
		IPAC_PLAYER_FreePort(m_Port);
		m_Port=-1;
		TRACE("释放播放器\n");
	}

	//刷新播放窗口
	GetDlgItem(IDC_STATIC_VIDEO)->Invalidate();
	GetDlgItem(IDC_STATIC_VIDEO)->UpdateData();
	return TRUE;
}

//关闭窗口
void CIpcRecordDlg::OnClose()
{
	if (MessageBox("确实要退出吗？", "提示", MB_OKCANCEL|MB_ICONWARNING) == IDOK)
	{
		CDialog::OnClose();
	}
}

// 窗体销毁
void CIpcRecordDlg::OnDestroy()
{
	 
		CDialog::OnDestroy();
		CloseChannel();
		IPAC_DEV_Cleanup();
}


// 录像事件
void CIpcRecordDlg::OnBnClickedBtnRecord()
{
	if (m_VideoHandle<=0){
		return;
	}

	CString text;
	GetDlgItemText(IDC_BTN_RECORD,text);
	if(text == "开始录像"){
		CTime pt = CTime::GetCurrentTime();
		CString szRecodeName;
		szRecodeName.Format("%04d%02d%02d_%02d%02d%02d.mp4",pt.GetYear(),pt.GetMonth(),pt.GetDay(),pt.GetHour(),pt.GetMinute(),pt.GetSecond());

		IPAC_DEV_StartRecord(m_VideoHandle,(PTSTR)(LPCTSTR)szRecodeName);

		text="停止录像";
		SetDlgItemText(IDC_BTN_RECORD,text);
	}else{
		IPAC_DEV_StopRecord(m_VideoHandle);

		text="开始录像";
		SetDlgItemText(IDC_BTN_RECORD,text);
	}
}
