package com.example.xy.nativesocket.cpp;

/**
 * Created by xy on 2017/9/20.
 */

public class SocketClient {
    static {
        System.loadLibrary("native-lib");
    }

    public native void test(String ip,int port);
    public native boolean connect();
    public native void sendMsg(String msg);
    public native byte[] recvMsg();
    public native void closeSocket();

}
