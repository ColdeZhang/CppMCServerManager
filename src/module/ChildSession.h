//
// Created by Deer on 2022/6/8.
//

#ifndef CPPMCSERVERMANAGER_CHILDSESSION_H
#define CPPMCSERVERMANAGER_CHILDSESSION_H

#include "../main.h"

#define MESSAGE_BUFF 1024

/*!
 * @brief 创建一个子进程
 */
class ChildSession {
public:
    ChildSession();
    ~ChildSession();

    /*!
     * @brief 启动子进程
     * @param file 子进程执行的脚本文件
     * @return 成功返回true，失败返回false
     */
    bool Start(std::string &file);

    /*!
     * @brief 停止子进程
     * @details 停止子进程，并关闭相关进程回收资源。
     * 不是非必需，对象在折构时会自动调用。
     * @return 成功返回true，失败返回false
     */
    bool Stop() const;

    /*!
     * @brief 发送消息至子进程执行
     * @param command 命令
     */
    bool Do(const std::string& command);

    /*!
     * @brief 获取子进程的输出内容
     * @details 最好开一个线程轮训读取子进程的输出内容。
     * 如果子进程是一个程序的持续输出，在程序结束前此方法会一直返回true。
     * @param message 输出内容
     * @param buff 输出缓冲大小(默认1024)
     * @return 能读取到信息时true，子进程结束时返回false
     */
    bool Get(std::string& message, int buff = 1024);

    /*!
     * @brief 获取子进程的进程PID
     * @return 子进程PID
     */
    int GetChildPID() const;
private:
    pid_t session_pid{};  // 子进程pid
    int put_pipe[2]{};    // 命令发送管道-[1]
    int get_pipe[2]{};    // 结果接收管道-[0]
};


#endif //CPPMCSERVERMANAGER_CHILDSESSION_H
