//
// Created by xuye on 2017/9/28.
//

#include "asyncclient.h"

AsyncClient::AsyncClient(JNIEnv *env) {
    if(env){
        this->env=env;
        env->GetJavaVM(&jvm);
    }
}

AsyncClient::~AsyncClient() {
    if(jvm){
        jvm.
    }
}


void AsyncClient::start(void *mtd) {
    pthread_mutex_init(&mutex, nullptr);
   int tid= pthread_create(mtd);


}