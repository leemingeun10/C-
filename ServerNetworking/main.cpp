#include<iostream>
#include<WinSock2.h>

// winsock 라이브러리 로딩 
#pragma comment(lib , "ws2_32")

using namespace std;
int main()
{
	//dll init
	WSADATA wsaData;

	int Result = WSAStartup(MAKEWORD(2,2),&wsaData); //윈도우 전용

	if (Result != 0)
	{
		cout << "WindSock init Error";
		return 0;
	}

	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (ListenSocket == INVALID_SOCKET)
	{
		cout << "Socket Error";
		return 0;
	}
	sockaddr_in ListenSockAddr;
	memset(&ListenSockAddr, 0, sizeof(ListenSockAddr));
	ListenSockAddr.sin_family = AF_INET;
	ListenSockAddr.sin_addr.s_addr= INADDR_ANY; // 연습이라 주소 아무거나
	ListenSockAddr.sin_port = htons(32000); // 포트번호 를 정하고 htons감쌈 process 별로 사용 포트 무조건 wellknown 포트 1024 이상으로 쓴다.           

	int Result2 = bind(ListenSocket, (struct sockaddr*)&ListenSockAddr, sizeof(ListenSockAddr));

	if (Result2 == SOCKET_ERROR)
	{
		cout << "bind Error" << GetLastError()<<endl;
		return 0;
	}

	int Result3 = listen(ListenSocket, 5);
	if (Result3 == SOCKET_ERROR)
	{
		cout << "Listen Error" << GetLastError() << endl;
		return 0;
	}

	sockaddr_in ClientSocketAddr;
	memset(&ClientSocketAddr, 0, sizeof(ClientSocketAddr));
	int ClientSockAddrLength = sizeof(ClientSocketAddr);

	SOCKET ClientSocket = accept(ListenSocket, (struct sockaddr*)&ClientSocketAddr, &ClientSockAddrLength);
	if (ClientSocket == INVALID_SOCKET)
	{
		cout << "accpet Error" << GetLastError() << endl;
		return 0;
	}
	
	char Message[1024] = "Hellow World";
	send(ClientSocket,Message,strlen(Message),0);


	char Buffer[1024] = { 0, };
	recv(ClientSocket,Buffer,1024, 0 );

	cout << "Client Send : + " << Buffer << endl;

	closesocket(ClientSocket);
	closesocket(ListenSocket);

	//Dll remove
	WSACleanup();

	return 0; 
}