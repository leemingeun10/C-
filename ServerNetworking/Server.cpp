//#define _CRT_SECURE_NO_WARNINGS
//
//
//#include<iostream>
//#include<WinSock2.h>
//#include <fstream>  
//
//
//
//// winsock 라이브러리 로딩 
//#pragma comment(lib , "ws2_32")
//
//using namespace std;
//int main()
//{
//	//dll init
//	WSADATA wsaData;
//
//	int Result = WSAStartup(MAKEWORD(2,2),&wsaData); //윈도우 전용
//
//	if (Result != 0)
//	{
//		cout << "WindSock init Error";
//		return 0;
//	}
//
//	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//
//	if (ListenSocket == INVALID_SOCKET)
//	{
//		cout << "Socket Error";
//		return 0;
//	}
//	sockaddr_in ListenSockAddr;
//	memset(&ListenSockAddr, 0, sizeof(ListenSockAddr));
//	ListenSockAddr.sin_family = AF_INET;
//	ListenSockAddr.sin_addr.s_addr= INADDR_ANY; // 연습이라 주소 아무거나
//	ListenSockAddr.sin_port = htons(32000); // 포트번호 를 정하고 htons감쌈 process 별로 사용 포트 무조건 wellknown 포트 1024 이상으로 쓴다.           
//
//	int Result2 = bind(ListenSocket, (struct sockaddr*)&ListenSockAddr, sizeof(ListenSockAddr));
//
//	if (Result2 == SOCKET_ERROR)
//	{
//		cout << "bind Error" << GetLastError()<<endl;
//		return 0;
//	}
//
//	int Result3 = listen(ListenSocket, 5);
//	if (Result3 == SOCKET_ERROR)
//	{
//		cout << "Listen Error" << GetLastError() << endl;
//		return 0;
//	}
//
//	sockaddr_in ClientSocketAddr;
//	memset(&ClientSocketAddr, 0, sizeof(ClientSocketAddr));
//	int ClientSockAddrLength = sizeof(ClientSocketAddr);
//
//	SOCKET ClientSocket = accept(ListenSocket, (struct sockaddr*)&ClientSocketAddr, &ClientSockAddrLength);
//	if (ClientSocket == INVALID_SOCKET)
//	{
//		cout << "accpet Error" << GetLastError() << endl;
//		return 0;
//	}
//	
//	// 버퍼 사이즈 
//	const int BUFFER_SIZE = 4096;
//	char buffer[BUFFER_SIZE];
//
//	FILE* fp = fopen("C:/good.png", "rb");
//	if (!fp)
//	{
//		cout << "파일 열기 실패" << endl;
//		return 0;
//	}
//
//
//	fseek(fp, 0, SEEK_END);
//	int fileSize = ftell(fp);
//	rewind(fp);
//	send(ClientSocket, (char*)&fileSize, sizeof(fileSize), 0);
//
//	// 준비 확인
//	char ack[2] = { 0 };
//	int recvLen = recv(ClientSocket, ack, 1, 0);
//	if (recvLen <= 0 || ack[0] != '1')
//	{
//		cout << "클라이언트 준비 안 됨" << endl;
//		fclose(fp);
//		return 0;
//	}
//
//	// 청크 단위로 파일 읽고 전송
//	int totalSent = 0;
//	while (!feof(fp))
//	{
//		int bytesRead = fread(buffer, 1, BUFFER_SIZE, fp);
//		if (bytesRead > 0)
//		{
//			int sent = send(ClientSocket, buffer, bytesRead, 0);
//			if (sent == SOCKET_ERROR)
//			{
//				cout << "전송 중 에러 발생" << endl;
//				fclose(fp);
//				return 0;
//			}
//			totalSent += sent;
//		}
//	}
//
//	cout << "전송 완료  바이트 : " << totalSent << endl;
//	fclose(fp);
//
//	closesocket(ClientSocket);
//	closesocket(ListenSocket);
//
//	//Dll remove
//	WSACleanup();
//
//	return 0; 
//}