
// Morpheus_Client_MFC.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "Morpheus_Client_MFC.h"
#include "Morpheus_Client_MFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMorpheus_Client_MFCApp

BEGIN_MESSAGE_MAP(CMorpheus_Client_MFCApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMorpheus_Client_MFCApp ����

CMorpheus_Client_MFCApp::CMorpheus_Client_MFCApp()
{
	// �ٽ� ���� ������ ����
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	m_pClient = NULL;
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CMorpheus_Client_MFCApp ��ü�Դϴ�.

CMorpheus_Client_MFCApp theApp;


// CMorpheus_Client_MFCApp �ʱ�ȭ

BOOL CMorpheus_Client_MFCApp::InitInstance()
{
	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControlsEx()�� �ʿ��մϴ�.
	// InitCommonControlsEx()�� ������� ������ â�� ���� �� �����ϴ�.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ���� ���α׷����� ����� ��� ���� ��Ʈ�� Ŭ������ �����ϵ���
	// �� �׸��� �����Ͻʽÿ�.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}


	// ��ȭ ���ڿ� �� Ʈ�� �� �Ǵ�
	// �� ��� �� ��Ʈ���� ���ԵǾ� �ִ� ��� �� �����ڸ� ����ϴ�.
	CShellManager *pShellManager = new CShellManager;

	// MFC ��Ʈ���� �׸��� ����ϱ� ���� "Windows ����" ���־� ������ Ȱ��ȭ
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ǥ�� �ʱ�ȭ
	// �̵� ����� ������� �ʰ� ���� ���� ������ ũ�⸦ ���̷���
	// �Ʒ����� �ʿ� ���� Ư�� �ʱ�ȭ
	// ��ƾ�� �����ؾ� �մϴ�.
	// �ش� ������ ����� ������Ʈ�� Ű�� �����Ͻʽÿ�.
	// TODO: �� ���ڿ��� ȸ�� �Ǵ� ������ �̸��� ����
	// ������ �������� �����ؾ� �մϴ�.
	SetRegistryKey(_T("���� ���� ���α׷� �����翡�� ������ ���� ���α׷�"));

	CMorpheus_Client_MFCDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: ���⿡ [Ȯ��]�� Ŭ���Ͽ� ��ȭ ���ڰ� ������ �� ó����
		//  �ڵ带 ��ġ�մϴ�.
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ���⿡ [���]�� Ŭ���Ͽ� ��ȭ ���ڰ� ������ �� ó����
		//  �ڵ带 ��ġ�մϴ�.
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "���: ��ȭ ���ڸ� ������ �������Ƿ� ���� ���α׷��� ����ġ �ʰ� ����˴ϴ�.\n");
		TRACE(traceAppMsg, 0, "���: ��ȭ ���ڿ��� MFC ��Ʈ���� ����ϴ� ��� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS�� ������ �� �����ϴ�.\n");
	}

	// ������ ���� �� �����ڸ� �����մϴ�.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

#ifndef _AFXDLL
	ControlBarCleanUp();
#endif

	// ��ȭ ���ڰ� �������Ƿ� ���� ���α׷��� �޽��� ������ �������� �ʰ�  ���� ���α׷��� ���� �� �ֵ��� FALSE��
	// ��ȯ�մϴ�.
	return FALSE;
}

// ���� �������� ������ ��û�Ѵ�
void CMorpheus_Client_MFCApp::Connect()
{
	CMorpheus_Client_MFCDlg dlg;
	//if (dlg.DoModal() == IDOK)
	//{
		//AfxMessageBox(_T("����"), MB_RETRYCANCEL | MB_ICONINFORMATION);
		m_pClient = new CClientSocket; // Ŭ���̾�Ʈ ���� ��ü�� ���� �޸� �Ҵ��� ��
		m_pClient->Create(); // Ŭ���̾�Ʈ ���� �����Ѵ�.
							 // ������ IP �ּҿ� ��Ʈ ��ȣ�� �����Ͽ� ������ ������ �õ��Ѵ�.
		//m_pClient->Connect(dlg.m_strAddress, 5000);
		m_pClient->Connect(_T("192.168.1.10"), 5000);
		//// <������> ��ư Ȱ��ȭ
		//->GetDlgItem(BUTTON_SendToServer)->EnableWindow(TRUE);
		//// <���� ����...> ��ư ��Ȱ��ȭ
		//m_pMainwnd->GetDlgItem(BUTTON_Connect)->EnableWindow(TRUE);
	//}
}


// ������ ������ �ݰ� �޸𸮸� �����Ѵ�
void CMorpheus_Client_MFCApp::CleanUp()
{
	//������ ������ �ݰ� �޸𸮸� �����Ѵ�.
	if (m_pClient)
		delete m_pClient;

}


// �����͸� �����Ѵ�
void CMorpheus_Client_MFCApp::SendData(CString strData)
{
	if (m_pClient)
	{
		strData.Insert(strData.GetLength(), _T("\0"));
		m_pClient->Send(strData, 100);
		CString strIP, strText;
		UINT nPort;
		m_pClient->GetSockName(strIP, nPort); //�ڽ��� IP�ּҿ� ��Ʈ ��ȣ ����
		strText.Format(_T("[ %s ] %s"), strIP, strData);
		//((CListBox*)m_pMainWnd->GetDlgItem(IDC_LIST1))->InsertString(-1, strText);
	}
}


// �����͸� ���Ź޴´�
void CMorpheus_Client_MFCApp::ReceiveData()
{
	char temp[1000];
	m_pClient->Receive(temp, sizeof(temp));
	CString strIP, strText;
	UINT nPort;
	m_pClient->GetPeerName(strIP, nPort); //������ IP�ּ��ϰ� ��Ʈ ��ȣ ����
	strText.Format(_T("[ %s ] %s"), strIP, temp);
	//((CListBox*)m_pMainWnd->GetDlgItem(IDC_LIST1))->InsertString(-1, strText);
}


// ����� ������ ������ ȣ���Ѵ�.
void CMorpheus_Client_MFCApp::CloseChild()
{
	//((CListBox*)m_pMainWnd->GetDlgItem(IDC_LIST1))->InsertString(-1, _T("���� ���� ����"));
	//<������> ��ư ��Ȱ��ȭ
	m_pMainWnd->GetDlgItem(BUTTON_SendToServer)->EnableWindow(FALSE);
	//<���� ����..> ��ư Ȱ��ȭ
	m_pMainWnd->GetDlgItem(BUTTON_Connect)->EnableWindow(TRUE);
}