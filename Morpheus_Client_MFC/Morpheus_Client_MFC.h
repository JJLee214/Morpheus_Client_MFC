
// Morpheus_Client_MFC.h : PROJECT_NAME 응용 프로그램에 대한 주 헤더 파일입니다.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"		// 주 기호입니다.
#include "ClientSocket.h" //* 클라이언트 소켓

// CMorpheus_Client_MFCApp:
// 이 클래스의 구현에 대해서는 Morpheus_Client_MFC.cpp을 참조하십시오.
//

class CMorpheus_Client_MFCApp : public CWinApp
{
public:
	CMorpheus_Client_MFCApp();
	//*추가
	CClientSocket* m_pClient;
	// 서버 소켓으로 접속을 요청한다
	void Connect();
	// 생성된 소켓을 닫고 메모리를 해제한다
	void CleanUp();
	// 데이터를 전송한다
	void SendData(CString strData);
	// 데이터를 수신받는다
	void ReceiveData();
	// 연결된 소켓이 닫히면 호출한다.
	void CloseChild();
// 재정의입니다.
public:
	virtual BOOL InitInstance();

// 구현입니다.

	DECLARE_MESSAGE_MAP()
	


};

extern CMorpheus_Client_MFCApp theApp;