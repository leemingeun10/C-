#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define NOMINMAX

#include <iostream>
#include <WinSock2.h>
#include <conio.h>
#include <Windows.h>
#include "flatbuffers/flatbuffers.h"
#include "UserEvents_generated.h"

#pragma comment(lib, "ws2_32")

SOCKET clientSocket;
uint32_t playerId = 0;
int posX = 5, posY = 5;

void PrintMap() {
    system("cls");
    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 20; ++x)
            std::cout << (x == posX && y == posY ? '*' : '.');
        std::cout << "\n";
    }
}

uint64_t GetTimeStamp() { return (uint64_t)time(NULL); }

void SendPacket(flatbuffers::FlatBufferBuilder& builder) {
    int size = htonl(builder.GetSize());
    send(clientSocket, (char*)&size, sizeof(size), 0);
    send(clientSocket, (char*)builder.GetBufferPointer(), builder.GetSize(), 0);
}

bool RecvPacket(char* buffer) {
    int size;
    if (recv(clientSocket, (char*)&size, sizeof(size), MSG_WAITALL) <= 0) return false;
    size = ntohl(size);
    return recv(clientSocket, buffer, size, MSG_WAITALL) > 0;
}

void SendLogin() {
    flatbuffers::FlatBufferBuilder builder;
    auto login = UserEvents::CreateC2S_Login(builder, builder.CreateString("username"), builder.CreateString("password"));
    auto event = UserEvents::CreateEventData(builder, GetTimeStamp(), UserEvents::EventType_C2S_Login, login.Union());
    builder.Finish(event);
    SendPacket(builder);
}

void SendMove(char key) {
    flatbuffers::FlatBufferBuilder builder;
    auto move = UserEvents::CreateC2S_PlayerMoveData(builder, playerId, posX, posY, key);
    auto event = UserEvents::CreateEventData(builder, GetTimeStamp(), UserEvents::EventType_C2S_PlayerMoveData, move.Union());
    builder.Finish(event);
    SendPacket(builder);
}

void SendLogout() {
    flatbuffers::FlatBufferBuilder builder;
    auto logout = UserEvents::CreateC2S_Logout(builder, playerId);
    auto event = UserEvents::CreateEventData(builder, GetTimeStamp(), UserEvents::EventType_C2S_Logout, logout.Union());
    builder.Finish(event);
    SendPacket(builder);
}

void ProcessPacket(const char* buffer) {
    auto evt = UserEvents::GetEventData(buffer);
    switch (evt->data_type()) {
    case UserEvents::EventType_S2C_Login: {
        auto data = evt->data_as_S2C_Login();
        posX = data->position_x();
        posY = data->position_y();
        playerId = data->player_id();
        std::cout << "[클라] 로그인 성공! ID: " << playerId << "\n";
      
        break;
    }
    case UserEvents::EventType_S2C_PlayerMoveData: {
        auto data = evt->data_as_S2C_PlayerMoveData();
        posX = data->position_x();
        posY = data->position_y();
        PrintMap();
        break;
    }
    case UserEvents::EventType_S2C_Logout: {
        std::cout << "[클라] 서버로부터 로그아웃 응답.\n";
        exit(0);
    }
    }
}

int main() {
    WSAData wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    SOCKADDR_IN addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(30303);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int result = connect(clientSocket, (SOCKADDR*)&addr, sizeof(addr));
    if (result == SOCKET_ERROR) {
        std::cerr << "연결 실패: " << WSAGetLastError() << std::endl;
        return 1;
    }
    std::cout << "[클라] 서버에 연결 성공\n";

    SendLogin();

    char buffer[4096] = {};
    if (RecvPacket(buffer)) {
        ProcessPacket(buffer); // 로그인 결과 처리
    }

    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 'q') {
                SendLogout();
                if (RecvPacket(buffer)) ProcessPacket(buffer);
                break;
            }
            else if (key == 'w' || key == 'a' || key == 's' || key == 'd') {
                SendMove(key);
                if (RecvPacket(buffer)) ProcessPacket(buffer);
            }
        }
    }

    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
