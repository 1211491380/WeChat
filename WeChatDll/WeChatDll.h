#pragma once
#include"WeBianLiang.h"
#ifdef WECHATDLL_EXPORTS
#define WECHATDLL_API __declspec(dllexport)
#else
#define WECHATDLL_API __declspec(dllimport)
#endif

void  GetKey8url();
class MYQUNLIST
{
public:
	LPWSTR szQid;
	LPWSTR szQName;
	LPWSTR szQzWxid;
	LPWSTR szQChengYuan;
};
//�����ź�����Ϣ
class MYWEHAO
{
public:
	LPWSTR szSex;
	LPWSTR szName;
	LPWSTR szWxid;
	LPWSTR szWxHao;
};
class MYWEQUN
{
public:
	LPWSTR szName;
	LPWSTR szQId;
};
typedef CArray<LPWSTR, LPWSTR&> ARRWXID;

typedef CList <MYWEQUN, MYWEQUN&> LISTQUN;
typedef CList <MYWEHAO, MYWEHAO&> LISTHAOYOU;
/*
����1����Դ���Ǳ�������ҵ��ʱ����д������ѡ� ���������̰�����ѧϰʹ�ã���Դ���ֹ������ҵ�Ƿ���;��
����2����Դ�����κζ�����룡�����ܴ���Щ��BUG �������ɵ���ʧ�ȸ��뱾���޹�
����3��ʹ�ñ��뱾Դ�뼴Ĭ��ͬ����������+
*/
/*
Statement 1: the source code is written in my spare time, "free"
only for reverse programming enthusiasts to learn!This source code is prohibited for commercial illegal use!

Statement 2: this source code without any malicious code!But there may be a little BUG so the
loss caused by the loss has nothing to do with me
*/
/*******************************************************/
/*********֧�ֵ�΢�Ű汾:2.7.1.82***************************/
/*********���ߣ�������Ů����***************************/
/*********ʱ�䣺20191101***************************/
/*********QQ��2865298812***************************/
/*********���䣺670088124@qq.com***************************/
/*********QQ����Ⱥ��635433739***************************/
/*******************************************************/

class WECHATDLL_API CWeChatDll {
public:
/*******************************************************/
/*********���ܣ����ݳ�ʼ�� �������ȵ���һ��************/
/*******************************************************/
	BOOL InitData();
/*******************************************************/
/*********���ܣ���ȡ������Ϣ****************************/
/*********����ֵ������һ�������Ÿ�����Ϣ�����ýṹMYDATANAME***/
/*******************************************************/
	MYDATANAME& GetWeChatGerenXinxi();
/*******************************************************/
/*********���ܣ�������Ϣ****************************/
/*********����1���Է���WXID*************************/
/*********����2��Ҫ���͵�����************************/
/*********����ֵ����*********************/

/*******************************************************/
	VOID SendMsg(LPWSTR pWxid, LPWSTR pwMsg);
/*******************************************************/
/*********���ܣ�������Ϣ****************************/
/*********����ֵ���ɹ�����TRUE ��������ʧ��*********************/
	BOOL HookGetRegiXinxi();
/*******************************************************/
/*********���ܣ�����������Ϣ****************************/
/*********����1����β���3 ΪNULL �������ŷ����ŵ�WXID ����ΪȺID*****/
/*********����2�����յ�������************************/
/*********����3�������Ⱥ��Ϣ��ŵ��Ƿ����ߵ�WXID ����ΪNULL***********/
/*********����ֵ����*********************/
/*********ֻ�õ��� HookGetRegiXinxi ��˺����Żᱻ����********/
	static VOID RecvWxMsg(LPWSTR szWxid, LPWSTR szMsg, LPWSTR szID);
/*******************************************************/
/*********���ܣ�HOOK����΢�Ŷ�ά��****************************/
/*********����ֵ����*********************/
	VOID HookReWeiMaPng();
/***************************************************************************/
/*********���ܣ�������ȡ΢�Ŷ�ά�� �������HookReWeiMaPng�˺����Ż���Ч*************/
/*********����ֵ����*************************************************************/
	static VOID GetErWeiMa(BYTE* ByBuf, DWORD dwlen);

/*********���ܣ�������ѽ�Ⱥ***************************************/
/*********����1������wxid********************************/
/*********����2��ȺID******************************************/
	BOOL SendYaoQingQunLiao(LPWSTR szWxid, LPWSTR szQid);

/*********���ܣ���Ƭ����XML***************************************************/
/*********����1:������Ƭ�ߵ�WXID**********************************************/
/*********����2���������ߵ�WXID**********************************************/
/*********����3���������ߵ��ǳ� ��i���öԷ�����ʲô���־���дʲô*******************/
	VOID SendWxXML(CStringW strWxid_1, CStringW strWxid_2, CStringW strName);
/*********���ܣ�΢���˳���½*********************************/
	DWORD  LogOut();
/*********���ܣ�ɾ������**********************************/
/*********������Ŀ��WXID**********************************/
	VOID DeleUser(LPWSTR szWxid);
/*********���ܣ��ж��Ƿ���ɵ�½**********************************/
	BOOL IsWeChatInitOk();
/*********���ܣ��˳�Ⱥ��****************************************/
/*********����1��Ŀ��ȺID****************************************/
	VOID DeleQunLiao(LPWSTR szQid);
/*********���ܣ���ȡȺ�б�****************************************/
/*********����ֵ������Ⱥ�б�****************************************/
	LISTQUN& GetRoomXinXi();
/*********���ܣ��ݹ��ȡ΢��Ⱥ�б�****************************/
/*********���������������ڵ�****************************/
/*********����ֵ������΢��Ⱥ�б�***********************/
	LISTQUN& GetAddRoomList(DWORD dwList);

/*********���ܣ�˫ջ��ʽ��ȡ�����������б�****************************/
/*********������������ͷ�ڵ��ַ****************************/
/*********����ֵ������LISTHAOYOU������****************************/
LISTHAOYOU &GetAddHaoYouList(DWORD dwList);
/*********���ܣ���ȡ΢�ź�����Ϣ****************************/
/*********��������****************************/
/*********����ֵ������LISTHAOYOU������****************************/
	LISTHAOYOU & GetHaoYouList();
/*********���ܣ��Զ�ͬ����Ӻ���****************************/
/*********����1��V1����****************************/
/*********����2��V2����****************************/
	BOOL ZiDongYesHaoYou(LPWSTR pV1,LPWSTR pV2);
/*********���ܣ��Զ��տ�****************************/
/*********����1��ת����WXID****************************/
/*********����2��������****************************/
	VOID ZiDongShouKuan(LPWSTR pWxid, LPWSTR pDingDan);
/*********���ܣ���ȡȺ��ԱWXID****************************/
/*********����1��ȺID****************************/
	ARRWXID& GetRoomWxid(LPWSTR szID);
	ARRWXID& CWeChatDll::GetRoomArrWxid(DWORD dwList, LPWSTR szID);
/*********���ܣ�ͨ��WXID��ȡ�Է���ϸ��Ϣ****************************/
/*********����1��Ŀ��WXID****************************/
/*********����ֵ��������Ϣ�ṹ��****************************/
	XINXIJIEGOU& CWeChatDll::GetXiangxiXinxi(LPWSTR szID);
	char *CWeChatDll::GetXiangxiBase(LPWSTR szID);
/*********���ܣ���ȡȺ��Ա�б�****************************/
/*********����1��Ŀ��ȺID****************************/
/*********����ֵ��Ⱥ��Ա��Ϣ����****************************/
	QUNCHENGYUANLIST& GetAddRoomXinxi(LPWSTR szID);
/*********���ܣ����ú��ѱ�ע****************************/
/*********����1������WXID****************************/
/*********����2��Ҫ��ע���ǳ�****************************/
	VOID SetBeiZhu(LPWSTR szWxid, LPWSTR szName);
/*********���ܣ��Զ���Ⱥ****************************/
/*********����1��Ⱥ��URL****************************/
/*********����2�������˵�WXID****************************/
	VOID  SendUrlAddRoom(LPWSTR szURL, LPWSTR szWxid);
/*********���ܣ�HOOK��ȡ������URL****************************/
	VOID HookGetKey8();
/*********���ܣ�POST��Ⱥ****************************/
/*********����1��Ⱥ��URL****************************/
	static VOID PostAddRoom(LPWSTR szURL);


/*********���ܣ��ղط���****************************/
/*********����1���Է���WXID****************************/
/*********����2���ղص�������0��ʼ****************************/
	VOID sendCollections(CString lpWxID, int Index);
	DWORD enumContainer(DWORD pParent, CString strText, int nType);
	DWORD getRoot();
	//void sendCollection(CList <CString, CString> &strArray, int Index);
	DWORD m_pUI;
	void updateData(DWORD p)
	{
		m_pUI = p;
	}
	wchar_t* getClass()
	{
		return (wchar_t*)_LPDWORD(m_pUI + 0xCC);
	}
	wchar_t* getText()
	{
		return (wchar_t*)(m_pUI + 0x1BC);
	}
	DWORD getSize()
	{
		DWORD nSize = _LPDWORD(m_pUI + 0x4B0);
		if (nSize > 0x100) nSize = 0;

		return nSize;
	}
	DWORD getChildStartAddr()
	{
		return _LPDWORD(m_pUI + 0x4AC);
	}
	DWORD getChild(DWORD pChildStartAddr, DWORD nIndex)
	{
		if (pChildStartAddr == 0xFFFFFFFF || pChildStartAddr < 0x10000) {
			return 0;
		}
		__try {
			return _LPDWORD(pChildStartAddr + nIndex * 4);
		}
		__except (1) {
			
		}
		return 0;
	}
/******************************************************************************************/
public:
	DWORD m_pContact_list;
	DWORD m_WeDllBase;
	MYDATANAME m_MyDataName;
	MYWEHAO m_MyHaoYou;
	MYWEQUN m_MyQun;
	XINXIJIEGOU m_MyData;
	BOOL m_IsAdd=FALSE;//�Ƿ��Զ�ͬ����Ӻ���
	BOOL m_IsShouKuan = FALSE; //�Զ��տ�
	BOOL m_IsAddRoom = FALSE;//�Զ���Ⱥ
	int m_nVal;//�յ���Ⱥ�����ܴ���
	int m_nNumOk;//�ɹ���Ⱥ����
	int m_nNumOn;//ʧ�ܽ�Ⱥ����

};




extern WECHATDLL_API int nWeChatDll;
WECHATDLL_API int fnWeChatDll(void);
