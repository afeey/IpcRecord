
// IpcRecordDlg.h : ͷ�ļ�
//

#pragma once


// CIpcRecordDlg �Ի���
class CIpcRecordDlg : public CDialogEx
{
// ����
public:
	CIpcRecordDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_IPCRECORD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


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
	CTreeCtrl m_DeviceTree;
	LONG m_VideoHandle;
	ULONG m_UserID;
	int m_Port;
	
	int OpenDevice(CString ip, int port,BOOL showMsg=FALSE); //���豸
	BOOL CloseChannel();	//�ر�ͨ��
	static int WINAPI SearchCallback(IPAC_DEV_SEARCH* pSearchData, void *pParam);
	static BOOL WINAPI StreamCallback(LONG lRealHandle,DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser);
public:
	afx_msg void OnBnClickedBtnSearch();
	afx_msg void OnDblclkTreeDevice(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDestroy();
	afx_msg void OnClose();
	afx_msg void OnBnClickedBtnRecord();
};
