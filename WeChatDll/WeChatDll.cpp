// WeChatDll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "WeChatDll.h"
#ifdef _X86_
extern "C" { int _afxForceUSRDLL; }
#else
extern "C" { int __afxForceUSRDLL; }
#endif
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CWinApp theApp;

using namespace std;
CWeChatDll g_WeChatDll;

BOOL Mymain()
{
	int nRetCode = 0;
	AfxMessageBox("ע��");
	HMODULE hModule = ::GetModuleHandle(nullptr);

	if (hModule != nullptr)
	{
		// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
		if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
		{
			// TODO: ���Ĵ�������Է���������Ҫ
			wprintf(L"����: MFC ��ʼ��ʧ��\n");
			nRetCode = 1;
		}
		else
		{
			

			//0BCCEA10  0A6EADB8  UNICODE "wxid_udf87w5xrr5622"
			//0BDE3598  0BBC7EA0  UNICODE "wxid_o6qtpsjzi32922"
			//0A8CC578  0B75F388  UNICODE "wxid_qcf7tarw5i8y22"




			g_WeChatDll.InitData();
			//AfxMessageBox("��ʼ��Ⱥ");
			//g_WeChatDll.SendUrlAddRoom(L"https://support.weixin.qq.com/cgi-bin/mmsupport-bin/addchatroombyinvite?ticket=A6fff1ao1vmoNr6BrkjC0",L"wxid_o6qtpsjzi32922");
			//CString aa = "wxid_66hotg8nv37m22";
			//g_WeChatDll.sendCollections(aa,0);
			//g_WeChatDll.GetXiangxiBase(L"liuhaiqi000");
			//0AA93148  0BA44758  UNICODE "wxid_oeufy22czhxr12"
			//g_WeChatDll.SetBeiZhu(L"wxid_benwytlkyosx21", L"AA666��ע�ɹ��");

			/*for (int k=0;k<5;k++)
			{
				AfxMessageBox("��ʼ��ȡ");
				QUNCHENGYUANLIST& listQunChengyuan = g_WeChatDll.GetAddRoomXinxi(L"105489409@chatroom");
				int nNum = listQunChengyuan.GetCount();
				CStringW strnNum;
				strnNum.Format(L"Ⱥ��Ա������%d", nNum);
				OutputDebugStringW(strnNum);
				for (int i = 0; i < nNum; i++)
				{
				
					XINXIJIEGOU& Xinxi = listQunChengyuan.GetAt(listQunChengyuan.FindIndex(i));

					OutputDebugStringW(Xinxi.szName);
					OutputDebugStringW(Xinxi.szWxHao);
					OutputDebugStringW(Xinxi.szV1);
					OutputDebugStringW(Xinxi.szWxid);

				}
			}*/
			/*ARRWXID &listRet = g_WeChatDll.GetRoomWxid(L"105489409@chatroom");
			if (listRet.IsEmpty())
			{
				return 0;
			}
			CString str;
			str.Format("��ǰqun��Ա������%d", listRet.GetSize());
			AfxMessageBox(str);
			for (int i = 0; i < listRet.GetSize(); i++)
			{

				LPWSTR Myhao = listRet.GetAt(i);

				OutputDebugStringW(Myhao);
				//OutputDebugStringW(Myhao.szQId);
			}*/

		}
	}
	else
	{
		// TODO: ���Ĵ�������Է���������Ҫ
		wprintf(L"����: GetModuleHandle ʧ��\n");
		nRetCode = 1;
	}

	return nRetCode;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��������
#pragma comment(linker, "/EXPORT:vSetDdrawflag=_AheadLib_vSetDdrawflag,@1")
#pragma comment(linker, "/EXPORT:AlphaBlend=_AheadLib_AlphaBlend,@2")
#pragma comment(linker, "/EXPORT:DllInitialize=_AheadLib_DllInitialize,@3")
#pragma comment(linker, "/EXPORT:GradientFill=_AheadLib_GradientFill,@4")
#pragma comment(linker, "/EXPORT:TransparentBlt=_AheadLib_TransparentBlt,@5")
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// �궨��
#define EXTERNC extern "C"
#define NAKED __declspec(naked)
#define EXPORT __declspec(dllexport)

#define ALCPP EXPORT NAKED
#define ALSTD EXTERNC EXPORT NAKED void __stdcall
#define ALCFAST EXTERNC EXPORT NAKED void __fastcall
#define ALCDECL EXTERNC NAKED void __cdecl
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// AheadLib �����ռ�
namespace AheadLib
{
	HMODULE m_hModule = NULL;	// ԭʼģ����
	DWORD m_dwReturn[5] = { 0 };	// ԭʼ�������ص�ַ


									// ����ԭʼģ��
	inline BOOL WINAPI Load()
	{
		TCHAR tzPath[MAX_PATH];
		TCHAR tzTemp[MAX_PATH * 2];

		GetSystemDirectory(tzPath, MAX_PATH);
		lstrcat(tzPath, TEXT("\\msimg32"));
		m_hModule = LoadLibrary(tzPath);
		if (m_hModule == NULL)
		{
			wsprintf(tzTemp, TEXT("�޷����� %s�������޷��������С�"), tzPath);
			MessageBox(NULL, tzTemp, TEXT("AheadLib"), MB_ICONSTOP);
		}

		return (m_hModule != NULL);
	}

	// �ͷ�ԭʼģ��
	inline VOID WINAPI Free()
	{
		if (m_hModule)
		{
			FreeLibrary(m_hModule);
		}
	}

	// ��ȡԭʼ������ַ
	FARPROC WINAPI GetAddress(PCSTR pszProcName)
	{
		FARPROC fpAddress;
		CHAR szProcName[16];
		TCHAR tzTemp[MAX_PATH];

		fpAddress = GetProcAddress(m_hModule, pszProcName);
		if (fpAddress == NULL)
		{
			if (HIWORD(pszProcName) == 0)
			{
				wsprintf(szProcName, "%d", pszProcName);
				pszProcName = szProcName;
			}

			wsprintf(tzTemp, TEXT("�޷��ҵ����� %hs�������޷��������С�"), pszProcName);
			MessageBox(NULL, tzTemp, TEXT("AheadLib"), MB_ICONSTOP);
			ExitProcess(-2);
		}

		return fpAddress;
	}
}
using namespace AheadLib;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��ں���
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, PVOID pvReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);
		Mymain();
		return Load();
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		Free();
	}

	return TRUE;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��������
ALCDECL AheadLib_vSetDdrawflag(void)
{
	GetAddress("vSetDdrawflag");
	__asm JMP EAX;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��������
ALCDECL AheadLib_AlphaBlend(void)
{
	GetAddress("AlphaBlend");
	__asm JMP EAX;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��������
ALCDECL AheadLib_DllInitialize(void)
{
	GetAddress("DllInitialize");
	__asm JMP EAX;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��������
ALCDECL AheadLib_GradientFill(void)
{
	GetAddress("GradientFill");
	__asm JMP EAX;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��������
ALCDECL AheadLib_TransparentBlt(void)
{
	GetAddress("TransparentBlt");
	__asm JMP EAX;
}


