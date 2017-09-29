package com.example.xy.nativesocket;

import android.app.Activity;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.view.View;
import android.widget.EditText;
import android.widget.LinearLayout;

import com.example.xy.nativesocket.cpp.SocketClient;

/**
 * Created by xy on 2017/9/20.
 */

public class MainActivity extends Activity {
    private SocketClient client;
    private LinearLayout mRecvContent;
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);


        setContentView(R.layout.main_activity);
        mRecvContent= (LinearLayout) findViewById(R.id.recvcontent);
        client=new SocketClient();
        findViewById(R.id.test).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                final String ip=((EditText)findViewById(R.id.ip)).getText().toString();
                String port=((EditText)findViewById(R.id.input)).getText().toString();
                final  int p=Integer.valueOf(port);
                final String text=((EditText)findViewById(R.id.text)).getText().toString();
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        client.test(ip,p);
                        client.connect();
                        client.sendMsg(text);
//                        char recive=client.recvMsg();
//                        String recvdata=new String(recive);
                        client.closeSocket();
                    }
                }).start();
            }
        });
    }
}
