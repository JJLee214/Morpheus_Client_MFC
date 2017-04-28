#pragma once
#include "stdafx.h"

//#pragma commnet(lib, "ws2_32.lib");
#pragma comment(lib, "ws2_32.lib")

class MC_Socket //Dynamic Singleton
{
private:
	MC_Socket()
	{
		//* WS2_32.DLL�� ����ϱ� ���� �����Ѵ�.
		//* WSAStartup(����ϴ� ������ ����, ������ ������ �����ϴ� ����ü ����);
		WSAStartup(0x0202, &data);
		// ����� ������ üũ�� ������ �����Ѵ�.
		// socket(��Ʈ��ũ �ּ� ü��, ���� Ÿ��(TCP), �߰������� ��������);
		mh_my_socket = socket(AF_INET, SOCK_STREAM, 0);
		// ����ü ���� ������ ũ�⸸ŭ ������ �ʱ�ȭ ��Ű�� �Լ�
		// memset(�ʱ�ȭ ��ų ������ �Ǿ�, �ʱ�ȭ��ų ����, �ʱ�ȭ��ų ����)
		memset(&srv_addr, 0, sizeof(struct sockaddr_in));
		// ������ ������ �ּ� ����� �����Ѵ�.
		srv_addr.sin_family = AF_INET;
		// ������ ������ IP�ּҸ� �����Ѵ�.
		srv_addr.sin_addr.s_addr = inet_addr("192.168.1.10");
		// ������ ������ ��Ʈ��ȣ �����Ѵ�.
		srv_addr.sin_port = htons(5000);
	};
	MC_Socket(const MC_Socket& other);
	~MC_Socket() {};

	static MC_Socket* instance;
	// *���� ���� ���� ������ üũ�ϱ� ���� ����ü ����
	static WSADATA data;
	// ������ ������ ������ ������ ����ü ���� ����
	static struct sockaddr_in srv_addr;
public:
	// ������ ����� ����
	static SOCKET mh_my_socket;
	static MC_Socket* GetInstance()
	{
		if (instance == NULL)
			instance = new MC_Socket();
		return instance;
	}
};

MC_Socket* MC_Socket::instance = nullptr;
