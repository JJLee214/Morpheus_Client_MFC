#pragma once
#include "afxsock.h"
class CClientSocket :
	public CSocket
{
public:
	CClientSocket();
	~CClientSocket();

	CClientSocket *m_pClient;

	void OnReceive(int nErrorCode);
	void OnClose(int nErrorCode);
};

