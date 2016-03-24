
// IpcRecordDlg.h : 头文件
//

#pragma once


// CIpcRecordDlg 对话框
class CIpcRecordDlg : public CDialogEx
{
// 构造
public:
	CIpcRecordDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_IPCRECORD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


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
	CTreeCtrl m_DeviceTree;
	LONG m_VideoHandle;
	ULONG m_UserID;
	int m_Port;
	
	int OpenDevice(CString ip, int port,BOOL showMsg=FALSE); //打开设备
	BOOL CloseChannel();	//关闭通道
	static int WINAPI SearchCallback(IPAC_DEV_SEARCH* pSearchData, void *pParam);
	static BOOL WINAPI StreamCallback(LONG lRealHandle,DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser);
public:
	afx_msg void OnBnClickedBtnSearch();
	afx_msg void OnDblclkTreeDevice(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDestroy();
	afx_msg void OnClose();
	afx_msg void OnBnClickedBtnRecord();
};
