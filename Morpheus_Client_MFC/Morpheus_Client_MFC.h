
// Morpheus_Client_MFC.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.
#include "ClientSocket.h" //* Ŭ���̾�Ʈ ����

// CMorpheus_Client_MFCApp:
// �� Ŭ������ ������ ���ؼ��� Morpheus_Client_MFC.cpp�� �����Ͻʽÿ�.
//

class CMorpheus_Client_MFCApp : public CWinApp
{
public:
	CMorpheus_Client_MFCApp();
	//*�߰�
	CClientSocket* m_pClient;
	// ���� �������� ������ ��û�Ѵ�
	void Connect();
	// ������ ������ �ݰ� �޸𸮸� �����Ѵ�
	void CleanUp();
	// �����͸� �����Ѵ�
	void SendData(CString strData);
	// �����͸� ���Ź޴´�
	void ReceiveData();
	// ����� ������ ������ ȣ���Ѵ�.
	void CloseChild();
// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	


};

extern CMorpheus_Client_MFCApp theApp;