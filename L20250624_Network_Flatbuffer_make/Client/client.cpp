#define _WINSOCK_DEPRECATED_NO_WARNINGS

#define NOMINMAX


#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#include "Packet.h"
#include <conio.h> // _kbhit(), _getch()


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
	std:: cout << std::endl;
	}
}


int main()
{
	WSAData wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET ServerSocket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN ServerSockAddr;
	memset(&ServerSockAddr, 0, sizeof(ServerSockAddr));
	ServerSockAddr.sin_family = PF_INET;
	ServerSockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	ServerSockAddr.sin_port = htons(30303);

	::connect(ServerSocket, (SOCKADDR*)&ServerSockAddr, sizeof(ServerSockAddr));

	
	while (true)
	{
		if (_kbhit())
		{
			char input = _getch();
			if (input == 'w' || input == 's' || input == 'a' || input == 'd')
			{
				flatbuffers::FlatBufferBuilder Builder(1024); // 만들 flatbuffer 사이즈 1024
				auto data = Calculate::CreateData(Builder, input);
				Builder.Finish(data);

				// 데이터 전송
				int size = htonl(Builder.GetSize());
				send(ServerSocket, (char*)&size, sizeof(size), 0);
				send(ServerSocket, (char*)Builder.GetBufferPointer(), Builder.GetSize(), 0);

				// 응답 수신
				int recvSize = 0;
				if (recv(ServerSocket, (char*)&recvSize, sizeof(recvSize), MSG_WAITALL) <= 0) break;
				recvSize = ntohl(recvSize);

				char buffer[1024] = {};
				if (recv(ServerSocket, buffer, recvSize, MSG_WAITALL) <= 0) break;

				auto res = Calculate::GetResult(buffer);
				int x = res->result_number1();
				int y = res->result_number2();

				// 콘솔 출력
				PrintMap(x, y);


			}
		}
	}

	closesocket(ServerSocket);

	WSACleanup();

	return 0;
}