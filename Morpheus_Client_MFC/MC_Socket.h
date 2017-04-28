#pragma once
#include "stdafx.h"

//#pragma commnet(lib, "ws2_32.lib");
#pragma comment(lib, "ws2_32.lib")

class MC_Socket //Dynamic Singleton
{
private:
	MC_Socket()
	{
		//* WS2_32.DLL을 사용하기 위해 선언한다.
		//* WSAStartup(사용하는 소켓의 버전, 가져온 정보를 저장하는 구조체 변수);
		WSAStartup(0x0202, &data);
		// 사용자 접속을 체크할 소켓을 생성한다.
		// socket(네트워크 주소 체계, 소켓 타입(TCP), 추가적으로 프로토콜);
		mh_my_socket = socket(AF_INET, SOCK_STREAM, 0);
		// 구조체 등을 정해진 크기만큼 정수로 초기화 시키는 함수
		// memset(초기화 시킬 변수의 맨앞, 초기화시킬 숫자, 초기화시킬 범위)
		memset(&srv_addr, 0, sizeof(struct sockaddr_in));
		// 접속할 서버의 주소 방식을 저장한다.
		srv_addr.sin_family = AF_INET;
		// 접속할 서버의 IP주소를 저장한다.
		srv_addr.sin_addr.s_addr = inet_addr("192.168.1.10");
		// 접속할 서버의 포트번호 저장한다.
		srv_addr.sin_port = htons(5000);
	};
	MC_Socket(const MC_Socket& other);
	~MC_Socket() {};

	static MC_Socket* instance;
	// *현재 사용된 소켓 버전을 체크하기 위한 구조체 변수
	static WSADATA data;
	// 접속할 서버의 정보를 저장할 구조체 변수 선언
	static struct sockaddr_in srv_addr;
public:
	// 서버와 통신할 소켓
	static SOCKET mh_my_socket;
	static MC_Socket* GetInstance()
	{
		if (instance == NULL)
			instance = new MC_Socket();
		return instance;
	}
};

MC_Socket* MC_Socket::instance = nullptr;
