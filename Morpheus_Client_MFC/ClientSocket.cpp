#include "stdafx.h"
#include "ClientSocket.h"
#include "Morpheus_Client_MFC.h"

CClientSocket::CClientSocket()
{

}


CClientSocket::~CClientSocket()
{
}

void CClientSocket::OnReceive(int nErrorCode)
{
	((CMorpheus_Client_MFCApp*)AfxGetApp())->ReceiveData(); //�����͸� �д´�
	CSocket::OnReceive(nErrorCode);

}

void CClientSocket::OnClose(int nErrorCode)
{
	//���� ���ϰ� ����� �ڼ��Ͽ� ���� ó���Ѵ�
	((CMorpheus_Client_MFCApp*)AfxGetApp())->CloseChild(); //�����͸� �д´�
	CSocket::OnClose(nErrorCode);
}
