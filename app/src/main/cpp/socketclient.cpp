//
// Created by xy on 2017/9/20.
//

#include "socketclient.h"
SocketClient::SocketClient(const char *ip,const uint16_t port) {
    socketId=socket(AF_INET,SOCK_STREAM,IPPROTO_IP);
    memset(&serverAddr,0, sizeof(serverAddr));
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_port=htons(port);
    inet_aton(ip,&serverAddr.sin_addr);
}

SocketClient::~SocketClient() {
    closeSocket();
}

bool SocketClient::connectServer() {
    return connect(socketId,(const sockaddr*)&serverAddr, sizeof(sockaddr));
}

void SocketClient::sendMsg(const char *msg,size_t length) {
    send(socketId,msg,length,0);
}

char* SocketClient::recvMsg() {
    char *buf;
    int size=1024;
    int count=recv(socketId,buf, 1024,0);
    return buf;
}

void SocketClient::closeSocket() {
    close(socketId);
}

