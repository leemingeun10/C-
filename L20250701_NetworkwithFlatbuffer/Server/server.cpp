// server.cpp 서버 클라 1대1 로 돌아가도록
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define NOMINMAX

#include <iostream>
#include <WinSock2.h>
#include <unordered_map>
#include <windows.h>
#include "flatbuffers/flatbuffers.h"
#include "UserEvents_generated.h"

#pragma comment(lib, "ws2_32")

struct Player {
    uint32_t id;
    uint16_t x, y;
};

std::unordered_map<uint32_t, Player> players;
uint32_t playerCounter = 1;

uint64_t GetTimeStamp() {
    return (uint64_t)time(NULL);
}

void SendPacket(SOCKET socket, flatbuffers::FlatBufferBuilder& builder) {
    int size = htonl(builder.GetSize());
    send(socket, (char*)&size, sizeof(size), 0);
    send(socket, (char*)builder.GetBufferPointer(), builder.GetSize(), 0);
}

bool RecvPacket(SOCKET socket, char* buffer) {
    int size = 0;
    if (recv(socket, (char*)&size, sizeof(size), MSG_WAITALL) <= 0) return false;
    size = ntohl(size);
    return recv(socket, buffer, size, MSG_WAITALL) > 0;
}

void CreateS2C_Login(flatbuffers::FlatBufferBuilder& builder, const Player& p) {
    auto msg = builder.CreateString("Login Success");
    UserEvents::Color color(100, 100, 255);
    auto login = UserEvents::CreateS2C_Login(builder, true, msg, p.x, p.y, &color, p.id);
    auto event = UserEvents::CreateEventData(builder, GetTimeStamp(), UserEvents::EventType_S2C_Login, login.Union());
    builder.Finish(event);
}

void CreateS2C_Move(flatbuffers::FlatBufferBuilder& builder, const Player& p) {
    auto move = UserEvents::CreateS2C_PlayerMoveData(builder, p.id, p.x, p.y);
    auto event = UserEvents::CreateEventData(builder, GetTimeStamp(), UserEvents::EventType_S2C_PlayerMoveData, move.Union());
    builder.Finish(event);
}

void CreateS2C_Logout(flatbuffers::FlatBufferBuilder& builder, uint32_t id) {
    auto msg = builder.CreateString("Goodbye");
    auto logout = UserEvents::CreateS2C_Logout(builder, id, true, msg);
    auto event = UserEvents::CreateEventData(builder, GetTimeStamp(), UserEvents::EventType_S2C_Logout, logout.Union());
    builder.Finish(event);
}

int main() {
    WSAData wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    SOCKET listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    SOCKADDR_IN addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(30303);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(listenSock, (SOCKADDR*)&addr, sizeof(addr));
    listen(listenSock, 1);

    SOCKET clientSock = accept(listenSock, nullptr, nullptr);
    char buffer[4096];

    while (RecvPacket(clientSock, buffer)) {
        auto evt = UserEvents::GetEventData(buffer);
        flatbuffers::FlatBufferBuilder builder;

        switch (evt->data_type()) {
        case UserEvents::EventType_C2S_Login: {
            auto login = evt->data_as_C2S_Login();
            Player p = { playerCounter++, 5, 5 };
            players[p.id] = p;
            std::cout << "[서버] 로그인 ID = " << p.id << std::endl;
            CreateS2C_Login(builder, p);
            SendPacket(clientSock, builder);
            break;
        }
        case UserEvents::EventType_C2S_PlayerMoveData: {
            auto move = evt->data_as_C2S_PlayerMoveData();
            auto& p = players[move->player_id()];
            switch (move->key_code()) {
            case 'w': p.y = std::max(0, p.y - 1); break;
            case 's': p.y = std::min(9, p.y + 1); break;
            case 'a': p.x = std::max(0, p.x - 1); break;
            case 'd': p.x = std::min(19, p.x + 1); break;
            }
            std::cout << "[서버] ID=" << p.id << " 위치=(" << p.x << ", " << p.y << ")\n";
            CreateS2C_Move(builder, p);
            SendPacket(clientSock, builder);
            break;
        }
        case UserEvents::EventType_C2S_Logout: {
            auto logout = evt->data_as_C2S_Logout();
            auto& p = players[logout->player_id()];
            std::cout << "[서버] ID=" << p.id << "가 로그아웃 "<< std::endl;
            players.erase(logout->player_id());
            CreateS2C_Logout(builder, logout->player_id());
            SendPacket(clientSock, builder);
            break;
        }
        }
    }

    closesocket(clientSock);
    closesocket(listenSock);
    WSACleanup();
    return 0;
}

//
//// 멀티로 돌아갈수 있도록
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#define NOMINMAX
//
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <unordered_map>
//#include <WinSock2.h>
//#include "flatbuffers/flatbuffers.h"
//#include "UserEvents_generated.h"
//
//#pragma comment(lib, "ws2_32")
//
//struct Player {
//    uint32_t id;
//    uint16_t x, y;
//};
//
//std::unordered_map<SOCKET, Player> players;
//std::mutex playerMutex;
//uint32_t playerCounter = 1;
//
//uint64_t GetTimeStamp() {
//    return (uint64_t)time(NULL);
//}
////
////void SendAllPlayerPositions(SOCKET targetSocket) {
////    flatbuffers::FlatBufferBuilder builder;
////    std::vector<flatbuffers::Offset<UserEvents::PlayerPosition>> posList;
////
////    {
////        std::lock_guard<std::mutex> lock(playerMutex);
////        for (const auto& [sock, player] : players) {
////            auto pos = UserEvents::CreatePlayerPosition(builder, player.id, player.x, player.y);
////            posList.push_back(pos);
////        }
////    }
////
////    auto vectorOffset = builder.CreateVector(posList);
////    auto list = UserEvents::CreateS2C_PlayerList(builder, vectorOffset);
////    auto event = UserEvents::CreateEventData(builder, GetTimeStamp(), UserEvents::EventType_S2C_PlayerList, list.Union());
////    builder.Finish(event);
////
////    SendPacket(targetSocket, builder);
////}
//
//
//void SendPacket(SOCKET socket, flatbuffers::FlatBufferBuilder& builder) {
//    int size = htonl(builder.GetSize());
//    send(socket, (char*)&size, sizeof(size), 0);
//    send(socket, (char*)builder.GetBufferPointer(), builder.GetSize(), 0);
//}
//
//bool RecvPacket(SOCKET socket, char* buffer) {
//    int size = 0;
//    if (recv(socket, (char*)&size, sizeof(size), MSG_WAITALL) <= 0) return false;
//    size = ntohl(size);
//    return recv(socket, buffer, size, MSG_WAITALL) > 0;
//}
//
//void CreateS2C_Login(flatbuffers::FlatBufferBuilder& builder, const Player& p) {
//    auto msg = builder.CreateString("Login Success");
//    UserEvents::Color color(100, 200, 255);
//    auto login = UserEvents::CreateS2C_Login(builder, true, msg, p.x, p.y, &color, p.id);
//    auto event = UserEvents::CreateEventData(builder, GetTimeStamp(), UserEvents::EventType_S2C_Login, login.Union());
//    builder.Finish(event);
//}
//
//void CreateS2C_Move(flatbuffers::FlatBufferBuilder& builder, const Player& p) {
//    auto move = UserEvents::CreateS2C_PlayerMoveData(builder, p.id, p.x, p.y);
//    auto event = UserEvents::CreateEventData(builder, GetTimeStamp(), UserEvents::EventType_S2C_PlayerMoveData, move.Union());
//    builder.Finish(event);
//}
//
//void CreateS2C_Logout(flatbuffers::FlatBufferBuilder& builder, uint32_t id) {
//    auto msg = builder.CreateString("Goodbye");
//    auto logout = UserEvents::CreateS2C_Logout(builder, id, true, msg);
//    auto event = UserEvents::CreateEventData(builder, GetTimeStamp(), UserEvents::EventType_S2C_Logout, logout.Union());
//    builder.Finish(event);
//}
//
//void HandleClient(SOCKET clientSock) {
//    char buffer[4096];
//    Player player;
//
//    while (RecvPacket(clientSock, buffer)) {
//        flatbuffers::FlatBufferBuilder builder;
//        auto evt = UserEvents::GetEventData(buffer);
//
//        switch (evt->data_type()) {
//        case UserEvents::EventType_C2S_Login: {
//            auto login = evt->data_as_C2S_Login();
//            player.id = playerCounter++;
//            player.x = 5;
//            player.y = 5;
//            {
//                std::lock_guard<std::mutex> lock(playerMutex);
//                players[clientSock] = player;
//            }
//            std::cout << "[서버] 로그인 ID = " << player.id << std::endl;
//            CreateS2C_Login(builder, player);
//            SendPacket(clientSock, builder);
//            break;
//        }
//        case UserEvents::EventType_C2S_PlayerMoveData: {
//            auto move = evt->data_as_C2S_PlayerMoveData();
//            {
//                std::lock_guard<std::mutex> lock(playerMutex);
//                auto& p = players[clientSock];
//                switch (move->key_code()) {
//                case 'w': p.y = std::max(0, p.y - 1); break;
//                case 's': p.y = std::min(9, p.y + 1); break;
//                case 'a': p.x = std::max(0, p.x - 1); break;
//                case 'd': p.x = std::min(19, p.x + 1); break;
//                }
//                std::cout << "[서버] ID=" << p.id << " 위치=(" << p.x << ", " << p.y << ")\n";
//                CreateS2C_Move(builder, p);
//            }
//            SendPacket(clientSock, builder);
//            break;
//        }
//        case UserEvents::EventType_C2S_Logout: {
//            auto logout = evt->data_as_C2S_Logout();
//            {
//                std::lock_guard<std::mutex> lock(playerMutex);
//                std::cout << "[서버] ID=" << players[clientSock].id << "가 로그아웃\n";
//                players.erase(clientSock);
//            }
//            CreateS2C_Logout(builder, logout->player_id());
//            SendPacket(clientSock, builder);
//            closesocket(clientSock);
//            return;
//        }
//        }
//    }
//
//    closesocket(clientSock);
//    {
//        std::lock_guard<std::mutex> lock(playerMutex);
//        players.erase(clientSock);
//    }
//    std::cout << "[서버] 클라이언트 연결 종료됨\n";
//}
//
//int main() {
//    WSAData wsa;
//    WSAStartup(MAKEWORD(2, 2), &wsa);
//
//    SOCKET listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//    SOCKADDR_IN addr = {};
//    addr.sin_family = AF_INET;
//    addr.sin_port = htons(30303);
//    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
//
//    bind(listenSock, (SOCKADDR*)&addr, sizeof(addr));
//    listen(listenSock, 5);
//
//    std::cout << "[서버] 대기 중...\n";
//    while (true) {
//        SOCKET clientSock = accept(listenSock, nullptr, nullptr);
//        std::thread(HandleClient, clientSock).detach();
//    }
//
//    closesocket(listenSock);
//    WSACleanup();
//    return 0;
//}
