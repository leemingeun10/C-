//#define _CRT_SECURE_NO_WARNINGS
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//
//#include <iostream>
//#include <string>
//#include <winsock2.h>
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
//	while (true)
//	{
//		SOCKADDR_IN ClientSockAddr;
//		memset(&ClientSockAddr, 0, sizeof(ClientSockAddr));
//		int ClientSockAddrLength = sizeof(ClientSockAddr);
//		SOCKET ClientSocket = accept(ListenSocket, (SOCKADDR*)&ClientSockAddr, &ClientSockAddrLength);
//
//		while (true)
//		{
//			char Buffer[30] = { 0, };
//
//			int RecvBytes = recv(ClientSocket, Buffer, 5, 0);
//
//			if (RecvBytes == 0)
//			{
//				//정상종료
//				break;
//			}
//			else if (RecvBytes < 0)
//			{
//				//비정상종료
//				break;
//			}
//
//
//			//[9][9][+][9][9]
//
//			char FirstNumberString[3] = { 0, };
//			char SecondNumberString[3] = { 0, };
//			char Operator[1] = { 0, };
//			//FirstNumberString[0] = Buffer[0];
//			//FirstNumberString[1] = Buffer[1];
//			//SecondNumberString[0] = Buffer[3];
//			//SecondNumberString[1] = Buffer[4];
//
//			memcpy(FirstNumberString, &Buffer[0], 2);
//			memcpy(SecondNumberString, &Buffer[3], 2);
//			Operator[0] = Buffer[2];
//
//			int FirstNumber = atoi(FirstNumberString);
//			int SecondNumber = atoi(SecondNumberString);
//			int TotalNumber = 0;
//
//			switch (Operator[0] )
//			{
//			case'+':
//				TotalNumber = FirstNumber + SecondNumber; break;
//			case'-':
//				TotalNumber = FirstNumber - SecondNumber; break;
//			case'/':
//				TotalNumber = FirstNumber / SecondNumber; break;
//			case'*':
//				TotalNumber = FirstNumber * SecondNumber; break;
//			}
//
//
//			char Message[1024] = { 0, }; 
//
//			_itoa(TotalNumber, Message, 10);
//
//			send(ClientSocket, Message, strlen(Message), 0);
//			printf("%s", Buffer);
//			printf(" = %d\n", TotalNumber);
//		}
//
//		closesocket(ClientSocket);
//	}
//	closesocket(ListenSocket);
//
//	WSACleanup();
//
//	return 0;
//}