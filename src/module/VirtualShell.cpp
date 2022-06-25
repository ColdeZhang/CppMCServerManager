//
// Created by Deer on 2022/6/7.
//

#include "VirtualShell.h"

VirtualShell::VirtualShell(const std::string& command) {
    pipe = popen(command.c_str(), "r");
    if (pipe == nullptr) {
        throw std::runtime_error("pipe open failed!");
    }

    res_thread = std::make_shared<std::thread>([this]()mutable {
        while(!stop){
            char res[1024]{};
            while(fgets(res, sizeof res, pipe) != nullptr && !over_size){
                std::unique_lock<std::mutex> lock(lck);
                res_buffer += res;
                if (res_buffer.size() > BUFF_SIZE) over_size = true;
            }
        }
    });
}

VirtualShell::~VirtualShell() {
    Stop();
}

void VirtualShell::Stop() {
    stop = true;
    pclose(pipe);
    res_thread->join();
}

bool VirtualShell::Do(const std::string &command) {
    if (fputs(command.c_str(), pipe)) {
        return true;
    }else{
        return false;
    }
}

bool VirtualShell::GetResult(std::string &result) {
    std::unique_lock<std::mutex> lock(lck);
    if (res_buffer.empty()) {
        result = res_buffer;
        return false;
    }
    if (!over_size) {
        result = res_buffer;
    }else{
        result = res_buffer + "\n[ Have removed massive message to avoid lagging, please look up logs for skipped message. ]";
    }
    res_buffer.clear();
    return true;
}
