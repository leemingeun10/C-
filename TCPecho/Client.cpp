//#define _WINSOCK_DEPRECATED_NO_WARNINGS 
//
//#include<iostream>
//#include<WinSock2.h>
//#include <fstream>  
//
//// winsock 라이브러리 로딩 
//#pragma comment(lib , "ws2_32")
//
//
//
//using namespace std;
//int main()
//{
//	//dll init
//	WSADATA wsaData;
//
//	int Result = WSAStartup(MAKEWORD(2, 2), &wsaData);
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
//	ListenSockAddr.sin_addr.s_addr =inet_addr("127.0.0.1"); 
//	ListenSockAddr.sin_port = htons(32000); // 포트번호 를 정하고 htons감쌈
//
//	int Result2 = connect(ListenSocket, (struct sockaddr*)&ListenSockAddr, sizeof(ListenSockAddr));
//
//	
//	if (Result2 == SOCKET_ERROR) // <0 
//	{
//		int errorCode = WSAGetLastError();
//		cout << "Connect Error, code: " << errorCode << endl;
//
//		switch (errorCode)
//		{
//		case WSAETIMEDOUT: cout << "→ 연결 시도 시간 초과 (서버 응답 없음)" << endl; break;
//		case WSAECONNREFUSED: cout << "→ 연결 거부 (서버 실행 안 됨 or 포트 닫힘)" << endl; break;
//		case WSAEHOSTUNREACH: cout << "→ 호스트에 도달할 수 없음 (IP 잘못되었거나 네트워크 문제)" << endl; break;
//		case WSAENETUNREACH: cout << "→ 네트워크에 도달할 수 없음" << endl; break;
//		default: cout << "→ 알 수 없는 오류" << endl; break;
//		}
//
//		return 0;
//	}
//
//	cout << "connect" << endl;
//
//	
//
//
//
//
//	// 1. 파일 크기 먼저 수신
//	int fileSize = 0;
//	recv(ListenSocket, (char*)&fileSize, sizeof(fileSize), 0);
//	cout << "받은 파일 크기: " << fileSize << " 바이트" << endl;
//
//	// 2. 수신 준비 완료 신호
//	char ack = '1';
//	send(ListenSocket, &ack, sizeof(ack), 0);
//
//	// 3. 이미지 수신 (청크 방식)
//	std::ofstream outFile("C:/Users/USER/Desktop/received.png", std::ios::binary);
//	if (!outFile)
//	{
//		cout << "파일 저장 실패" << endl;
//		return 0;
//	}
//
//	const int BUFFER_SIZE = 4096;
//	char buffer[BUFFER_SIZE];
//	int totalReceived = 0;
//
//	//버퍼만큼을 계속 수신
//	while (totalReceived < fileSize)
//	{
//		int toReceive = min(BUFFER_SIZE, fileSize - totalReceived);
//		int received = recv(ListenSocket, buffer, toReceive, 0);
//		if (received <= 0)
//		{
//			cout << "수신 에러!" << endl;
//			outFile.close();
//			return 0;
//		}
//		outFile.write(buffer, received);
//		totalReceived += received;
//	}
//
//	outFile.close();
//	cout << "파일 저장 완료: C:/Users/USER/Desktop/received.png" << endl;
//
//	
//
//	cout << "파일 저장 완료: received.png" << endl;
//
//	
//	//Dll remove
//	WSACleanup();
//
//	return 0;
//}