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
	((CMorpheus_Client_MFCApp*)AfxGetApp())->ReceiveData(); //데이터를 읽는다
	CSocket::OnReceive(nErrorCode);

}

void CClientSocket::OnClose(int nErrorCode)
{
	//닫힌 소켓과 연결된 자소켓에 대해 처리한다
	((CMorpheus_Client_MFCApp*)AfxGetApp())->CloseChild(); //데이터를 읽는다
	CSocket::OnClose(nErrorCode);
}
