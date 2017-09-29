#include <jni.h>
#include "socketclient.h"
#include <linux/gpio.h>



#ifdef __cplusplus
extern "C"{
#endif

SocketClient *client= nullptr;


JNICALL JNIEXPORT
void  Java_com_example_xy_nativesocket_cpp_SocketClient_test(JNIEnv *env,jobject *obj,jstring ip,jint port){
    const char *localIp=env->GetStringUTFChars(ip,JNI_FALSE);
    __android_log_print(ANDROID_LOG_INFO,"xuye","%s",localIp);
    client=new SocketClient(localIp,port);
}

JNICALL JNIEXPORT
jboolean Java_com_example_xy_nativesocket_cpp_SocketClient_connect(JNIEnv *env,jobject *obj){
   if( client->connectServer()){
       return JNI_TRUE;
   }
    return JNI_FALSE;
};

JNICALL JNIEXPORT
void Java_com_example_xy_nativesocket_cpp_SocketClient_sendMsg(JNIEnv *env,jobject *obj,jstring msg){
    const char *nmsg=env->GetStringUTFChars(msg,JNI_FALSE);
    const int length= sizeof(nmsg);
    client->sendMsg(nmsg,length);
};

JNICALL JNIEXPORT
jbyteArray Java_com_example_xy_nativesocket_cpp_SocketClient_recvMsg(JNIEnv *env,jobject *obj){
    char *getdata=client->recvMsg();

    return getdata;
};

JNICALL JNIEXPORT
void Java_com_example_xy_nativesocket_cpp_SocketClient_closeSocket(JNIEnv *env,jobject *obj){
    client->closeSocket();
};


#ifdef __cplusplus
};
#endif
