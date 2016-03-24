
// IpcRecordDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IpcRecord.h"
#include "IpcRecordDlg.h"
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


// CIpcRecordDlg �Ի���

CIpcRecordDlg *g_this = NULL;	//��ǰ�Ի���ָ��

CIpcRecordDlg::CIpcRecordDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CIpcRecordDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	//��ʼ��
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


// CIpcRecordDlg ��Ϣ�������

BOOL CIpcRecordDlg::OnInitDialog()
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

	//��ʼ��
	IPAC_DEV_Init();
	IPAC_PLAYER_Init();
	IPAC_PLAYER_DisPlayerMode(FALSE);

	OnBnClickedBtnSearch();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CIpcRecordDlg::OnPaint()
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
HCURSOR CIpcRecordDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//����IP
void CIpcRecordDlg::OnBnClickedBtnSearch()
{
	m_DeviceTree.DeleteAllItems();
	HTREEITEM item  = m_DeviceTree.InsertItem("�豸�б�",TVI_ROOT,TVI_LAST);
	IPAC_DEV_SearchDevice(SearchCallback,this,0);
}

//�����ص�
int WINAPI CIpcRecordDlg::SearchCallback(IPAC_DEV_SEARCH* pSearchData, void *pParam)
{
	HTREEITEM root = g_this->m_DeviceTree.GetRootItem();

	in_addr addr;
	addr.S_un.S_addr = pSearchData->IP;
	g_this->m_DeviceTree.InsertItem(inet_ntoa(addr),root,TVI_LAST);

	g_this->m_DeviceTree.Expand(g_this->m_DeviceTree.GetRootItem(),TVE_EXPAND);

	return 0;
}

//˫�����¼�
void CIpcRecordDlg::OnDblclkTreeDevice(NMHDR *pNMHDR, LRESULT *pResult)
{
	HTREEITEM item = m_DeviceTree.GetSelectedItem();
	CString ip = m_DeviceTree.GetItemText(item);
	OpenDevice(ip.GetBuffer(ip.GetLength()),8100,TRUE);

	*pResult = 0;
}

//���豸
int CIpcRecordDlg::OpenDevice(CString ip, int port,BOOL showMsg)
{
	if (ip == "" || ip == "�豸�б�" ){
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
			MessageBox("��¼ʧ��");
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
			MessageBox("���Ų��ɹ�");
		}		
	}else{
	
		GetDlgItem(IDC_BTN_RECORD)->EnableWindow(TRUE);
	}
	TRACE("��ͨ��, ip =%s \n",ip);

	return 0;
}

// ��Ƶ���ݻص�����
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

// �ر�ͨ��
BOOL CIpcRecordDlg::CloseChannel()
{
	//�Ͽ�ͨ��
	if (m_VideoHandle>0)
	{
		IPAC_DEV_StopRealPlay(m_VideoHandle);
		m_VideoHandle = 0;	
		TRACE("�Ͽ���Ƶͨ��\n");
	}		

	//��¼ע��
	if (m_UserID>0)
	{
		IPAC_DEV_Logout(m_UserID);
		m_UserID=0;
		TRACE("ע���豸��¼\n");
	}

	//�ͷŲ�����
	if (m_Port != -1)
	{
		IPAC_PLAYER_Stop(m_Port);
		IPAC_PLAYER_FreePort(m_Port);
		m_Port=-1;
		TRACE("�ͷŲ�����\n");
	}

	//ˢ�²��Ŵ���
	GetDlgItem(IDC_STATIC_VIDEO)->Invalidate();
	GetDlgItem(IDC_STATIC_VIDEO)->UpdateData();
	return TRUE;
}

//�رմ���
void CIpcRecordDlg::OnClose()
{
	if (MessageBox("ȷʵҪ�˳���", "��ʾ", MB_OKCANCEL|MB_ICONWARNING) == IDOK)
	{
		CDialog::OnClose();
	}
}

// ��������
void CIpcRecordDlg::OnDestroy()
{
	 
		CDialog::OnDestroy();
		CloseChannel();
		IPAC_DEV_Cleanup();
}


// ¼���¼�
void CIpcRecordDlg::OnBnClickedBtnRecord()
{
	if (m_VideoHandle<=0){
		return;
	}

	CString text;
	GetDlgItemText(IDC_BTN_RECORD,text);
	if(text == "��ʼ¼��"){
		CTime pt = CTime::GetCurrentTime();
		CString szRecodeName;
		szRecodeName.Format("%04d%02d%02d_%02d%02d%02d.mp4",pt.GetYear(),pt.GetMonth(),pt.GetDay(),pt.GetHour(),pt.GetMinute(),pt.GetSecond());

		IPAC_DEV_StartRecord(m_VideoHandle,(PTSTR)(LPCTSTR)szRecodeName);

		text="ֹͣ¼��";
		SetDlgItemText(IDC_BTN_RECORD,text);
	}else{
		IPAC_DEV_StopRecord(m_VideoHandle);

		text="��ʼ¼��";
		SetDlgItemText(IDC_BTN_RECORD,text);
	}
}
