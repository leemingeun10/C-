//#define _CRT_SECURE_NO_WARNINGS
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//
//#include <iostream>
//#include <winsock2.h>
//#include <string>
//#pragma comment(lib, "ws2_32")
//
//int main()
//{
//	WSAData wsaData;
//	WSAStartup(MAKEWORD(2, 2), &wsaData);
//
//	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
//
//	SOCKADDR_IN ServerSockAddr;
//	memset(&ServerSockAddr, 0, sizeof(ServerSockAddr));
//	ServerSockAddr.sin_family = PF_INET;
//	ServerSockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//	ServerSockAddr.sin_port = htons(30303);
//
//	connect(ServerSocket, (SOCKADDR*)&ServerSockAddr, sizeof(ServerSockAddr));
//
//
//	std::string input;
//	std::cout << "연산 입력 (예: 12+34): ";
//	std::cin >> input; 
//
//	if (!input.empty())
//	{
//		send(ServerSocket, input.c_str(), 5, 0);
//	}
//
//	char answer[3];
//	int recvnum = recv(ServerSocket, answer, 3, 0);
//
//	if (recvnum == 3)
//	{
//		for (int i= 0 ; i  <3 ;i++)
//		{
//			std::cout << answer[i];
//		}
//	}
//	else
//	{
//		std::cout << "뭔가 잘못받아짐";
//	}
//
//
//
//	closesocket(ServerSocket);
//
//	WSACleanup();
//
//	return 0;
//}