//#define _CRT_SECURE_NO_WARNINGS
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//
//#include <iostream>
//#include <winsock2.h>
//#include <string>
//
//
//#pragma comment(lib, "ws2_32")
//
//int main()
//{
//	WSAData wsaData;
//	WSAStartup(MAKEWORD(2, 2), &wsaData);
//
//	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, 0);
//
//	SOCKADDR_IN ListSockAddr;
//	memset(&ListSockAddr, 0, sizeof(ListSockAddr));
//	ListSockAddr.sin_family = PF_INET;
//	ListSockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//	ListSockAddr.sin_port = htons(30303);
//
//	bind(ListenSocket, (SOCKADDR*)&ListSockAddr, sizeof(ListSockAddr));
//
//	listen(ListenSocket, 0);
//
//	SOCKADDR_IN ClientSockAddr;
//	memset(&ClientSockAddr, 0, sizeof(ClientSockAddr));
//	int ClientSockAddrLength = sizeof(ClientSockAddr);
//	SOCKET ClientSocket = accept(ListenSocket, (SOCKADDR*)&ClientSockAddr, &ClientSockAddrLength);
//
//
//
//	char cur[5];
//	int recvlen =recv(ClientSocket, cur, 5, 0);
//	int first=-1, second;
//
//
//	if (recvlen!= 5)
//	{
//		std::cout << "잘못받아짐";
//	}
//	else
//	{
//		std::string fnum(cur, 2);
//		first = std::stoi(fnum);
//
//		std::string snum(cur+3, 2);
//		second = std::stoi(snum);
//
//	}
//
//	if (!(first == -1))
//	{
//		int retnum;
//		switch (cur[2])
//		{
//		case '+':retnum = first + second;
//		case '-':retnum = first - second;
//		case '*':retnum = first * second;
//		case '/':retnum = first + second;
//		}
//
//		char answer[4];
//		sprintf(answer, "%03d", retnum);
//
//		send(ClientSocket, answer, 3, 0);
//		std::cout << "송신끝";
//
//	}
//	closesocket(ListenSocket);
//	closesocket(ClientSocket);
//	
//
//	WSACleanup();
//
//	return 0;
//}