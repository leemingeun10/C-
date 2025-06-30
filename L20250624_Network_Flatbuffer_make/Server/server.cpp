#define _WINSOCK_DEPRECATED_NO_WARNINGS

#define NOMINMAX

#include <iostream>
#include <WinSock2.h>

#include "flatbuffers/flatbuffers.h"
#include "Calculate_generated.h"
#include "Result_generated.h"

#pragma comment(lib, "ws2_32")

void PrintMap(int x, int y) {
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 20; ++j) {
			if (i == y && j == x)
				std::cout << "*";
			else
				std::cout << ".";
		}
		std::cout << std::endl;
	}
}


int main()
{

	WSAData wsaData;
	int wsaResult = WSAStartup(MAKEWORD(2, 2), &wsaData);


	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN ServerAddr = {};
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	ServerAddr.sin_port = htons(30303);

	bind(ListenSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));
	listen(ListenSocket, 1);

	std::cout << "[서버] 준비 완료. 클라이언트를 기다립니다..." << std::endl;

	// 클라이언트 연결 대기
	SOCKADDR_IN ClientAddr = {};
	int ClientAddrLen = sizeof(ClientAddr);
	SOCKET ClientSocket = accept(ListenSocket, (SOCKADDR*)&ClientAddr, &ClientAddrLen);
	if (ClientSocket == INVALID_SOCKET) {
		std::cerr << "[서버] accept 실패: " << WSAGetLastError() << std::endl;
		return -1;
	}

	


	int x = 5, y = 5;
	PrintMap(x, y);

	while (true)
	{
		int packetsize;
		int recvresult = recv(ClientSocket, (char*)&packetsize, sizeof(packetsize), MSG_WAITALL);
		if (recvresult <= 0)
		{
			std::cout << "recv error1";
			break;
		}
		packetsize = ntohl(packetsize);

		char buffer[1024] = { 0, };
		recvresult = recv(ClientSocket, buffer, packetsize, MSG_WAITALL);
		if (recvresult <= 0)
		{
			std::cout << "recv error2";
			break;
		}

		auto data = Calculate::GetData(buffer);

		switch (data->input())
		{
		case'w': y--;
			break;
		case'a': x--;
			break;
		case's': y++;
			break;
		case'd': x++;
			break;
		}
		if (x < 0) x = 0;
		if (x > 19) x = 19;
		if (y < 0) y = 0;
		if (y > 9) y = 9;

		PrintMap(x, y);

		flatbuffers::FlatBufferBuilder Builder(1024);
		auto result = Calculate::CreateResult(Builder, x, y);
		Builder.Finish(result);

		int sendpacket = htonl(Builder.GetSize());

		send(ClientSocket, (char*)&sendpacket, sizeof(sendpacket), 0);
		send(ClientSocket, (char*)Builder.GetBufferPointer(), Builder.GetSize(), 0);



	}

	closesocket(ClientSocket);

	closesocket(ListenSocket);

	WSACleanup();

	return 0;
}
