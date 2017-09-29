//
// Created by xuye on 2017/9/28.
//

#ifndef ANDROIDSTUDY_ASYNCCLIENT_H
#define ANDROIDSTUDY_ASYNCCLIENT_H

#include <jni.h>
#include <pthread.h>
class AsyncClient {
public:
    AsyncClient(JNIEnv *);
    ~AsyncClient();
    void start(void *);

private :
    JavaVM *jvm= nullptr;
    JNIEnv* env = nullptr;

    pthread_t  thread;
    pthread_mutex_t mutex;

};


#endif //ANDROIDSTUDY_ASYNCCLIENT_H
