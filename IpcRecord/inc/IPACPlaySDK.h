///////////////////////////////////////////////////////////////////
//File:			WWAPlaySDK.h
//ver:			1.0
//Date:			2011-11-12
//Description:	Interface for WWAPlaySDK.dll
///////////////////////////////////////////////////////////////////


#ifndef _WWAPlaySDK_H_
#define _WWAPlaySDK_H_

#if defined( _WINDLL)
#define IPAC_PLAYER_API  extern "C"__declspec(dllexport) 
#else 
#define IPAC_PLAYER_API  extern "C" __declspec(dllimport) 
#endif

//Max channel numbers
#define PLAY_MAX_SUPPORTS 100

//Stream type
#define STREAME_REALTIME 0
#define STREAME_FILE	 1

//video_type  ��Ƶ��������
#define VIDEO_H264          0x0  // ��׼H.264��˽��H.264
#define VIDEO_MPEG4         0x1  // ��׼MPEG4
#define VIDEO_JPEG          0x2  // ��׼JPEG

// ��Ƶ��������
#define AUDIO_NULL          0x0000 // û����Ƶ
#define AUDIO_ADPCM         0x1000 // ADPCM 
#define AUDIO_MPEG          0x2000 // MPEG ϵ����Ƶ��������������Ӧ����MPEG��Ƶ

// Gϵ����Ƶ
#define AUDIO_G711_U		0x7110
#define AUDIO_G711_A		0x7111
#define AUDIO_G722_1		0x7221
#define AUDIO_G723_1        0x7231
#define AUDIO_G726          0x7260
#define AUDIO_G729          0x7290


//Source buffer
#define SOURCE_BUF_MAX	1024*100000
#define SOURCE_BUF_MIN	1024*50


//Error code
#define  PLAY_NOERROR					0	//no error
#define	 PLAY_PARA_OVER					1	//input parameter is invalid;
#define  PLAY_ORDER_ERROR				2	//The order of the function to be called is error.
#define	 PLAY_TIMER_ERROR				3	//Create multimedia clock failed;
#define  PLAY_DEC_VIDEO_ERROR			4	//Decode video data failed.
#define  PLAY_DEC_AUDIO_ERROR			5	//Decode audio data failed.
#define	 PLAY_ALLOC_MEMORY_ERROR		6	//Allocate memory failed.
#define  PLAY_OPEN_FILE_ERROR			7	//Open the file failed.
#define  PLAY_CREATE_OBJ_ERROR			8	//Create thread or event failed


#define NET_PLAYM4_NOERROR 500				//û�д��� 
#define NET_PLAYM4_PARA_OVER 501			//��������Ƿ� 
#define NET_PLAYM4_ORDER_ERROR 502			//����˳�򲻶� 
#define NET_PLAYM4_TIMER_ERROR 503			//��ý��ʱ������ʧ�� 
#define NET_PLAYM4_DEC_VIDEO_ERROR 504		//��Ƶ����ʧ�� 
#define NET_PLAYM4_DEC_AUDIO_ERROR 505		//��Ƶ����ʧ�� 
#define NET_PLAYM4_ALLOC_MEMORY_ERROR 506	 //�����ڴ�ʧ�� 
#define NET_PLAYM4_OPEN_FILE_ERROR 507		//�ļ�����ʧ�� 
#define NET_PLAYM4_CREATE_OBJ_ERROR 508		//�����߳��¼���ʧ�� 
#define NET_PLAYM4_CREATE_DDRAW_ERROR 509	//����directDrawʧ�� 
#define NET_PLAYM4_CREATE_OFFSCREEN_ERROR 510 //������˻���ʧ�� 
#define NET_PLAYM4_BUF_OVER 511				 //����������������ʧ�� 
#define NET_PLAYM4_CREATE_SOUND_ERROR 512	 //������Ƶ�豸ʧ�� 
#define NET_PLAYM4_SET_VOLUME_ERROR 513		//��������ʧ�� 
#define NET_PLAYM4_SUPPORT_FILE_ONLY 514	//ֻ���ڲ����ļ�ʱ����ʹ�ô˽ӿ� 
#define NET_PLAYM4_SUPPORT_STREAM_ONLY 515	//ֻ���ڲ�����ʱ����ʹ�ô˽ӿ� 
#define NET_PLAYM4_SYS_NOT_SUPPORT 516		//ϵͳ��֧�֣�������ֻ�ܹ�����Pentium 3���� 
#define NET_PLAYM4_FILEHEADER_UNKNOWN 517	//û���ļ�ͷ 
#define NET_PLAYM4_VERSION_INCORRECT 518	//�������ͱ������汾����Ӧ 
#define NET_PALYM4_INIT_DECODER_ERROR 519	//��ʼ��������ʧ�� 
#define NET_PLAYM4_CHECK_FILE_ERROR 520		//�ļ�̫�̻������޷�ʶ�� 
#define NET_PLAYM4_INIT_TIMER_ERROR 521		//��ʼ����ý��ʱ��ʧ�� 
#define NET_PLAYM4_BLT_ERROR 522			//λ����ʧ��  
#define NET_PLAYM4_UPDATE_ERROR 523			//��ʾoverlayʧ�� 
#define NET_PLAYM4_OPEN_FILE_ERROR_MULTI 524 //�򿪻�����ļ�ʧ��  
#define NET_PLAYM4_OPEN_FILE_ERROR_VIDEO 525 ///����Ƶ���ļ�ʧ��  
#define NET_PLAYM4_JPEG_COMPRESS_ERROR 526	//JPEGѹ������  

//-------------------------------------------ver 1.0-----------------------------------------------
typedef void (CALLBACK * FileEndMsgCallBack)(DWORD nPort, UINT MessageID,void *pContext);

IPAC_PLAYER_API int IPAC_PLAYER_Init(void);
IPAC_PLAYER_API int IPAC_PLAYER_Cleanup(void);

IPAC_PLAYER_API int IPAC_PLAYER_GetPort(ULONG nPort,HWND hWnd);
IPAC_PLAYER_API int IPAC_PLAYER_FreePort(ULONG nPort);

IPAC_PLAYER_API int IPAC_PLAYER_DisPlayerMode(BOOL bMode);

IPAC_PLAYER_API int IPAC_PLAYER_Play(ULONG nPort);
IPAC_PLAYER_API int IPAC_PLAYER_Stop(ULONG nPort);

IPAC_PLAYER_API int IPAC_PLAYER_StartShearRecord(ULONG nPort, char *recordfile_name);
IPAC_PLAYER_API int IPAC_PLAYER_StopShearRecord(ULONG nPort);

IPAC_PLAYER_API int IPAC_PLAYER_InputData(ULONG nPort,PBYTE buf,DWORD dwSize);
IPAC_PLAYER_API int IPAC_PLAYER_InputVideoData(ULONG nPort,PBYTE buf,DWORD dwSize);
IPAC_PLAYER_API int IPAC_PLAYER_InputAudioData(ULONG nPort,PBYTE buf,DWORD dwSize);
IPAC_PLAYER_API int IPAC_PLAYER_RefreshPlay(LONG nPort);
IPAC_PLAYER_API int IPAC_PLAYER_CaptureOnePicture(ULONG nPort, char *in_file_name);


IPAC_PLAYER_API int IPAC_PLAYER_OpenFile(ULONG nPort, char *file_name);
IPAC_PLAYER_API int IPAC_PLAYER_CloseFile(ULONG nPort);
IPAC_PLAYER_API int IPAC_PLAYER_GetStreamFileInfo(int nPort,DWORD &dwTimeLength);
IPAC_PLAYER_API int IPAC_PLAYER_Fast(ULONG nPort);
IPAC_PLAYER_API int IPAC_PLAYER_Slow(ULONG nPort);
IPAC_PLAYER_API int IPAC_PLAYER_Pause(ULONG nPort);
IPAC_PLAYER_API int IPAC_PLAYER_NextFrame(ULONG nPort);
IPAC_PLAYER_API int IPAC_PLAYER_SetFileEndCallBack(ULONG nPort,FileEndMsgCallBack pFileDoneProc, void *pContext);

IPAC_PLAYER_API int IPAC_PLAYER_GetFilePos(ULONG nPort);
IPAC_PLAYER_API int IPAC_PLAYER_SetFilePos(ULONG nPort, DWORD pos);

IPAC_PLAYER_API int IPAC_PLAYER_GetFileTotalSize(ULONG nPort);
IPAC_PLAYER_API int IPAC_PLAYER_GetFileTotalTime(ULONG nPort);

IPAC_PLAYER_API int IPAC_PLAYER_GetCurPlayedTime(ULONG nPort);
IPAC_PLAYER_API int IPAC_PLAYER_SetCurPlayedTime(ULONG nPort, int len);

IPAC_PLAYER_API int IPAC_PLAYER_GetBufNum(ULONG nPort);
IPAC_PLAYER_API int IPAC_PLAYER_SetBufNum(ULONG nPort, int num);

IPAC_PLAYER_API int IPAC_PLAYER_GetPictureSize(ULONG nPort, int *width, int *height);

IPAC_PLAYER_API int IPAC_PLAYER_SetWriteLog(BOOL bflag);

IPAC_PLAYER_API int IPAC_PLAYER_GetSdkVersion();
IPAC_PLAYER_API int IPAC_PLAYER_GetLastError();

#endif