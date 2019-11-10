#pragma once
#include "stdafx.h"
//����תָ��
#define  _LPBASE(X) (DWORD*)(X)
#define _PSTRBASE(X)((LPWSTR)*(DWORD*)(X))
const CStringW GetstrXml(const CStringW& strZ, const CStringW& strY, CStringW& strXML);
CString UTF8ToGB(const char* str);
/*�ı��ָ� ��11��11��11
����1��Ҫ�ָ���ı�
����2����Ϊ�ָ��Ŀ�� ��11��11��11Ҫ�ָ�Ϊ3��11 �˲�������д ������
����3���˲����Ǹ����� ����ָ�� ������� �ָ��˶�����
����ֵ������һ��CString������
*/
CStringW* StrParTition(LPWSTR strTxt, LPWSTR strByte, int& nNum);
void urldecode(char url[]);
typedef struct _BinaryTree
{
	//��
	_BinaryTree* s_tree_pleft;
	//��
	_BinaryTree* s_tree_pcentre;
	//��
	_BinaryTree* s_tree_pright;
	//��־
	byte                s_by_flags;
	//������־
	byte                s_by_endflags;

	_BinaryTree()
	{
		s_tree_pleft = nullptr;
		s_tree_pcentre = nullptr;
		s_tree_pright = nullptr;
		s_by_flags = 0;
		s_by_endflags = 0;
	}

} BinaryTree, *pBinaryTree;
#define _LPDWORD *(LPDWORD)
#define UI_CLASS 1
#define UI_NAME 2
#define UI_TEXT 3
int MyOutputDebugString(LPCTSTR pstrFormat, ...);
#define LOG MyOutputDebugString
typedef struct
{
	wchar_t* lpwString;
	DWORD Len;
	DWORD Len2;
	DWORD Zero0;
	DWORD Zero1;
}WXSTRING, *LPWXSTRING;
typedef struct
{
	LPWXSTRING pHead;
	LPWXSTRING pEnd1;
	LPWXSTRING pEnd2;
	DWORD Zero0;
	DWORD Zero1;
}WXSTRINGARRAY, *LPWXSTRINGARRAY;
//����ת��
BOOL UTF8_TO_GBK(CString &strGBK, LPCSTR lpstring);
//΢���˳���½
typedef DWORD(__stdcall *LOGOUT)(DWORD);
//������Ϣ���㺯��
void HookRecvMsgWx();
//����΢�Ŷ�ά��
void HookEeWeiMa();
//���������Ϣ�����ĵ�ַ
extern DWORD g_JmpRecvMsg;
extern DWORD g_JmpErWeiMaPng;
extern DWORD g_dwJmpKey8;//��ȡ����Ⱥ���������Ӻ�JMP��ԭ����ַ
//����΢�Ÿ�����Ϣ�Ľṹ��
typedef struct DATANAME
{
	CString strWxID;
	CString strWxName;
	CString strWxHao;
	CString strURL;
}MYDATANAME, *PMYDATANAME;
//�����ļ���Ϣ�Ľṹ
typedef struct SENDMSG
{
	LPWSTR lpMsg;
	int nlen;
	int nVal;
}MYSENDMSG,*PMYSENDMSG;
//����ʱWXID�Ľṹ
typedef struct SENWXID
{
	LPWSTR lpWxid;
	int nlen;
	int nVal;
}MYSENDWXID, *PMYSENDWXID;
typedef struct WXIDEX
{
	LPWSTR lpWxid;
	int nlen;
	int nVal;
	char arr[72];
}MYWXIDEX, *PMYWXIDEX;
typedef struct WXID
{
	LPWSTR lpWxid;
	int nlen;
	int nVal;
	int nEnd;
}MYWXID, *PMYWXID;
typedef struct V2DATA
{
	char Memy[0x24c] = {};
	DWORD dwVal = 0x25;
	char Memy2[0x40] = {};
	wchar_t* v2Data;
	int v2Len;
	int v2len2;
	char  Memy3[8] = {};
} WECHATV2DATA, *PWECHATV2DATA;
typedef struct V1DATA
{
	int fill = 0;
	wchar_t* v1;
	int nlen;
	int nlen2;
	char fill2[0x41c] = {};
	DWORD v2 = 0;
} WECHATV1DATA, *PWECHATV1DATA;
//�տ�ṹ��
typedef struct strShouKuan
{
	LPWSTR szDanHao;
	int len;
	int lenMax;
	int null0 = 0;
	int null1 = 0;
	LPWSTR szWxid;
	int len1;
	int lenMax1;
	int end0 = 0;
	int end1 = 0;
	int end3 = 0;
}ShouKuan,*PShouKuan;
typedef struct HAOYOUXINXI
{
	LPWSTR szWxid;
	LPWSTR szWxHao;
	LPWSTR szV1;
	LPWSTR szName;
}XINXIJIEGOU,*PXINXIJIEGOU;
typedef struct STRWXID
{
	int nVal1;
	int nVal2;
	LPWSTR lpWxid;
	int nlen;
	int nlenMax;
	int end;
}STRWXIDEX;
typedef CList<XINXIJIEGOU, XINXIJIEGOU&> QUNCHENGYUANLIST;



//΢�Ÿ������Ƶ�ƫ��
#define WENAMEOFFSET 0x13972FC
//����ͷ���URLƫ��            
#define  WETOUXIANGURLOFFSET 0x13975C4
//����΢��IDƫ�� 
#define WEWXIDOFFSET 0x1397700
//���΢�ź�ƫ��
#define  WECHATHAO 0x13976E8
//���΢���Ƿ��½��ɱ�־
#define ISWECHATOK 0x13A986C


//������Ϣ��CALL��ƫ�� 
/*�����룺C70000000000C7400400000000C7400800000000A3????????50A1????????B9????????FF50*/
#define  WERECVMSGOFFSET 0x264F20
//��½��ά������
//�����룺83 C4 08 84 C0 0F 85 ?? ?? ?? ?? FF 76 34 8D 4D 0C FF 76 30 E8 ?? ?? ?? ?? 8D 45 0C C7 45 FC 0000 00 00
#define WEERWEIMAPNGOFFSET 0x4A2AD0
//������ϢCALL��ƫ��
/**CALL�����룺8B???? 8D???? 6A01?? ??8D8D????????E8????????83C40C50 **/
#define WESENDTEXTOFFSET 0x2FA780
/************************�����������Ⱥ�õ���ƫ��*****************************************/
//����wxid�ṹ���call
#define WESHENGCHENGWXIDOFFSET 0x59390

//������� �����ý�Ⱥ����� ������Լ���΢��ID
#define WECEXOFFSET 0x1397284
#define WEBIXUZHIXINGOFFSET 0x4A4560

//��ȺIDѹ���ջ
#define WECHATQUNOFFSET 0x6A7A0
//��Ⱥ���� CALL
//�����룺83 C4 04 C6 45 FC ?? ?? B9 ?? ?? ?? ?? C6 45 FC ?? E8 ?? ?? ?? ??
#define WEJINQUNECXOFFSET 0x13977B0
#define WEJINQUNYAOQINGOFFSET 0x2712F0

//Ⱥ��������40��Ҫִ�����CALL
//�����룺8D 87 ?? ?? ?? ?? C6 45 ?? ?? 50 E8 ?? ?? ?? ?? 8B 87 ?? ?? ?? ?? 8D 8F ?? ?? ?? ?? 6A 01 FF ?? 8D 8D ?? ?? ?? ?? E8 ?? ?? ?? ?? 8D 8D ?? ?? ?? ?? E8 ?? ?? ?? ?? E9 ?? ?? ?? ?? 85 F6
#define WEJINQUNYAOQING2OFFSET 0x271150
/******************************************************************************************/
//������ƬXML
//�����룺83 C4 04 C6 45 FC 02 6A 2A 8D 45 ? ? 8B D6 6A 00 50 8D 8D ? ? ? ? ? ? ? ? E8 ? ? ? ? ? ? ? ? 83 C4 0C
#define WESENDMXLOFFSET 0x2FA780
//΢���˳���ǰ��½�ĺ���ƫ��
//����������Kicked by Srv Logout onLogout(0,0,0) ����CALL���� 
#define WECHATEXITOFFSET 0x40B330
//ɾ�����ѵ�CALLƫ��
//�������� menuCmdDeletePublicUser����2�������ľ���
#define WEDELETEHAOYOUOFFSET 0x2809D0
//ɾ���˳�Ⱥ
//�����룺53 E8 ?? ?? ?? ?? 8D 87 ?? ?? ?? ?? 8B CB 50 E8 
#define WEDELEQUNLIAOOFFSET 0x276600
//����Ⱥ �������Ѷ�������ַƫ��
//�����룺FF 15 ?? ?? ?? ?? A1 ?? ?? ?? ?? 83 C0 24 5E C3
#define  WEBIANLIQUNOFFSET 0x1397AAC
//����Ⱥ��ԱWXID
//�����룺FF 15 ?? ?? ?? ?? A1 ?? ?? ?? ?? 05 80 06 00 00 5E C3
#define WECHATROOMINF 0x126E0A0  
//�Զ�ͬ����Ӻ���
//�����룺8B D7 8D 8F ?? ?? ?? ?? F7 DA 50 1B D2 23 D1 8D 8F ?? ?? ?? ?? 52 56 E8 
#define WEYESADDHAOYOU 0x18EBC0
#define WEYESADDHAOYOU2 0x527A0
#define WEYESADDHAOYOU3 0x1397A04
#define  WEYESADDHAOYOU4 0xD37C0
#define  WEYESADDHAOYOU5 0x173ED0

//�Զ��տ�
//�����룺8B 45 34 83 EC ? ? 89 45 D0 8B CC 8D 45 A8 C7 45 D4 00 00 00 00 50 E8 ? ? ? ? ? ? ? ? E8
#define  WEYESSHOUKUAN1 0x757450  //CALL1
#define  WEYESSHOUKUAN2 0x7574D0  //CALL2

//ͨ��WXID��ȡ�û���ϸ
//������8D BE ?? ?? ?? ?? 57 83 EC ?? 8D 45 08 8B CC 89 65 D4 50 E8 ?? ?? ?? ?? C6 45 FC 01 E8 ?? ?? ?? ?? C6 45 FC 00 E8
#define WEXIANGXIXINXICALL1 0x4A4450
#define WEXIANGXIXINXICALL2 0x53400
#define WEXIANGXIXINXICALL3 0x27F4F0

//ͨ��WXID���ñ�ע
//EB ?? E8 ?? ?? ?? ?? 51 56 E8
#define WECHATBEIZHU1 0x43FDE0
#define WECHATBEIZHU2 0x53400
#define WECHATBEIZHU3 0x2808A0

//�ղط���
// WECHATSHOUCANG4������
/*55 8B EC 6A FF 68 ? ? ? ? ? ? ? ? 64 A1 00 00 00 00 50 51 56 A1 ? ? ? ? ? ? ? ? 33 C5 50 8D 45 F4 64 A3
00 00 00 00 8B F1 83 BE 54 0A 00 00 00 0F 85 F6 00 00 00 0F 10 05*/
#define WECHATSHOUCANG4 0x620900
//WECHATSHOUCANG2������
//55 8B EC 83 E4 F8 83 EC 2C A1 ? ? ? ? ? ? ? ? 33 C4 89 44 24 28 53 56 8B 75 08 8B D9 8B 4D 10 89 7424 10 89 4C 24 08 57
#define WECHATSHOUCANG2 0x7CA980
//WECHATSHOUCANG3������
//55 8B EC F6 45 10 01 56 57 8B F1 74 ?? 8B 06 FF 90 ?? ?? ?? ?? 84 C0 75 ?? 33 C0 EB ?? F6 45 1002 74
#define WECHATSHOUCANG3 0x7C2E48

#define WECHATSHOUCANG1 0x1397A44


//�Զ���Ⱥ��ȡKEY8
//83 EC 08 8D 45 E4 8B CC 89 65 1C 50 E8 ?? ?? ?? ?? C6 45 FC 04 E8 ?? ?? ?? ?? 8B C8 C6 45 FC 03E8 ? ? ? ? ? ? ? ? 8AD8
#define WECHATGETKEY1 0xB34C58
#define WECHATGETKEY2 0x4A4710
#define WECHATGETKEY3 0x11004F4
#define WECHATGETKEY4 0x4A4710
#define WECHATGETKEY5 0x38E8D0
#define WECHATGETKEY6 0x2F1360
#define WECHATGETKEY7 0x6D1D0
#define WECHATGETKEY8 0x6D4E0
#define WECHATGETKEY9 0x358E80
//HOOK�õ�KEY8
//6A 00 FF 70 08 E8 ?? ?? ?? ?? 8D 45 DC 50 8D 4E 24
#define WECHATHOOKGETKEY8 0x38F559

