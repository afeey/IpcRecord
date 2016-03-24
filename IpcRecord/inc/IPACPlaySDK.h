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

//video_type  视频编码类型
#define VIDEO_H264          0x0  // 标准H.264和私有H.264
#define VIDEO_MPEG4         0x1  // 标准MPEG4
#define VIDEO_JPEG          0x2  // 标准JPEG

// 音频编码类型
#define AUDIO_NULL          0x0000 // 没有音频
#define AUDIO_ADPCM         0x1000 // ADPCM 
#define AUDIO_MPEG          0x2000 // MPEG 系列音频，解码器能自适应各种MPEG音频

// G系列音频
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


#define NET_PLAYM4_NOERROR 500				//没有错误 
#define NET_PLAYM4_PARA_OVER 501			//输入参数非法 
#define NET_PLAYM4_ORDER_ERROR 502			//调用顺序不对 
#define NET_PLAYM4_TIMER_ERROR 503			//多媒体时钟设置失败 
#define NET_PLAYM4_DEC_VIDEO_ERROR 504		//视频解码失败 
#define NET_PLAYM4_DEC_AUDIO_ERROR 505		//音频解码失败 
#define NET_PLAYM4_ALLOC_MEMORY_ERROR 506	 //分配内存失败 
#define NET_PLAYM4_OPEN_FILE_ERROR 507		//文件操作失败 
#define NET_PLAYM4_CREATE_OBJ_ERROR 508		//创建线程事件等失败 
#define NET_PLAYM4_CREATE_DDRAW_ERROR 509	//创建directDraw失败 
#define NET_PLAYM4_CREATE_OFFSCREEN_ERROR 510 //创建后端缓存失败 
#define NET_PLAYM4_BUF_OVER 511				 //缓冲区满，输入流失败 
#define NET_PLAYM4_CREATE_SOUND_ERROR 512	 //创建音频设备失败 
#define NET_PLAYM4_SET_VOLUME_ERROR 513		//设置音量失败 
#define NET_PLAYM4_SUPPORT_FILE_ONLY 514	//只能在播放文件时才能使用此接口 
#define NET_PLAYM4_SUPPORT_STREAM_ONLY 515	//只能在播放流时才能使用此接口 
#define NET_PLAYM4_SYS_NOT_SUPPORT 516		//系统不支持，解码器只能工作在Pentium 3以上 
#define NET_PLAYM4_FILEHEADER_UNKNOWN 517	//没有文件头 
#define NET_PLAYM4_VERSION_INCORRECT 518	//解码器和编码器版本不对应 
#define NET_PALYM4_INIT_DECODER_ERROR 519	//初始化解码器失败 
#define NET_PLAYM4_CHECK_FILE_ERROR 520		//文件太短或码流无法识别 
#define NET_PLAYM4_INIT_TIMER_ERROR 521		//初始化多媒体时钟失败 
#define NET_PLAYM4_BLT_ERROR 522			//位拷贝失败  
#define NET_PLAYM4_UPDATE_ERROR 523			//显示overlay失败 
#define NET_PLAYM4_OPEN_FILE_ERROR_MULTI 524 //打开混合流文件失败  
#define NET_PLAYM4_OPEN_FILE_ERROR_VIDEO 525 ///打开视频流文件失败  
#define NET_PLAYM4_JPEG_COMPRESS_ERROR 526	//JPEG压缩错误  

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