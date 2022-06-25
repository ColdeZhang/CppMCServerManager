//
// Created by Deer on 2022/6/8.
//

#include "ChildSession.h"

ChildSession::ChildSession() = default;

bool ChildSession::Stop() const {
    // 结束进程
    if(kill(session_pid, SIGTERM)==0)
        return true;
    else
        return false;
}

ChildSession::~ChildSession() {
    Stop();
}

bool ChildSession::Do(const std::string& command) {
    std::string _command = command + "\n";
    const char *_cmd = _command.c_str();
    write(put_pipe[1], _cmd, strlen(_cmd));
    return false;
}

bool ChildSession::Get(std::string& message, int buff) {
    char *_msg = new char[buff];
    if (read(get_pipe[0], _msg, buff)==0)
        return false;
    message = std::string(_msg);
    return true;
}

bool ChildSession::Start(std::string &file) {
    if(pipe(put_pipe)==-1||pipe(get_pipe)==-1){
        std::cout<<"pipe open error."<<std::endl;
        return false;
    }

    session_pid = fork();
    if (session_pid == 0)
    {
        // 以下为子进程
        dup2(put_pipe[0], STDIN_FILENO);
        dup2(get_pipe[1], STDOUT_FILENO);
        dup2(get_pipe[1], STDERR_FILENO);

        close(put_pipe[1]);
        close(get_pipe[0]);

        // 在MacOS平台不起效
        // prctl(PR_SET_PDEATHSIG, SIGTERM);

        // 在子进程启动脚本 替换子进程内容
        execlp(file.c_str(),  (char*) nullptr);
    }

    session_pid++;
    // 关闭父进程多余的管道端口
    close(put_pipe[0]);
    close(get_pipe[1]);

    return true;
}

int ChildSession::GetChildPID() const {
    return session_pid;
}






