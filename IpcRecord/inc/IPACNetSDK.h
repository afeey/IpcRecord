///////////////////////////////////////////////////////////////////
//File:			WWADevSDK.h
//ver:			1.0
//Date:			2011-11-12
//Description:	Interface for WWADevSDK.dll
///////////////////////////////////////////////////////////////////

#ifndef IPAC_DEVSDK_H_
#define IPAC_DEVSDK_H_

// #ifdef __cplusplus
// extern "C" {
// #endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#ifdef IPAC_DEVSDK_H_
#define IPAC_API extern "C" __declspec(dllexport) 
#else 
#define IPAC_API extern "C" __declspec(dllimport) 
#endif

//宏定义
#define NAME_LEN		    	16      //名称长度
#define PASSWD_LEN			    16      //密码长度
#define SERIALNO_LEN		    16      //序列号长度

/*******************全局错误码 begin**********************/	
#define IPAC_DEV_NOERROR				 0	//没有错误。
#define IPAC_DEV_PASSWORD_ERROR			1	//用户名密码错误。注册时输入的用户名或者密码错误。
#define IPAC_DEV_NOENOUGHPRI			2	//权限不足。该注册用户没有权限执行当前对设备的操作，可以与远程用户参数配置做对比。
#define IPAC_DEV_NOINIT     			3	//SDK未初始化。
#define IPAC_DEV_CHANNEL_ERROR			4	//通道号错误。设备没有对应的通道号。
#define IPAC_DEV_OVER_MAXLINK			5	//连接到设备的用户个数超过最大。
#define IPAC_DEV_VERSIONNOMATCH			6	//版本不匹配。SDK和设备的版本不匹配。
#define IPAC_DEV_NETWORK_FAIL_CONNECT	7	//连接设备失败。设备不在线或网络原因引起的连接超时等。
#define IPAC_DEV_NETWORK_SEND_ERROR		8	//向设备发送失败。
#define IPAC_DEV_NETWORK_RECV_ERROR		9	//从设备接收数据失败。
#define IPAC_DEV_NETWORK_RECV_TIMEOUT	10	//从设备接收数据超时。
#define IPAC_DEV_NETWORK_ERRORDATA		11	//传送的数据有误。发送给设备或者从设备接收到的数据错误，如远程参数配置时输入设备不支持的值。
#define IPAC_DEV_ORDER_ERROR			12	//调用次序错误。
#define IPAC_DEV_OPERNOPERMIT			13	//无此权限。
#define IPAC_DEV_COMMANDTIMEOUT			14	//设备命令执行超时。
#define IPAC_DEV_ERRORSERIALPORT		15	//串口号错误。指定的设备串口号不存在。
#define IPAC_DEV_ERRORALARMPORT			16	//报警端口错误。指定的设备报警输出端口不存在。
#define IPAC_DEV_PARAMETER_ERROR		17	//参数错误。SDK接口中给入的输入或输出参数为空。
#define IPAC_DEV_CHAN_EXCEPTION			18	//设备通道处于错误状态
#define IPAC_DEV_NODISK					19	//设备无硬盘。当设备无硬盘时，对设备的录像文件、硬盘配置等操作失败。
#define IPAC_DEV_ERRORDISKNUM			20	//硬盘号错误。当对设备进行硬盘管理操作时，指定的硬盘号不存在时返回该错误。
#define IPAC_DEV_DISK_FULL				21	//设备硬盘满。
#define IPAC_DEV_DISK_ERROR 			22	//设备硬盘出错
#define IPAC_DEV_NOSUPPORT				23	//设备不支持。
#define IPAC_DEV_BUSY					24	//设备忙。
#define IPAC_DEV_MODIFY_FAIL			25	//设备修改不成功。
#define IPAC_DEV_PASSWORD_FORMAT_ERROR	26	//密码输入格式不正确
#define IPAC_DEV_DISK_FORMATING			27	//硬盘正在格式化，不能启动操作。
#define IPAC_DEV_DVRNORESOURCE			28	//设备资源不足。
#define IPAC_DEV_DVROPRATEFAILED		29	//设备操作失败。
#define IPAC_DEV_OPENHOSTSOUND_FAIL		30	//语音对讲、语音广播操作中采集本地音频或打开音频输出失败。
#define IPAC_DEV_DVRVOICEOPENED			31	//设备语音对讲被占用。
#define IPAC_DEV_TIMEINPUTERROR			32	//时间输入不正确。
#define IPAC_DEV_NOSPECFILE 			33	//回放时设备没有指定的文件。
#define IPAC_DEV_CREATEFILE_ERROR		34	//创建文件出错。本地录像、保存图片、获取配置文件和远程下载录像时创建文件失败。
#define IPAC_DEV_FILEOPENFAIL			35	//打开文件出错。设置配置文件、设备升级、上传审讯文件时打开文件失败。
#define IPAC_DEV_OPERNOTFINISH			36	//上次的操作还没有完成。
#define IPAC_DEV_GETPLAYTIMEFAIL		37	//获取当前播放的时间出错。
#define IPAC_DEV_PLAYFAIL				38	//播放出错。
#define IPAC_DEV_FILEFORMAT_ERROR		39	//文件格式不正确。
#define IPAC_DEV_DIR_ERROR				40	//路径错误
#define IPAC_DEV_ALLOC_RESOURCE_ERROR	41	//SDK资源分配错误。
#define IPAC_DEV_AUDIO_MODE_ERROR		42	//声卡模式错误。当前打开声音播放模式与实际设置的模式不符出错。
#define IPAC_DEV_NOENOUGH_BUF			43	//缓冲区太小。接收设备数据的缓冲区或存放图片缓冲区不足。
#define IPAC_DEV_CREATESOCKET_ERROR		44	//创建SOCKET出错。
#define IPAC_DEV_SETSOCKET_ERROR		45	//设置SOCKET出错。
#define IPAC_DEV_MAX_NUM				46	//个数达到最大。分配的注册连接数、预览连接数超过SDK支持的最大数。
#define IPAC_DEV_USERNOTEXIST			47	//用户不存在。注册的用户ID已注销或不可用。
#define IPAC_DEV_WRITEFLASHERROR		48	//写FLASH出错。设备升级时写FLASH失败。
#define IPAC_DEV_UPGRADEFAIL			49	//设备升级失败。网络或升级文件语言不匹配等原因升级失败。
#define IPAC_DEV_CARDHAVEINIT			50	//解码卡已经初始化过。
#define IPAC_DEV_PLAYERFAILED			51	//调用播放库中某个函数失败。
#define IPAC_DEV_MAX_USERNUM			52	//登录设备的用户数达到最大。
#define IPAC_DEV_GETLOCALIPANDMACFAIL	53	//获得本地PC的IP地址或物理地址失败。
#define IPAC_DEV_NOENCODEING			54	//设备该通道没有启动编码。
#define IPAC_DEV_IPMISMATCH				55	//IP地址不匹配。
#define IPAC_DEV_MACMISMATCH			56	//MAC地址不匹配。
#define IPAC_DEV_UPGRADELANGMISMATCH	57	//升级文件语言不匹配。
#define IPAC_DEV_MAX_PLAYERPORT			58	//播放器路数达到最大。
#define IPAC_DEV_NOSPACEBACKUP			59	//备份设备中没有足够空间进行备份。
#define IPAC_DEV_NODEVICEBACKUP			60	//没有找到指定的备份设备。
#define IPAC_DEV_PICTURE_BITS_ERROR		61	//图像素位数不符，限24色。
#define IPAC_DEV_PICTURE_DIMENSION_ERROR	62	//图片高*宽超限，限128*256。
#define IPAC_DEV_PICTURE_SIZ_ERROR			63	//图片大小超限，限100K。
#define IPAC_DEV_LOADPLAYERSDKFAILED		64	//载入当前目录下Player Sdk出错。
#define IPAC_DEV_LOADPLAYERSDKPROC_ERROR	65	//找不到Player Sdk中某个函数入口。
#define IPAC_DEV_LOADDSSDKFAILED			66	//载入当前目录下DSsdk出错。
#define IPAC_DEV_LOADDSSDKPROC_ERROR		67	//找不到DsSdk中某个函数入口。
#define IPAC_DEV_DSSDK_ERROR				68	//调用硬解码库DsSdk中某个函数失败。
#define IPAC_DEV_VOICEMONOPOLIZE			69	//声卡被独占。
#define IPAC_DEV_JOINMULTICASTFAILED		70	//加入多播组失败。
#define IPAC_DEV_CREATEDIR_ERROR			71	//建立日志文件目录失败。
#define IPAC_DEV_BINDSOCKET_ERROR			72	//绑定套接字失败。
#define IPAC_DEV_SOCKETCLOSE_ERROR			73	//socket连接中断，此错误通常是由于连接中断或目的地不可达。
#define IPAC_DEV_USERID_ISUSING				74	//注销时用户ID正在进行某操作。
#define IPAC_DEV_SOCKETLISTEN_ERROR			75	//监听失败。
#define IPAC_DEV_PROGRAM_EXCEPTION			76	//程序异常。
#define IPAC_DEV_WRITEFILE_FAILED			77	//写文件失败。本地录像、远程下载录像、下载图片等操作时写文件失败。
#define IPAC_DEV_FORMAT_READONLY			78	//禁止格式化只读硬盘。
#define IPAC_DEV_WITHSAMEUSERNAME			79	//远程用户配置结构中存在相同的用户名。
#define IPAC_DEV_DEVICETYPE_ERROR			80	//导入参数时设备型号不匹配。
#define IPAC_DEV_LANGUAGE_ERROR				81	//导入参数时语言不匹配。
#define IPAC_DEV_PARAVERSION_ERROR			82	//导入参数时软件版本不匹配。
#define IPAC_DEV_IPCHAN_NOTALIVE			83	//预览时外接IP通道不在线。
#define IPAC_DEV_RTSP_SDK_ERROR				84	//加载标准协议通讯库StreamTransClient失败。
#define IPAC_DEV_CONVERT_SDK_ERROR			85	//加载转码库失败。
#define IPAC_DEV_IPC_COUNT_OVERFLOW			86	//超出最大的IP接入通道数。
#define IPAC_DEV_PARAMMODE_ERROR			88	//图像增强仪，参数模式错误（用于硬件设置时，客户端进行软件设置时错误值）。
#define IPAC_DEV_CODESPITTER_OFFLINE		89	//视频综合平台，码分器不在线。
#define IPAC_DEV_BACKUP_COPYING				90	//设备正在备份。
#define IPAC_DEV_CHAN_NOTSUPPORT			91	//通道不支持该操作。
#define IPAC_DEV_OLD_VERSIONS				92  //网络库较旧，建议更新


/*************************设备升级错误码 OP*******************************/
#define IPAC_DEV_UP_SOCKET					200	//发送或接收数据出错
#define IPAC_DEV_UP_OPENFILE_ERROR			201	//升级文件打开失败
#define IPAC_DEV_UP_FILE_ERROR				202	//升级文件不正确
#define IPAC_DEV_UP_SENDFILE				203	//请求向设备发送文件失败
#define IPAC_DEV_UP_SENDFILE_ERROR			204	//发送文件失败
#define IPAC_DEV_UP_DEVUP					205	//请求设备升级失败
#define IPAC_DEV_UP_DEVUP_ERROR				206	//设备升级失败
#define IPAC_DEV_UP_ENOTSUP					207 //设备不支持该升级方式
#define IPAC_DEV_UP_ERROR					208 //其他
/*************************设备升级错误码 ED*******************************/



/*************************语音对讲错误码 OP*******************************/
#define IPAC_DEV_VOICE_OPEN					230	//设备音频没有打开
#define IPAC_DEV_VOICE_GETINFO				231	//设备音频没有打开
#define IPAC_DEV_VOICE_CONNECT				232 //连接设备对讲失败
/*************************语音对讲错误码 ED*******************************/


/*************************设备升级状态码 OP*******************************/
#define IPAC_DEV_UPSTATE_ERROR				0	//升级过程出错
#define IPAC_DEV_UPSTATE_SENDFILE           1	//正在发送文件
#define IPAC_DEV_UPSTATE_SENDFILEEND		2	//发送文件结束
#define IPAC_DEV_UPSTATE_UP					3	//正在升级设备
#define IPAC_DEV_UPSTATE_UPEND				4	//设备升级完成
#define IPAC_DEV_UPSTATE_REBOOTFAIL			5	//设备重启失败
/*************************设备升级状态码 ED*******************************/



/**********************云台控制命令 begin*************************/	

#define SET_PRESET		8	/* 设置预置点 */
#define CLE_PRESET		9	/* 清除预置点 */

#define PTZ_ZOOM_IN		11	/* 焦距以速度SS变大(倍率变大) */
#define PTZ_ZOOM_OUT	12	/* 焦距以速度SS变小(倍率变小) */
#define FOCUS_NEAR      13  /* 焦点以速度SS前调 */
#define FOCUS_FAR       14  /* 焦点以速度SS后调 */
#define IRIS_OPEN       15  /* 光圈以速度SS扩大 */
#define IRIS_CLOSE      16  /* 光圈以速度SS缩小 */

#define TILT_UP			21	/* 云台以SS的速度上仰 */
#define TILT_DOWN		22	/* 云台以SS的速度下俯 */
#define PAN_LEFT		23	/* 云台以SS的速度左转 */
#define PAN_RIGHT		24	/* 云台以SS的速度右转 */
#define UP_LEFT			25	/* 云台以SS的速度上仰和左转 */
#define UP_RIGHT		26	/* 云台以SS的速度上仰和右转 */
#define DOWN_LEFT		27	/* 云台以SS的速度下俯和左转 */
#define DOWN_RIGHT		28	/* 云台以SS的速度下俯和右转 */
#define PAN_AUTO		29	/* 云台以SS的速度左右自动扫描 */

#define FILL_PRE_SEQ	30	/* 将预置点加入巡航序列 */
#define SET_SEQ_DWELL	31	/* 设置巡航点停顿时间 */
#define SET_SEQ_SPEED	32	/* 设置巡航速度 */
#define CLE_PRE_SEQ		33	/* 将预置点从巡航序列中删除 */
#define STA_MEM_CRUISE	34	/* 开始记录轨迹 */
#define STO_MEM_CRUISE	35	/* 停止记录轨迹 */
#define RUN_CRUISE		36	/* 开始轨迹 */
#define RUN_SEQ			37	/* 开始巡航 */
#define STOP_SEQ		38	/* 停止巡航 */
#define GOTO_PRESET		39	/* 快球转到预置点 */


#define CLE_ALL_PRE_SEQ	44	/* 删除指定的巡航序列*/

/**********************云台控制命令 end*************************/	



/*************************参数配置命令 begin*******************************/
//用于IPAC_DEV_SetConfig和IPAC_DEVR_GetConfig,注意其对应的配置结构

#define IPAC_DEV_GET_DEVICECFG		100		//获取设备描述参数
#define IPAC_DEV_SET_DEVICECFG		101		//设置设备描述参数
#define IPAC_DEV_GET_NETCFG			102		//获取网络参数
#define IPAC_DEV_SET_NETCFG			103		//设置网络参数

#define IPAC_DEV_GET_CODERCFG		104		//获取编码参数
#define IPAC_DEV_SET_CODERCFG		105		//设置编码参数
#define IPAC_DEV_GET_CODER1CFG		106		//获取高级编码参数
#define IPAC_DEV_SET_CODER1CFG		107		//设置高级编码参数

#define IPAC_DEV_GET_VIDEOCFG		108		//获取图象参数
#define IPAC_DEV_SET_VIDEOCFG		109		//设置图象参数
#define IPAC_DEV_GET_VIDEO1CFG		110		//获取高级图象参数
#define IPAC_DEV_SET_VIDEO1CFG		111		//设置高级图象参数

#define IPAC_DEV_GET_AUDIOCFG		112		//获取音频参数
#define IPAC_DEV_SET_AUDIOCFG		113		//设置音频参数

#define IPAC_DEV_GET_SYSCFG			114		//获取系统参数
#define IPAC_DEV_SET_SYSCFG			115		//设置系统参数

#define IPAC_DEV_GET_TIMECFG 		116		//获取设备时间
#define IPAC_DEV_SET_TIMECFG		117		//设置设备时间

#define IPAC_DEV_GET_OSDCFG 		120		//获取OSD参数
#define IPAC_DEV_SET_OSDCFG			121		//设置OSD参数

#define IPAC_DEV_GET_RECORDYTPE		122		//获取录像格式
#define IPAC_DEV_SET_RECORDTYPE		123		//设置录像格式
#define IPAC_DEV_GET_RECORDCFG 		124		//获取录像参数
#define IPAC_DEV_SET_RECORDCFG		125		//设置录像参数

#define IPAC_DEV_GET_PTZCFG 		126		//获取PTZ参数
#define IPAC_DEV_SET_PTZCFG			127		//设置PTZ参数

#define IPAC_DEV_GET_ALARMCFG 		128		//获取告警参数
#define IPAC_DEV_SET_ALARMCFG		129		//设置告警参数

#define IPAC_DEV_GET_FTPCFG 		130		//获取FTP参数
#define IPAC_DEV_SET_FTPCFG			131		//设置FTP参数

#define IPAC_DEV_GET_IDCFG 			140		//获取设备ID
#define IPAC_DEV_SET_IDCFG			141		//设置设备ID

#define IPAC_DEV_GET_CONFIGURECFG	142		//获取设备配置参数
#define IPAC_DEV_SET_CONFIGURECFG	143		//设置设备配置参数

#define IPAC_DEV_SET_PONTMAT		144		//设置中文字
#define IPAC_DEV_GET_PONTMAT		145	    //获取中文字

#define IPAC_DEV_SET_VMDCFG			146		//读取移动侦测配置
#define IPAC_DEV_GET_VMDCFG			147	    //设置移动侦测配置

#define IPAC_DEV_GET_NETCFGEX		148		//读取设备网络扩展信息
#define IPAC_DEV_SET_NETCFGEX		149		//设置设备网络扩展信息

#define IPAC_DEV_GET_P2PCFG			150		//读取设备P2P服务器配置
#define IPAC_DEV_SET_P2PCFG			151		//设置设备P2P服务器配置

#define IPAC_DEV_GET_DDNSCFG		152		//读取设备DDNS服务器配置
#define IPAC_DEV_SET_DDNSCFG		153		//设置设备DDNS服务器配置

#define IPAC_DEV_GET_28181CFG		154		//读取设备28181配置
#define IPAC_DEV_SET_28181CFG		155		//设置设备28181配置

#define IPAC_DEV_PTZ_PRESETPOINT_NAME 156	//预置点名称配置
#define IPAC_DEV_PTZ_CONTROL		157		//高级功能配置

#define IPAC_DEV_GET_WIFI			158		//获取wifi信息
#define IPAC_DEV_SET_WIFI			159		//配置wifi

typedef enum  _ENCODE_VIDEO_TYPE
{
	FRAME_FLAG_VI=0x64,
	FRAME_FLAG_VP=0x65,
	FRAME_FLAG_VA=0x66,
}ENCODE_VIDEO_TYPE;

/*************************************************
参数配置结构、参数
**************************************************/
#pragma pack(1)

/*
typedef struct Time_
{
	BYTE by;
	BYTE bM;
	BYTE bD;
	BYTE bH;
	BYTE bMm;
	BYTE bS;
}Time_;
*/

typedef struct _WW_FIELD_TIME
{
	unsigned int		nSecond : 6;	// 秒: 0 ~ 59
	unsigned int		nMinute : 6;	// 分: 0 ~ 59
	unsigned int		nHour	: 5;	// 时: 0 ~ 23
	unsigned int		nDay	: 5;	// 日: 1 ~ 31
	unsigned int		nMonth  : 4;	// 月: 1 ~ 12
	unsigned int		nYear   : 6;	// 年: 2000 ~ 2063 
}WW_FIELD_TIME;

typedef union
{
	unsigned int	dwLongTime; // 32位整形访问
	WW_FIELD_TIME	stFieldTime; // 结构体域访问
}HH_TIME;

//size  64
typedef struct _RecodeHead
{
	char    szHead[4];//000002
	short	nVideoHeight; //视频图像高
	short	nVideoWidth;  //视频图像宽

	HH_TIME  pStartTime;
	HH_TIME  pEndTime;
	char   szResd[48];//44];
}RecodeHead;


typedef struct _SetFontMat 
{
	unsigned char szText[20];
	unsigned char szData1[9][32];
	unsigned char szData2[9][128];
}SetFontMat;

//视频参数帧头  size = 16
typedef struct _IPAC_AVINFO
{
	//视频参数
	char		  szHead[4];	//000003
	int			  nFrameSize;           //数据大小
	char		  EncodeVideoType;
	char          szRese[7];
}IPAC_AVINFO,*pIPAC_AVINFO;

//设备描述参数 , 长度 60
typedef struct
{
	BYTE sDEVName[NAME_LEN];     //设备名称
	//以下不可更改
	DWORD  dDEVType ;              //设备类型	
	BYTE   sDEVNO[SERIALNO_LEN];   //序列号
	DWORD  dAppVersion ;           //应用版本	
	DWORD  dAlgVersion ;           //算法版本	
	DWORD  dWebVersion ;           //WEB版本	
	DWORD  dKernelVersion ;        //内核版本	
	DWORD  dBootVersion ;          //BOOT版本			
	DWORD  dHardwareVersion ;      //硬件版本

	char sAppVersionEx[60];			//应用版本扩展信息
	char sDEVTypeEx[16];
	BYTE sReserve[44];				//保留
}IPAC_DEV_DEVICECFG, *LPIPAC_DEV_DEVICECFG;


typedef struct {		//网络参数， 28（新：58）
	DWORD IP;			//IP地址，高位在前
	DWORD Mask;			//网络掩码，高位在前
	DWORD Gateway;		//网关地址，高位在前
	DWORD NameServer;	//域名服务器地址 
	WORD  HttpPort;		//Http端口号
	WORD  RtspPort;		//RTSP端口号
	UCHAR MAC[6];		//MAC地址，高位在前 (一般不需要设置，填充为全0即可)
	BYTE  Dhcp;			//Dhcp  =0 静态IP,  =1 动态
	BYTE  blank1;

	BYTE  blank2;
	BYTE  blank3;

	WORD  ControlPort;		//控制端口
	WORD  VideoPort;		//视频端口
	WORD  RtspPort2;		//Rtsp端口
	WORD  OnvifPort;		//Onvif端口

	BYTE  blank4[2];

	DWORD Dns;				//
	BYTE  Mode;				//Mode 
	BYTE  blank7;
	BYTE  blank8;
	BYTE  blank9;
	BYTE  blank5[10];
}IPAC_DEV_NETCFG, *LPIPAC_DEV_NETCFG;


/*
------------------------------------------------------------------------------------------
		 编码方式	            主分辨率								子分辨率
------------------------------------------------------------------------------------------
0x10     单路H246			0	720(1280*720)						0	
0x11     单路MPEG4     		1	D1(720*480)							0	
0x12	 单路MJPEG     		2	SXGA(1280*1024)						0	
						 	3	1080(1920*1080)						0	
							4	3M									0	
------------------------------------------------------------------------------------------

0x23	H.264 + JPEG      	0	H264:720,JPEG:VGA					0	
							1	H264:D1,JPEG:D1						0	
							2	H264:720,JPEG:720					0	
------------------------------------------------------------------------------------------
                            0	H264:720,JPEG:VGA					0	
0x24	MPEG4 + JPEG     	1	H264:D1,JPEG:D1						0	
					    	2	H264:720,JPEG:720					0	
------------------------------------------------------------------------------------------
0x25	Dual H.264			0	H264:720, H264:CIF					0	
							1	H264:D1, H264:D1					0	
							2	H264:1080, H264:CIF					0	
------------------------------------------------------------------------------------------
0x26	Dual MPEG4 			0	MPEG4:720, MPEG4:CIF				0	
							1	MPEG4:D1, MPEG4:D1					0	
							2	MPEG4:1080, MPEG4:CIF				0	
------------------------------------------------------------------------------------------
0x27	H264 + MPEG4		0	H264:D1,MPEG4:D1					0	
------------------------------------------------------------------------------------------
0xA0	Dual H.264			0										0
0xA1	H.264 + JPEG		1	CIF									1	288*192
							2	VGA									2	320*192
							3	D1									3	QVGA
							4	720P								4	CIF
							5	960P								5	480*270
							6	1080P								6	640*360
							7	3M									7	VGA
							8	5M									8	D1
																	9	720P
																	10	1080P
------------------------------------------------------------------------------------------

*/
typedef struct {   // 设备编码模式  16
	UCHAR nEncode;		//编码方式, 可以选择单路H246、单路MPEG4、双路H246等
	UCHAR Resolution;	//编码分辨率,可以选择720P、1280*960、D1、CIF等
	UCHAR ImageFlip;	//图像翻转，=0 为不翻转；1 为水平方向翻转, 2为垂直方式翻转；3为水平、垂直方向翻转
	UCHAR Resolution2;	//编码分辨率,可以选择720P、1280*960、D1、CIF等

	UCHAR RateCtrol1;	//码流一速率控制，=0 为关闭；=1 为VBR  =2为CBR
	UCHAR CodeRate1;	//码流一码率，范围为500-8000 kbps，设置码率为（实际值/100）kbps
	UCHAR FrameRate1;	//码流一帧率，=0 为30；=1 为24  =2为15  =3为8
	UCHAR Quality1;		//码流一质量，=1-10 

	UCHAR RateCtrol2;	//码流二速率控制，=0 为关闭；=1 为VBR  =2为CBR
	UCHAR CodeRate2;	//码流二码率，范围为500-8000 kbps，设置码率为（实际值/100）kbps
	UCHAR FrameRate2;	//码流二帧率，=0 为30；=1 为24  =2为15  =3为8
	UCHAR Quality2;		//码流二质量，=1-10 

	//DWORD Blank2;
	UCHAR n264Encode;	//H264编码方式
	UCHAR IFrameGap;	//I帧间隔
	UCHAR Blank1;
	UCHAR Blank2;

	UCHAR MainMaxResolution; //主码留最大支持分辨率
	UCHAR SubMaxResolution;  //次码流最大支持分辨率
	UCHAR Blank3;
	UCHAR Blank4;

	UCHAR Blank5[26];
}IPAC_DEV_CODERCFG, *LPIPAC_DEV_CODERCFG;



typedef struct {     //设备高级编码模式 , 20
	UCHAR IpRatio1;	 //流1 IP Ratio, 1-30（30）
	UCHAR fIframe1;	 //流1 强制I帧,   1为选中,
	UCHAR qpInit1;	 //流1 QP 初始值，1-51（28）,
	UCHAR qpMin1;	 //流1 QP 最小值，1-51（1）,
	UCHAR qpMax1;	 //流1 QP 最大值，1-51（51）,
	UCHAR meConfig1;	 //流1 Encode Preset , 0-AUTO  1-CUSTOM  2-SVC （0,
	UCHAR packetSize1;	 //流1 Packet Size  1-100（100，单位是%）,
	UCHAR Blank1;
 	WORD Blank2;

	UCHAR IpRatio2;	 //流2 IP Ratio, 1-30（30）
	UCHAR fIframe2;	 //流2 强制I帧,   1为选中,
	UCHAR qpInit2;	 //流2 QP 初始值，1-51（28）,
	UCHAR qpMin2;	 //流2 QP 最小值，1-51（1）,
	UCHAR qpMax2;	 //流2 QP 最大值，1-51（51）,
	UCHAR meConfig2;	 //流2 Encode Preset , 0-AUTO  1-CUSTOM  2-SVC （0,
	UCHAR packetSize2;	 //流2 Packet Size  1-100（100，单位是%）,
	UCHAR Blank21;
 	WORD Blank22;
}IPAC_DEV_CODER2CFG, *LPIPAC_DEV_CODER2CFG;


typedef struct {    // 设备图像参数  17
	UCHAR nBright;		//亮度，范围为1-100
	UCHAR nContrast;	//对比度，范围为1-100
	UCHAR nSaturat;		//饱和度，范围为1-100
	UCHAR nSharpen;		//锐利度，范围为1-100
	UCHAR bPAL;			//编码制式，=0 为NTSC/60HZ；=1 为PAL/50HZ
	UCHAR bIRCut;		//滤光片模式 = 0自动  =1 白天  =2 晚上  =3 定时切换  =4 io_in控制
	UCHAR bColor;		//晚上图像  = 0彩色  =1 黑白
    UCHAR bBLC;			//背光补偿，=0 关  =1 小  =2 中  =3 大
	UCHAR bOpenWB;		//白平衡天关，=0 为关闭；	  =1 为AE      =2 为AEW    =3 为AEWB
	UCHAR bModeWB;		//白平衡模式，=0 自动；	  
	UCHAR bIntelNoise;		//智能降噪 0 为关闭           =1 SNF	=2 为TNF          =3 SNF+TNF
	UCHAR bWidedynamic;		//宽动态功能，=0 为关闭           =1 为打开

	UCHAR WidedynamicRange; //宽动态范围     1-10
	UCHAR IntelNoiseLevel;  //智能降噪等级   10-13对应 自动、低、中、高
	UCHAR Blank1;
	UCHAR Blank2;
	UCHAR Out;        //本地输出     =10关闭，=11 NTSC =12 PAL

	UCHAR Noise;      //噪点    范围为1-100
	UCHAR ExposureBiasValue;//曝光补偿    范围为1-100
	UCHAR Blank3;

	UCHAR ImageFlip;  //图像翻转   =10为不翻转； =11为水平方向翻转   =12为垂直方式翻转；  =13为水平、垂直方向翻转
	UCHAR Blank4;

	UCHAR NightToDay_hour;	//黑白转彩色时间点
	UCHAR NightToDay_minute;
	UCHAR DayToNight_hour;	//彩色转黑白时间点
	UCHAR DayToNight_minute;

	UCHAR LevelToNight;     //=11 高电平转黑白  =12 低电平转黑白

	UCHAR Blank5[20];

}IPAC_DEV_VIDEOCFG, *LPIPAC_DEV_VIDEOCFG;


//告警信息
typedef struct AramInfo 
{
	BYTE bcameStat;
	BYTE bcamestat2;
	BYTE bAraminput;
	BYTE bAramoutput;//硬件告警
	BYTE bAram1;//软件告警信息
	BYTE bAram2;
}AramInfo;

/*
快门时间	ShutTime
1/50000	0
1/20000	1
1/10000	2
1/5000	3
1/2000	4
1/1000	5
1/500	6
1/250	7
1/200	8
1/125	9
1/100	10
1/50	11
1/25	12（默认）
1/20	13
1/15	14
1/13	15
1/10	16
1/5		17


*/

typedef struct {    // 设备高级图像参数  14
	UCHAR PriorMode;	//优先模式， =0 为速度优先；		=1 为质量优先
	UCHAR ShutTime;		//最大快门时间 ，具体定义参见表
	UCHAR MaxGain;		//最大增益，0-100
	UCHAR Blank1;

    UCHAR Light_control; //强光抑制
	UCHAR RangeWDR;		//宽动态范围，范围为1-10
	UCHAR nNoise;		//噪声，	范围为1-100
	UCHAR nEV;		    //EV补偿，范围为1-100

 	WORD Blank2;
	DWORD Blank3;

}IPAC_DEV_VIDEO2CFG, *LPIPAC_DEV_VIDEO2CFG;



typedef struct {    // 设备音频参数  12
	UCHAR audioON;	  //音频允许， =0 为关闭音频；	=1 为打开音频
	UCHAR audiomode;		//音频模式，=0 输入  =1 输出  =2输入和输出
	UCHAR audioinvolume;		//输入增益，0-100（85）
	UCHAR codectype;			//音频编码，1-G711, 2-AAC-LC）

    UCHAR samplerate; //采样频率，0-8Khz, 1-16Khz
	UCHAR bitrate;		//采样速率，0-64Kbps
	UCHAR audiooutvolume;		//输出音量，0-100（75）
	UCHAR alarmlevel;		    //告警音量，0-100（50）

 	WORD Blank1;
	WORD Blank2;

}IPAC_DEV_AUDIOCFG, *LPIPAC_DEV_AUDIOCF;


typedef struct {     // 设备工作模式  12  2.0-new-42
	UCHAR AFMinDist;    //AF最小距离  10-自动
	UCHAR AFMaxDist;    //AF最大距离  10-自动
	UCHAR AFWorkMode1;	//AF工作模式1 
	                    //BIT0=0为关闭；=1为启用自动对焦
	                    //BIT1=0为关闭；=1为球转动后强制对焦
	                    //BIT2=0为关闭；=1为调预置位后不对焦
	                    //BIT3=0为关闭；=1为巡航时不对焦
	                    //BIT7=0为关闭；=1为启用数字放大

	UCHAR AFWorkMode2;	//AF工作模式2
						//BIT0、1= 对焦灵敏度
						//BIT2 对焦窗口选择
						//BIT3 预置位调用方式
						//BIT4 对焦方式
						//BIT7 IR-CUT反转

	UCHAR BWSthPoint;	//彩色到黑白的切换点，范围为1-25
	UCHAR ClrSthPoint;	//黑白到彩色的切换点, 范围为5-35（其一定要大于Data5）
	DWORD IP;			//服务器IP地址
	WORD  port;			//服务器端口号

	UCHAR ControlMode;  //球机控制方式      10 自动  11 单串口控制模式  12 双串口控制模式
	UCHAR PTZCmdForward;//PTZ命令转发到球机 10 关闭  11 打开
	UCHAR SpecialPreset;//特殊预置位处理    10 默认  11 安信特

	UCHAR Blank1[4];

	UCHAR PWCutMemory;  //断电记忆 10关闭   11打开
	UCHAR PowerOnACT;   //上电动作 10关闭   11预置点  12 巡航
	UCHAR PowerOnACT2;  //预置点号 1-128（巡航时1-8）
	UCHAR LeisureACT;   //空闲动作 10关闭   11预置点  12 巡航
	UCHAR LeisureACT2;  //预置点号 1-128（巡航时1-8）

	UCHAR Blank[18];
}IPAC_DEV_SYSCFG, *LPIPAC_DEV_SYSCFG;



typedef struct {     // 设备时间设备  6
	UCHAR Second;		//秒数，正常范围为0-59
	UCHAR Minute;		 //分数，正常范围0-59			
	UCHAR Hour;			//时数，正常范围为0-23
	UCHAR Day;			//日数，范围01-31
	UCHAR Month;		//月份，范围从1-12
	UCHAR Year;			//年数，从1900 年算起至今的年数
}IPAC_DEV_TIMECFG, *LPIPAC_DEV_TIMECFG;



typedef struct {       //// 设备OSD   20
	UCHAR bShowTime;	//显示时间 =0 为不显示；=1 为显示
	UCHAR TimeFormat;	//显示时间格式, =0 为年/月/日  =1 为月/日/年 =2 为日/月/年			
	UCHAR bShowStr1;	//显示字符串1 =0 为不显示; =1 为显示
	UCHAR bShowRate;	//显示倍率, =0 为不显示;=1 为显示
	
	char str1[32];
	char str2[32];

	char time_show_pos;      //time位置   10-默认  11-左上  12-右上  13-左下   14-右下   15-自定义
	char time_show_pos_x;    //time位置自定义  x
	char time_show_pos_y;    //time位置自定义  y
	char time_show_color;    //time颜色

	char str1_show_pos;      //str1位置   10-默认  11-左上  12-右上  13-左下   14-右下   15-自定义
	char str1_show_pos_x;    //str1位置自定义  x
	char str1_show_pos_y;    //str1位置自定义  y
	char str1_show_color;    //str1颜色

	char rate_show_pos;      //rate位置   10-默认  11-左上  12-右上  13-左下   14-右下   15-自定义
	char rate_show_pos_x;    //rate位置自定义  x
	char rate_show_pos_y;    //rate位置自定义  y
	char rate_show_color;    //rate颜色

	char blank[16];
}IPAC_DEV_OSDCFG, *LPIPAC_DEV_OSDCFG;


/*
typedef struct {	// 设备ID   20

}IPAC_DEV_IDCFG, *LPIPAC_DEV_IDCFG;
*/

typedef struct{		// 摄像机录像格式   6
	UCHAR bStream;      //=0 视频流1；	=1 为视频流2 
	UCHAR Reserd[5];
}IPAC_DEV_RECORDTYPE, *LPIPAC_DEV_RECORDTYPE;

typedef struct{		// 摄像机录像命令  16
	UCHAR bRecord;      //是否保存录像到SD卡    =0 为不保存；		=1 为保存
	UCHAR RecordNo;		//计划号范围从0-6
	UCHAR RecordPloy;   // 录像策略，=0 不录像；  =1为按计划录像，
	UCHAR RecordWeek;	//开始日期
	UCHAR beginHour;	//开始小时
	UCHAR beginMinute;	//开始分钟
	UCHAR beginSecond;	//开始秒数
	UCHAR endHour;
	UCHAR endMinute;
	UCHAR endSecond;
	UCHAR Reserd[6];
}IPAC_DEV_RECORDCFG, *LPIPAC_DEV_RECORDCFG;


typedef struct {	//ftp服务器 , 50
	DWORD IP;			//IP地址，高位在前
	WORD  Port;			//端口号，高位在前
	char  user[6];		//用户名，高位在前
	char  Pwd[6];		//密码，高位在前
	UCHAR Reserd[2];

	char  sntp[30];    // SNTP 服务器地址，高位在前
}IPAC_DEV_FTPCFG;



typedef struct {	// 告警参数  40
    UCHAR IO_InAlarm;        //IO_IN告警配置 10-关闭  11-打开
    UCHAR IO_InTriggerLevel; //IO_IN触发电平 10-低电平触发 11-高电平触发
    UCHAR VideoLose;         //视频丢失   =10不报警； =11为报警
    UCHAR NetLose;           //网络掉线   =10不报警； =11为报警
    UCHAR MotionDetection;   //移动侦测   =10不报警； =11为报警
    UCHAR IO_OutAlarm;       //IO告警输出 =10为关闭； =11为打开
    UCHAR IO_OutTriggerLevel;//IO_OUT 0-告警输出低电平 1告警输出高电平
    UCHAR OutputDelay;       //输出延时 10-5S 11-10S 12-30S 13-1M 14-5M 15=10M 16=一直
    UCHAR AlarmSound;        //告警发声 10关闭，11打开
    UCHAR AlarmSave;         //告警存储 10关闭，11打开
    UCHAR AlarmSaveToFtp;    //告警FTP  10关闭，11打开
    UCHAR AlarmSaveToSMTP;   //告警SMTP 10关闭，11打开
    UCHAR AlarmPreset;       //告警预置点 10关闭，11打开
    UCHAR AlarmPresetNumber; //预置点号
    UCHAR AlarmCruise;       //告警巡航 10关闭，11打开
    UCHAR AlarmCruiseNumber; //巡航线路

	UCHAR Blank[24];
}IPAC_DEV_ALARMCFG, *LPIPAC_DEV_ALARMCFG;


typedef struct {	// PTZ参数  12
	UCHAR bNum;  // 串口号 10.串口0   1.串口1   默认：串口1
	UCHAR Baud;   // 串口波特率 //115200 =10  57600 =9   38400=8,  19200=7,  9600=6, 4800=5, 2400 =4, 1200 = 3,  600=2  300=1
	UCHAR Begin;  // 串口起始位数
	UCHAR End;	 //  串口停止位数  //0-1, 1-1.5 , 2-2
	UCHAR Check;		// 	串口校验      //0-none ,1-odd , 2-even
	UCHAR Data;		//  串口数据位数  //5-8
	UCHAR qj_add;	//  球机地址
	UCHAR Protocol1; // 球机协议
	UCHAR Protocol2; // 球机扩展协议

	UCHAR Reserd[3];

	UCHAR Num0Mode;  //串口0工作模式   10-默认
	UCHAR Num0Protocol; //串口0协议    10-SONY协议
	UCHAR Num0Baud;     //串口0波特率  115200 =19  57600 =18   38400=17,  19200=16,  9600=15, 4800=14, 2400 =13, 1200 = 12,  600=11  300=10
	UCHAR Num0Begin;    //串口0起始位数
	UCHAR Num0End;      //串口0停止位数  //0-1, 1-1.5 , 2-2
	UCHAR Num0Check;    //串口0校验      //0-none ,1-odd , 2-even
	UCHAR Num0Data;     //串口0数据位数  //5-8
	UCHAR Num0Blank;
	UCHAR Blank[12];
}IPAC_DEV_PTZCFG, *LPIPAC_DEV_PTZCFG;



typedef struct {	// SD参数
	UCHAR DATA1;		//
	UCHAR DATA2;		//
	UCHAR DATA3[4];
}IPAC_DEV_SDCFG, *LPIPAC_DEV_SDCFG;

typedef struct {    // SD操作参数
	UCHAR Order;
	UCHAR Blank[63];
}IPAC_DEV_SDOPERATE, *LPIPAC_DEV_SDOPERATE;

typedef struct {   //SD卡文件列表
	char FileName[50]; // 文件名
	char FileDate[15]; // 日期
	char FileTime[10]; // 时间
	char FileSize[20]; // 大小

}IPAC_DEV_SDFILEINFO, *LPIPAC_DEV_SDFILEINFO;

typedef struct {	// 获取SD卡信息
	BYTE State;		// =0没有SD卡，=1为已插入，=2为已挂载，=3为已插入并挂载
	BYTE Usage;		// 利用率0-100
	WORD Capacity;	// 容量
	BYTE FileCount; // 文件数量,IPAC_DEV_SDFILEINFO结构

}IPAC_DEV_SDCARDINFO, *LPIPAC_DEV_SDCARDINFO;



typedef struct{  // 软件升级命令
	UCHAR Command1;
	UCHAR Command2;
	WORD Command3;
}IPAC_DEV_UPDATE, *LPIPAC_DEV_UPDATE;



typedef struct{		//云台巡航设置数据 
	UCHAR	Cmd;		//Cmd:  30-将预置点加入巡航序列, 44-删指定的巡航路线,33-将预置点从巡航序列中删除,  37-开始巡航, 38-停止巡航
	UCHAR	nLine;		//nLine: 巡航线路 1-8
	UCHAR	nPoint;		//nPoint: 巡航点  1-16
	UCHAR	nPreset;	//nPreset: 相应的预置点 1-127
	UCHAR	nSpeed;     //nSpeed:  速度  1-8
	UCHAR	nTime;		//nTime:   时间  1-255
}IPAC_DEV_CRUISE, *LPIPAC_DEV_CRUISE;


typedef struct{		//请求镜头初始化数据
	UCHAR	bZoomInit;	//Zomm: 0 为不初始化；1 为初始化
	UCHAR	nZoomType;	//Zoom: 1 为回零点； 2 为回最小ZOOM
	UCHAR	bAFInit;	//AF: 0 为不初始化；1 为初始化
	UCHAR	nAFType;	//AF初始化类型，=1 为回零点； =2 为回最小AF
}IPAC_DEV_LENSINIT;



typedef struct{		//回应镜头数据
	UCHAR	bOK;		//完成状态 =0成功；	=1 出错
	WORD	nZoomPos;	//ZOOM当前位置
	WORD	nFocalPos;	//AF当前位置
	UCHAR	nZSection;	//ZOOM当前位置的段数
	UCHAR	aperPos:4;	//BIT4-1镜头当前光圈位置，
	UCHAR	nighPos:4;	//BIT8-5镜头当前日夜位置
	UCHAR	state;		//镜头状态 >0 时出错
}IPAC_DEV_LENSRESP;


typedef struct{		//请求自动对焦数据
	UCHAR	nType;		//设置类型，1-5为指定光圈当前打开的大小，0x10为调试
	UCHAR	nHValue;
	UCHAR	nLValue;		//调试数据
}IPAC_DEV_LENSREQU;



//摄像头设置日夜模式
typedef struct{
	UCHAR  FilterMode;
	UCHAR  Reversed;
	UCHAR  ImageColor;
}IPAC_DEV_LENSIRCTU;




typedef struct {	//搜索回应包 , 64+30

	DWORD IP;			//IP地址，高位在前
	DWORD Mask;			//网络掩码，高位在前
	DWORD Gateway;		//网关地址，高位在前
	UCHAR MAC[6];		 //MAC地址，
	BYTE  sDEVName[NAME_LEN];     //设备名称
	DWORD dDEVType ;              //设备类型	
	BYTE  sDEVNO[SERIALNO_LEN];   //序列号
	DWORD dAppVersion ;           //应用版本
	DWORD dRunTime ;
	WORD  dPort;

	WORD  dVideoPort;	//
	BYTE  sBlank1[4];
	char  sDEVTypeEx[16];
	BYTE  sBlank2[8];
	
}IPAC_DEV_SEARCH;

#define MAX_CRUISE_POINT 16

typedef struct _CruisePoint
{
	BYTE Flag; //1 yes 0 no
	BYTE PresetNum;
	BYTE speed	;
	BYTE Time;
}tagCruisePoint;


typedef struct _tagCruiseGroup
{
	BYTE Flag;  //0
	BYTE Blank1; 
	tagCruisePoint stPoint[MAX_CRUISE_POINT];
}tagCruiseGroup;

typedef struct _tagBroadcaseChange
{
	DWORD dwDevIP;
	DWORD dwDevMask;
	DWORD dwGateway;
	DWORD dwDomainServer;
	WORD  httpPort;
	WORD  httpsPort;
	UCHAR szDevMAC[6];
	BYTE  byDHCP;

	char szRes[3];
	DWORD dwUpDevType;//原有信息
	BYTE  byUpDevNo[16];
	DWORD dwUpDevIP;
	UCHAR szUpDevMAC[6];
	WORD  szRevPort;
}tagBroadcaseChange;  

#pragma pack()
//==================================================================================================================================frank 


//实时预览参数结构
typedef struct{ 
	LONG    lChannel;   //1为主码流，2为子码流
	LONG    lLinkMode;  // 连接方式：0－TCP方式；1－UDP方式；2－多播方式；3－RTP方式
	HWND    hPlayWnd;   //播放窗体
    char    *sMultiCastIP;
	WORD    nVideoPort; //为0使用默认， 连接方式为TCP或UDP时有效
} IPAC_DEV_CLIENTINFO, *LPIPAC_DEV_CLIENTINFO;


//云台图象区域位置信息
typedef struct{
  int    xTop;
  int    yTop;
  int    xBottom;
  int    yBottom;
  int    bCounter;
} IPAC_DEV_POINT_FRAME, *LPIPAC_DEV_POINT_FRAME;


//移动侦测参数
typedef struct{
	UCHAR bOpen;		//是否开启
	UCHAR Sensitivity;	//灵敏度选择（0.按等级  1.按细分）
	UCHAR Rank;			//灵敏度等级
	UCHAR Subdivs;	//细分灵敏度
			

	UCHAR sBlock[8];	//宏块配置（每个字节对应一行宏块，每个位对应一个宏块）=1 开启， =0 关闭
						//现在只支持3行4列的配置
	UCHAR Blank[38];
} IPAC_DEV_VMDCFG, *LPIPAC_DEV_VMDCFG;

//设备网络扩展信息
typedef struct{
	WORD  ContorlPort; //控制端口
	UCHAR bCheck;      //RTSP访问是否需要认证 10-不需要，11-需要
	UCHAR PacketSize;  //RTSP访问包大小， 10-小包，11-大包
	UCHAR URL;	       //访问URL， 10-WWA,11-WWA1,12-HK,13-UC
	UCHAR Mode;        //RTSP组播模式 10-单播， 11 组播
	UCHAR NvrVendor;        //NVR厂商 10-默认，11-海康，12-大华，13天地伟业，14-汉邦高科，15-雄迈，16-中维
	UCHAR Blank[3];

	UCHAR bUPNP;       //UPNP配置 10-关闭，11-打开
	UCHAR Blank2[9];

	UCHAR bADSL;       //ADSL配置 10-关闭，11-打开
	UCHAR Blank3;
	char  Username[16];	//用户名
	char  Password[16];	//密码 
	UCHAR Blank4[6];

	UCHAR bSNTP;        //SNTP配置 10-关闭，11-打开
	UCHAR Blank5;
	char  SNTPServerAddr[32];  //服务器地址
	WORD  SNTPServerPort;	   //端口
	UCHAR SNTPTimingInterval;  //校时间隔
	UCHAR Blank6[3];

	UCHAR bSMTP;               //SMTP配置 10-关闭，11-打开
	UCHAR Blank7;
	char  SMTPServerAddr[32];  //服务器地址
	char  SMTPSenderAddr[32];  //寄件人地址
	char  SMTPRecverAddr[32];  //收件人地址
	char  SMTPUsername[16];    //用户名
	char  SMTPPassword[16];	   //密码

	UCHAR Blank8[282];
}IPAC_DEV_NETCFGEX, *LPIPAC_DEV_NETCFGEX;


//P2P服务器信息
typedef struct{
	UCHAR Vender;
	UCHAR bOpen;

	char ServerAddr1[40];
	char ServerAddr2[40];
	char UserName[16];
	char Password[16];

	UCHAR ID[20];
	WORD  wPort;

	UCHAR Blank2[32];
}IPAC_DEV_P2PCFG, *LPIPAC_DEV_P2PCFG;

typedef struct
{
	BYTE Order;				//=1 开始对讲， =2 结束对讲，=3控制
	BYTE VoiceFormat;		//=1 wav， =2 G711
	BYTE MainDevType;		//=1 PC, =2 NVR, =3手机
	BYTE Protocol;			//=1  TCP,  =2 UDP

	UINT nSamplesPerSec;	//取样率
	UINT nBitsPerSample;	//取样位数
	WORD wPort;				//端口号

	WORD wBlank;
}IPAC_DEV_VOICECOMCFG, *LPIPAC_DEV_VOICECOMCFG;

//DDNS服务器信息
typedef struct{
	BYTE bOpen;
	BYTE bUpdateInterval;
	BYTE bBlank1;
	BYTE bBlank2;

	char DDNSAddr[32];
	char UserName[16];
	char Password[16];
	
	char Blank[444];
}IPAC_DEV_DDNSCFG, *LPIPAC_DEV_DDNSCFG;


//28181  byte:320
typedef struct{
	BYTE Open; //10-关闭，11-打开
	BYTE Stream;//10-主码流, 11-次码流

	char sServerIP[32]; //服务器IP
	char wServerPort[2];   //服务器端口
	char sServerID[32]; //服务器ID

	char sRegisterDomain[32]; //注册域
	char sUsername[32];       //用户名
	char sPassword[32];       //密码
	WORD wRegisterWaitTime;   //注册超时（s）
	WORD wHeartbeatCycle;     //心跳周期（s）
	char sBlank[31];

	char sDevID[32];		  //设备ID
	char wDevPort[2];			  //设备端口
	char sAlarmID[32];		  //报警端口

	char sBlank2[55];
}IPAC_DEV_28181CFG, *LPIPAC_DEV_28181CFG;

//预置点名称   byte:40
typedef struct  
{
	BYTE Order;			//1.读取  2.设置
	BYTE PresetPoint;	//预置点
	char Blank[8];

	char Name[20];		//预置点名称
	char Blank2[10];
}IPAC_DEV_PRESETPOINT_NAMECFG, *LPIPAC_DEV_PRESETPOINT_NAMECFG;

//云台高级控制命令  byte:30
typedef struct
{
	BYTE MainOrder;	//主命令
	BYTE SubOrder;	//子命令
	BYTE Speed;		//速度 取值范围[1,8]
	BYTE Blank;

	BYTE PresetPoint1;	//预置点
	BYTE Order1;		//10-调用，11-设置
	BYTE PresetPoint2;	//预置点2
	BYTE Order2;		//10-调用，11-设置

	BYTE Blank2[22];
}IPAC_DEV_PTZ_HIGHERCFG, *LPIPAC_DEV_PTZ_HIGHERCFG;
/*
详细命令定义如下
	10 显示时间
	11 不显示时间
	12 显示倍率
	13 不显示倍率
	25 单串口模式
	26 双串口模式
	30 镜头初始化
	31 清除预置点
	32 机芯恢复出厂设置
	33
	34 机芯重启
	50 线扫开
	51 线扫关
	52 线扫起点
	53 线扫终点
	55 灯光强
	56 灯光中
	57 灯光弱
	60 雨刷开
	61 雨刷关
	70 彩色黑白自动
	71 彩色模式
	72 黑白模式
*/

typedef struct
{
	char  ssid[32]; //ssid 
	char  pwd[32];	//已保存密码
//64
	unsigned short speed;    //速率
	unsigned char  wm; 		//工作模式01: manage， 02: ad-hoc
	unsigned char  sm;	    //安全模式 01：不加密 02：wep,  03:  wpa-psk  04: wpa-enterprise , 05: wpa2-psk 06: wpa2-enterprise
	unsigned char  cid;      //通道号
	unsigned char  strength; //信号强度
	short  rev;
//72
}IPAC_DEV_WIFI_INFO, *LPIPAC_DEV_WIFI_INFO;

typedef struct
{
	char open;		//wifi开关  10.关  11.开
	char dhcp;
	char wifi_count;	//可用的wifi数量
	char connect;	//wifi连接状态  10.未连接  11.已连接

	unsigned int ip;
	unsigned int mask;
	unsigned int gateway;
	unsigned int dns;
	
	unsigned char mac[6];
	char blank3[2];

	IPAC_DEV_WIFI_INFO info1; //已连接的wifi

	IPAC_DEV_WIFI_INFO info2[20]; //wifi列表
}IPAC_DEV_WIFI_GET, *LPIPAC_DEV_WIFI_GET;

typedef struct//180
{
	char open;		//wifi开关   10.关  11.开
	char dhcp;
	char blank1[2];

	unsigned int ip;
	unsigned int mask;
	unsigned int gateway;
	unsigned int dns;
	char blank2[8];

	IPAC_DEV_WIFI_INFO info1;	//连接的wifi

	char blank3[80];
}IPAC_DEV_WIFI_SET, *LPIPAC_DEV_WIFI_SET;


//--------------------------------------------------------------- 初始化SDK，调用其他SDK函数的前提   
/*
//TRUE表示成功，FALSE表示失败
*/
IPAC_API  BOOL   WINAPI IPAC_DEV_Init();
IPAC_API  BOOL   WINAPI IPAC_DEV_Cleanup();


//----------------------------------------------------------------  用户注册设备
/*
Parameters
sDVRIP 
[in] 设备IP地址 
wServerPort 
[in] 设备端口号 
sUserName 
[in] 登录的用户名 
sPassword 
[in] 用户密码 
lpDeviceInfo 
[out] 设备信息 
*/
IPAC_API  ULONG  WINAPI  IPAC_DEV_Login(const char *ip_addr, int port, const char *user_name, const char *user_pwd, UCHAR bRelay);
IPAC_API  BOOL   WINAPI  IPAC_DEV_Logout(ULONG    lUserID);

//--------------------------------------------------------------  异常信息回调
typedef BOOL (WINAPI *MESSAGE_CALLBACK)(int nType,void *pParam,int nLen,void *context);
typedef BOOL (WINAPI *STREAM_CALLBACK)(LONG lRealHandle,DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser);
typedef BOOL (WINAPI *CHANNEL_STREAM_CALLBACK)(LONG lRealHandle,DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser);

typedef struct _RtspRealStream
{
	DWORD dwPort;
	char  szDevIp[32];
	char  szDevUserName[32];
	char  szDevPwd[32];
	char  szRtspPath[MAX_PATH];
	STREAM_CALLBACK pCallback;
}RtspRealStream;

//---------------------------------------------------------------   实时预览
/*
//typedef void(*fRealDataCallBack_V30)(  LONG     lRealHandle,  DWORD    dwDataType,  BYTE      *pBuffer,  DWORD     dwBufSize,  void      *pUser);
/* 实时预览。
Parameters
lUserID 
[in] IPAC_DEV_Login的返回值 
lpClientInfo 
[in] 预览参数 
cbRealDataCallBack 
[in] 码流数据回调函数 
pUser 
[in] 用户数据 
bBlocked 
[in] 请求码流过程是否阻塞：0－否；1－是 
*/

IPAC_API LONG  WINAPI IPAC_DEV_RealRtsp(RtspRealStream stRtspStream,void  *pUser);

IPAC_API LONG  WINAPI IPAC_DEV_RealPlay(ULONG UserID, LPIPAC_DEV_CLIENTINFO lpClientInfo, STREAM_CALLBACK callback, void  *pUser, BOOL  bBlocked);
//  lRealHandle    IPAC_DEV_RealPlay的返回值 
IPAC_API BOOL  WINAPI IPAC_DEV_StopRealPlay( LONG    lRealHandle);

IPAC_API BOOL  WINAPI IPAC_DEV_ClientGetVideoEffect(LONG   lRealHandle,  DWORD  *pBrightValue,  DWORD  *pContrastValue,  DWORD   *pSaturationValue,  DWORD   *pHueValue);
IPAC_API BOOL  WINAPI IPAC_DEV_ClientSetVideoEffect(LONG   lRealHandle,  DWORD   dwBrightValue, DWORD   dwContrastValue, DWORD    dwSaturationValue, DWORD    dwHueValue);

IPAC_API BOOL  WINAPI IPAC_DEV_OpenSound( LONG  lLoginID, LONG lVolume);
IPAC_API BOOL  WINAPI IPAC_DEV_CloseSound( LONG  lLoginID);

//IPAC_API BOOL IPAC_DEV_SaveRealData(  LONG    lRealHandle,  char    *sFileName);
// IPAC_API BOOL IPAC_DEV_StopSaveRealData( LONG  lRealHandle);

IPAC_API ULONG WINAPI  IPAC_DEV_GetDecoderHandle( LONG    lRealHandle);
IPAC_API BOOL  WINAPI  IPAC_DEV_CapturePicture(LONG  lRealHandle,  char *sPicFileName);

IPAC_API BOOL  WINAPI IPAC_DEV_StartRecord(ULONG lRealHandle,const char *csFileName);
IPAC_API BOOL  WINAPI IPAC_DEV_StopRecord(ULONG lRealHandle);

IPAC_API BOOL  WINAPI IPAC_DEV_CheckPlayStatus(ULONG lRealHandle);


//--------------------------------------------------------  PTZ控制
/*
lUserID 
[in] IPAC_DEV_Login的返回值 
dwPTZCommand 
[in] 云台控制命令，见下表： 
ZOOM_IN 11 焦距变大(倍率变大) 
ZOOM_OUT 12 焦距变小(倍率变小) 
FOCUS_NEAR 13 焦点前调 
FOCUS_FAR 14 焦点后调 
IRIS_OPEN 15 光圈扩大 
IRIS_CLOSE 16 光圈缩小 
TILT_UP 21 云台上仰 
TILT_DOWN 22 云台下俯 
PAN_LEFT 23 云台左转 
PAN_RIGHT 24 云台右转 
UP_LEFT 25 云台上仰和左转 
UP_RIGHT 26 云台上仰和右转 
DOWN_LEFT 27 云台下俯和左转 
DOWN_RIGHT 28 云台下俯和右转 
PAN_AUTO 29 云台左右自动扫描 
dwStop 
[in] 云台停止动作或开始动作：0－开始；1－停止 
dwSpeed 
[in] 云台控制的速度，用户按不同解码器的速度控制值设置。取值范围[1,7] 
*/
IPAC_API BOOL  WINAPI IPAC_DEV_PTZControlWithSpeed_Other( LONG   lUserID,  DWORD   dwPTZCommand,  DWORD   dwStop,  DWORD    dwSpeed);

/*
lUserID 
[in] IPAC_DEV_Login的返回值 
dwPTZPresetCmd 
[in] 操作云台预置点命令，见下表： 宏定义 宏定义值 含义 
SET_PRESET 8 设置预置点 
CLE_PRESET 9 清除预置点 
GOTO_PRESET 39 转到预置点 

dwPresetIndex 
[in] 预置点的序号（从1开始），最多支持255个预置点 
*/
IPAC_API BOOL  WINAPI IPAC_DEV_PTZPreset_Other(  LONG     lUserID,  DWORD    dwPTZPresetCmd,  DWORD    dwPresetIndex);



/*  ---- 云台巡航设置
lUserID 
[in] IPAC_DEV_Login的返回值 
lChannel 
[in] 通道号 
pPTZCodeBuf 
[in] 存放云台巡航设置数据 
dwBufSize 
[in]云台巡航设置数据的长度 
*/
IPAC_API BOOL  WINAPI IPAC_DVR_PTZCruise(   LONG   lUserID,  LONG     lChannel,  IPAC_DEV_CRUISE    *pPTZCodeBuf,  DWORD    dwBufSize);

/*
lUserID 
[in] IPAC_DEV_Login的返回值 
lChannel 
[in] 通道号 
pPTZCodeBuf 
[in] 存放云台控制码缓冲区的指针 
dwBufSize 
[in] 云台控制码的长度 
*/
IPAC_API BOOL  WINAPI IPAC_DEV_TransPTZ_Other(  LONG     lUserID,  LONG     lChannel,  char     *pPTZCodeBuf,  DWORD    dwBufSize);
/*
lUserID 
[in] IPAC_DEV_Login的返回值 
lChannel 
[in] 通道号 
pPTZCodeBuf 
[in] pStruPointFrame 
选择图像区域位置信息
*/
IPAC_API BOOL  WINAPI IPAC_DEV_PTZSelZoomIn(  LONG     lUserID,  LONG     lChannel,  LPIPAC_DEV_POINT_FRAME     pStruPointFrame);

/*
获取和设置预置点名称
lLoginID 
[in] IPAC_DEV_Login的返回值 
lChannel 
[in] 通道号 
info
[in] 信息
[out]接收缓冲区 (21*48) 
struct{
	BYTE number;
	char name[20];
}
*/
IPAC_API BOOL  WINAPI IPAC_DEV_PTZ_PresetPointName(LONG lLoginID, LONG lChannel, IPAC_DEV_PRESETPOINT_NAMECFG info, char *RevBuffer, short* pSize);

IPAC_API BOOL  WINAPI IPAC_DEV_PTZ_Config(LONG lLoginID, DWORD dwPTZCmd, LONG lChannel, void *SendBuffer, short SendSize, void *RevBuffer, short RevSize);

//---------------------------------------------------------通用参数设置
/*
Parameters
lUserID 
[in] NET_DVR_Login或NET_DVR_Login_V30的返回值 
dwCommand 
[in] 设备配置命令，参见配置命令 
lChannel 
[in] 通道号，如果命令不需要通道号，该参数无效，置为0xFFFFFFFF即可 
lpOutBuffer 
[out] 接收数据的缓冲指针 
dwOutBufferSize 
[in] 接收数据的缓冲长度(以字节为单位)，不能为0 
lpBytesReturned 
[out] 实际收到的数据长度指针，不能为NULL 
*/
IPAC_API BOOL  WINAPI IPAC_DEV_GetConfig(  LONG     lUserID,  DWORD    dwCommand,  LONG     lChannel,  LPVOID   lpOutBuffer,  DWORD    dwOutBufferSize,  LPDWORD  lpBytesReturned);
/*
Parameters
lUserID 
[in] NET_DVR_Login或NET_DVR_Login_V30的返回值 
dwCommand 
[in] 设备配置命令，参见配置命令 
lChannel 
[in] 通道号，如果命令不需要通道号，该参数无效，置为0xFFFFFFFF即可 
lpInBuffer 
[in] 输入数据的缓冲指针 
dwOutBufferSize 
[in] 输入数据的缓冲长度(以字节为单位) 
*/
IPAC_API BOOL  WINAPI IPAC_DEV_SetConfig(  LONG     lUserID,  DWORD    dwCommand,  LONG     lChannel,  LPVOID   lpInBuffer,  DWORD    dwInBufferSize);


//---------------------------------------------------------  维护命令
IPAC_API BOOL  WINAPI IPAC_DEV_RestoreConfig(  LONG    lUserID, LONG lType=1);// 1 完全  2 普通恢复（保留ip）  3 删除配置文件

IPAC_API BOOL  WINAPI IPAC_DEV_Reboot(  LONG   lUserID);

IPAC_API BOOL  WINAPI IPAC_DEV_GetConfigFile(  LONG    lUserID,  char    *sOutBuffer,  DWORD   dwOutSize,  DWORD   *pReturnSize);

IPAC_API BOOL  WINAPI IPAC_DEV_SetConfigFile(  LONG    lUserID,  char    *sInBuffer,  DWORD   dwInSize);

IPAC_API BOOL  WINAPI IPAC_DEV_SDOperate( LONG    lUserID, char    *sInBuffer ,char    *sOutBuffer);

enum
{
	SDRead_State=1,
	SDRead_FileList=2,
};
IPAC_API BOOL  WINAPI IPAC_DEV_SDRead( LONG    lUserID, char    *sInBuffer ,char    *sOutBuffer);
IPAC_API BOOL  WINAPI IPAC_DEV_SDReadFileList(ULONG lUserID, char* sInBuffer,char* sOutBuffer, LONG lSDFileCount);

IPAC_API BOOL  WINAPI IPAC_DEV_Update( LONG    lUserID ,char    *sInBuffer,  char    *sOutBuffer);

IPAC_API BOOL  WINAPI IPAC_DEV_GetCruisePoint( LONG    lUserID ,char    *sInBuffer,  char    *sOutBuffer, DWORD dwInSize);


IPAC_API BOOL  WINAPI IPAC_DEV_setMessageCallback(LONG    lUserID, MESSAGE_CALLBACK callback, void *pContext);


IPAC_API BOOL  WINAPI IPAC_DEV_GetAlmData(LONG lUserID,char    *sOutBuffer);

IPAC_API DWORD  WINAPI IPAC_DEV_GetNetVersion(long lLoginID);
//---------------------------------------------------------  设置镜头
IPAC_API BOOL  WINAPI IPAC_DEV_GetLensStatus( LONG    lUserID, IPAC_DEV_LENSRESP* pStatus, SHORT Channel);
IPAC_API BOOL  WINAPI IPAC_DEV_SetLensInit( LONG    lUserID, IPAC_DEV_LENSINIT* pInit, IPAC_DEV_LENSRESP *pGetInit, SHORT Channel);
IPAC_API BOOL  WINAPI IPAC_DEV_SetLensZoom( LONG    lUserIDn, SHORT nValue, SHORT Channel);
IPAC_API BOOL  WINAPI IPAC_DEV_GetStreamInfo( LONG    lUserIDn, int *nWidth, int *nHeight);

//---------------------------------------------------------  设备搜索
typedef INT	(WINAPI *SearchHookFunc)(IPAC_DEV_SEARCH* pSearchData, void *pParam);
IPAC_API DWORD  WINAPI IPAC_DEV_SearchDevice(SearchHookFunc Func, void* pParam, int nType);

//---------------------------------------------------------- 透明传输
enum SERIAL_TYPE
{
	RS232 = 0,
	RS485 = 1,
};

typedef void (WINAPI *fTransComCallBack) (long lLoginID, SERIAL_TYPE lTransComType, char *pBuffer, unsigned long dwBufSize, unsigned long dwUser);

IPAC_API BOOL  WINAPI IPAC_DEV_OpenTransComChannel(long lLoginID, fTransComCallBack cbTransCom, unsigned long lUser, SERIAL_TYPE nType=RS232);

IPAC_API BOOL  WINAPI IPAC_DEV_CloseTransComChannel(long lLoginID, SERIAL_TYPE nType);

IPAC_API BOOL  WINAPI IPAC_DEV_SerialWrite(long lLoginID, SERIAL_TYPE nType, char *pBuffer, int nBufLen);

IPAC_API BOOL  WINAPI IPAC_DEV_SerialRead(long lLoginID, SERIAL_TYPE nType, char *pBuffer, int nBufLen, int *pReadLen);

//-------------------------------------------------------广播修改
IPAC_API DWORD  WINAPI IPAC_DEV_BroadcaseChangeIP(tagBroadcaseChange stDevInfo);

//---------------------------------------------------------  SDK信息
IPAC_API DWORD  WINAPI IPAC_DEV_SetWriteLog(BOOL bflag);

IPAC_API DWORD  WINAPI IPAC_DEV_GetSDKVersion();
IPAC_API DWORD  WINAPI IPAC_DEV_GetLastError();


//----------------------------------------------------------设备升级
/*
nType	升级状态
nInfo	详细信息（进度）
lpUser  用户参数
*/
typedef DWORD (WINAPI *DevUpFunc)(unsigned int nType, unsigned int nInfo, void* pUser);
/*
lLoginID
[in] 登录ID
szFileName
[in] 升级文件的完整路径
Func
[in] 升级状态回调函数
lpUser
[in] 回调函数参数
lSpeed
[in] 速度 0无限制 其他为带宽（Kb/s）（主要在远程升级使用）
*/
IPAC_API BOOL  WINAPI IPAC_DEV_StartDevUp(long lLoginID, const char* szFileName, DevUpFunc Func, LPVOID lpUser, ULONG lSpeed=0);


//---------------------------------------------------------设置告警信息回调
enum{
	Alarm_NOT_ONLINE	=0,				//设备不在线
	Alarm_ONLINE		=1,				//设备在线
	Alarm_Device		=2,				//设备报警
};
// typedef struct  
// {
// 	BYTE btDevState1;
// 	BYTE btDevState2;
// 	BYTE btAlarmIn;
// 	BYTE btAlarmOut;
// 	BYTE btAlarmState;
// 
// 	BYTE btBlank1;
// 	BYTE btBlank2;
// 	BYTE btBlank3;
// }IPAC_AlarmInfo, *LPIPAC_AlarmInfo;

typedef struct  
{
	BYTE bMainboard;	//= 1 为摄像主板有故障
	BYTE bFLASH;		//= 1 为FLASH有故障
	BYTE bEEPROM;		//= 1 为EEPROM有故障
	BYTE bNET;			//= 1 为网络有故障
	BYTE bIC;			//= 1 为电机驱动IC有故障
	BYTE bSENSOR;		//= 1 为没有发现SENSOR
	BYTE bSENSORImage;	//= 1 为没有SENSOR图像
	BYTE bZOOM;			//= 1 为镜头ZOOM出错
	BYTE bAF;			//= 1 为镜头AF出错
	BYTE bAperture;		//= 1 为镜头光圈出错
	BYTE bDayNight;		//= 1 为镜头日夜出错
	BYTE bIOIn;			//    告警输入状态
	BYTE bIOOut;		//    告警输出状态
	BYTE bVMD;			//= 1 为有移动侦测告警
	BYTE bIOInState;	//= 1 IO输入告警
	BYTE bNetOut;       //= 1 网络断线
	BYTE bVideoLose;	//= 1 视频丢失
 	BYTE bVideoShield;	//= 1 视频遮挡

	BYTE bBlank1;
	BYTE bBlank2;
	BYTE bBlank3;
	BYTE bBlank4;
}AlarmInfoEX;

/*
	lLoginID: 设备登陆ID
	lAlarmCode: 报警类型
	pInfo: 报警信息
	pUser: 用户参数
*/
typedef void (WINAPI *AlarmCallFunc)(LONG lLoginID, LONG lAlarmCode, void* pInfo, void* pUser);

/*
	设置全局的报警信息回调
	func: 回调函数
	pUser: 用户参数，回调函数最后一个参数
*/
IPAC_API BOOL  WINAPI IPAC_DEV_SetAlarmMessageCallback(AlarmCallFunc func,void* pUser);

/*
	监听设备的报警信息
	lLoginID: 设备登陆ID
*/
IPAC_API BOOL  WINAPI IPAC_DEV_SetListenDevAlarm(LONG lLoginID,BOOL bListen);



typedef void (CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle,char *pRecvDataBuffer,DWORD dwBufSize,BYTE byAudioFlag,void *pUser);
/*
[out] lVoiceComHandle   IPAC_DEV_StartVoiceCom 的返回值
[out] pRecvDataBuffer   存放音频数据的缓冲区指针
[out] dwBufSize         音频数据大小
[out] byAudioFlag       音频数据类型：0-  本地采集的数据，1-  设备发送过来的语音数据
[out] pUser             用户数据指针
*/

IPAC_API LONG  WINAPI IPAC_DEV_StartVoiceCom(LONG lLoginID, DWORD dwVoiceChan, BOOL bNeedCBNoEncData, fVoiceDataCallBack cbVoiceDataCallBack, void* pUser);
/*
[in]  lUserID					IPAC_DEV_Login 的返回值
[in]  dwVoiceChan				语音通道号，从 1 开始
[in]  bNeedCBNoEncData		需要回调的语音数据类型：0-  编码后的语音数据，1-  编码前的
[in]  cbVoiceDataCallBackPCM	原始数据音频数据回调函数
[in]  pUser					 用户数据指针
*/

IPAC_API BOOL  WINAPI IPAC_DEV_SetVoiceComClientVolume(LONG lVoiceComHandle, WORD wVolume);
/*
[in]  lVoiceComHandle  IPAC_DEV_StartVoiceCom 的返回值
[in]  wVolume			 设置音量，取值范围[0,0xffff] 
*/



IPAC_API BOOL  WINAPI IPAC_DEV_StopVoiceCom(LONG lVoiceComHandle);
/*
[in]  lVoiceComHandle  IPAC_DEV_StartVoiceCom 的返回值
*/
// typedef void (CALLBACK *fVoiceDataCallBack)(char *pRecvDataBuffer,DWORD dwBufSize, void *pUser);
// /*
// [out]pRecvDataBuffer 存放 PC 本地采集的音频数据（PCM）的缓冲区指针
// [out]dwBufSize       音频数据大小
// [out]pUser           用户数据指针
// */
IPAC_API BOOL  WINAPI IPAC_DEV_ClientAudioStart(fVoiceDataCallBack cbVoiceDataCallBack, void *pUser);
/*
开始捕获声音
*/

IPAC_API LONG  WINAPI IPAC_DEV_AddDEV(LONG lLoginID, DWORD dwVoiceChan);
/*
[in]lLoginID      IPAC_DEV_Login 的返回值
[in]dwVoiceChan   语音通道号，从 1 开始
*/

IPAC_API LONG  WINAPI IPAC_DEV_DelDEV(LONG lLoginID);
/*
[in]lLoginID      IPAC_DEV_Login 的返回值
*/

IPAC_API BOOL  WINAPI IPAC_DEV_ClientAudioStop();
/*
停止捕获声音
*/
enum
{
	INFO_P2PSERVER,
};

typedef struct 
{
	BYTE btState;
	BYTE btBlank1;
	BYTE btBlank2;
	BYTE btBlank3;

	int  nBlank1;
}P2PServerInfo, *LPP2PServerInfo;

IPAC_API BOOL  WINAPI IPAC_DEV_GetOtherInfo(LONG lLoginID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);



//SD卡录像回放
IPAC_API BOOL  WINAPI IPAC_DEV_SDCard_RealPlay(LONG lLoginID, const char* szFileName, STREAM_CALLBACK callback, void  *pUser, BOOL  bBlocked);

IPAC_API BOOL  WINAPI IPAC_DEV_SDCard_SetPlayPercentage(LONG lPercentage);

IPAC_API BOOL  WINAPI IPAC_DEV_SDCard_StopRealPlay(LONG lLoginID);

IPAC_API BOOL  WINAPI IPAC_DEV_BroadcastSetConfig(DWORD    dwCommand,  LONG     lChannel,  LPVOID   lpInBuffer,  DWORD    dwInBufferSize);

// #ifdef __cplusplus
// }
// #endif

#endif