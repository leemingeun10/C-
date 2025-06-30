#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define NOMINMAX

#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <conio.h>  // 키 입력을 실시간으로 받기 위해 필요
#include"flatbuffers/flatbuffers.h"
#include "Calculate_generated.h"

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

    SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    SOCKADDR_IN addr = {};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(30303);

    if (connect(s, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR) {
        cerr << "[클라] 서버 연결 실패: " << WSAGetLastError() << endl;
        return -1;
    }

    cout << "[클라] 서버 연결 성공" << endl;

    while (true) {
    
        

        char input = _getch();  // 엔터 없이 키 입력

        if (input != 'w' && input != 'a' && input != 's' && input != 'd')
            continue;  // w/a/s/d 외에는 무시

        Document doc;
        doc.SetObject();
        Value val;
        val.SetString(&input, 1, doc.GetAllocator());
        doc.AddMember("Input", val, doc.GetAllocator());

        StringBuffer sb;
        Writer<StringBuffer> writer(sb);
        doc.Accept(writer);

        int len = htonl(sb.GetSize());
        send(s, (char*)&len, sizeof(len), 0);
        send(s, sb.GetString(), sb.GetSize(), 0);

        // 응답
        len = 0;
        if (recv(s, (char*)&len, sizeof(len), MSG_WAITALL) <= 0) break;
        len = ntohl(len);

        char buffer[1024] = {};
        if (recv(s, buffer, len, MSG_WAITALL) <= 0) break;

        Document res;
        res.Parse(buffer);
        int x = res["X"].GetInt();
        int y = res["Y"].GetInt();

        PrintMap(x, y);

    }

    closesocket(s);
    WSACleanup();
    return 0;
}
