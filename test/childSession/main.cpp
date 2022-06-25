//
// Created by Deer on 2022/6/11.
//
#include <iostream>
#include <thread>
#include <string>
#include "../../src/module/ChildSession.h"

int main() {
    std::string file;
    std::cout<<"输入控制台执行shell脚本的绝对位置：";
    getline(std::cin, file);

    std::shared_ptr<ChildSession> exe;

    std::thread r_thread([&]() {
        exe = std::make_shared<ChildSession>();
        exe->Start(file);
        std::string res;
        while (exe->Get(res))
            std::cout<<res;
    });

    std::string cmd;
    while(cmd != "stop"){
        getline(std::cin, cmd);
        exe->Do(cmd);
    }

    exe->Stop();
    r_thread.join();

    return 0;
}
