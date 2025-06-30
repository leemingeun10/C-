#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define NOMINMAX

#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "flatbuffers/flatbuffers.h"
#include"Calculate_generated.h"


#pragma comment(lib, "ws2_32.lib")
using namespace std;
using namespace rapidjson;

void PrintMap(int x, int y) {
    COORD pos = { 0, 0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (i == y && j == x)
                cout << "*";
            else
                cout << ".";
        }
        cout << endl;
    }
}

int main() {
    WSAData wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    SOCKADDR_IN addr = {};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(30303);

    bind(ListenSocket, (SOCKADDR*)&addr, sizeof(addr));
    listen(ListenSocket, 1);

    cout << "[서버] 준비 완료. 클라이언트를 기다립니다.\n";

    SOCKADDR_IN clientAddr = {};
    int clientLen = sizeof(clientAddr);
    SOCKET ClientSocket = accept(ListenSocket, (SOCKADDR*)&clientAddr, &clientLen);

    if (ClientSocket == INVALID_SOCKET) {
        cerr << "[서버] accept 실패: " << WSAGetLastError() << endl;
        return -1;
    }

    int x = 5, y = 5;

    while (true) {

        //flatbuffers::FlatBufferBuilder Builder(1024);

        //int number1 = rand() % 9998 + 1;
        //int number2 = rand() % 9998 + 1;

        //auto Data = Calculate::CreateData(Builder, number1, number2, '+');
        //Builder.Finish(Data);


        

        int size = 0;
        if (recv(ClientSocket, (char*)&size, sizeof(size), MSG_WAITALL) <= 0) break;
        size = ntohl(size);

        char buffer[1024] = {};
        if (recv(ClientSocket, buffer, size, MSG_WAITALL) <= 0) break;

        Document doc;
        doc.Parse(buffer);
        if (!doc.HasMember("Input")) continue;
        string dir = doc["Input"].GetString();

        if (dir == "w") y--;
        if (dir == "s") y++;
        if (dir == "a") x--;
        if (dir == "d") x++;

        PrintMap(x, y);

        // 응답
        Document resDoc;
        resDoc.SetObject();
        resDoc.AddMember("X", x, resDoc.GetAllocator());
        resDoc.AddMember("Y", y, resDoc.GetAllocator());

        StringBuffer sb;
        Writer<StringBuffer> writer(sb);
        resDoc.Accept(writer);

        int len = htonl(sb.GetSize());
        send(ClientSocket, (char*)&len, sizeof(len), 0);
        send(ClientSocket, sb.GetString(), sb.GetSize(), 0);
    }

    closesocket(ClientSocket);
    closesocket(ListenSocket);
    WSACleanup();
    return 0;
}
