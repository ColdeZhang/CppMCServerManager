//
// Created by Deer on 2022/6/7.
//

#ifndef CPPMCSERVERMANAGER_VIRTUALSHELL_H
#define CPPMCSERVERMANAGER_VIRTUALSHELL_H

#define BUFF_SIZE 10240
#include <string>
#include <cstdio>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include <mutex>


class VirtualShell {
public:
    explicit VirtualShell(const std::string& command);
    virtual ~VirtualShell();

    // 停止任务并关闭相关线程回收资源
    void Stop();

    // 执行命令
    bool Do(const std::string& command);

    // 获取控制台运行内容
    bool GetResult(std::string& result);


private:
    std::shared_ptr<std::thread> res_thread;
    FILE * pipe = nullptr;
    std::string res_buffer;
    std::mutex lck;
    bool stop = false;
    bool over_size = false;
};



#endif //CPPMCSERVERMANAGER_VIRTUALSHELL_H
