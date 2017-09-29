//
// Created by xy on 2017/9/20.
//
#ifndef NATIVESOCKET_SOCKETCLIENT_H
#define NATIVESOCKET_SOCKETCLIENT_H
#include <sys/types.h>
#include <jni.h>
#include <android/log.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

class SocketClient {
public :
    SocketClient(const char *ip,const uint16_t port);
    ~SocketClient();
    bool connectServer();
    void sendMsg(const char *msg,size_t length);
    char *recvMsg();
    void closeSocket();
private :
    int socketId=-1;
    struct sockaddr_in serverAddr;
};


#endif //NATIVESOCKET_SOCKETCLIENT_H
