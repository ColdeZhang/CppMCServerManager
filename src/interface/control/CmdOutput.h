//
// Created by Deer on 2022/6/14.
//

#ifndef CPPMCSERVERMANAGER_CMDOUTPUT_H
#define CPPMCSERVERMANAGER_CMDOUTPUT_H

#include "../../main.h"
#include "../CommonElement.h"

using namespace ftxui;
using namespace std;

struct single_message{
    unsigned long head_begin_quote = 0; // [
    unsigned long head_end_quote;   // ]
    string head_type;   // "INFO" or "ERROR" or "WARN"
    string msg_head;    // "[00:00:00 INFO]"
    unsigned long body_end_position;
};

class CmdOutput{
public:
    CmdOutput();

    /*!
     * @brief 向控制台填入数据
     */
    void PushContent(string &new_content);

    /*!
     * @brief 清空控制台
     */
    void ClearContent();

    /*!
     * @brief 设置控制台输出内容的最大条数
     * @param max_lines 最大条数
     * @details 最大不建议超过500行，否则可能会导致严重的卡顿
     */
    void SetMaxSize(int &max_lines);

    Element Render();

private:
    // 将传入的消息进行格式化处理
    void ProcessNewContent(string &new_content);
    int max_display_lines = 100;
    string content;
    Element body;
    // shared_ptr<list<Element>> message_stack;
    list<Element> message_stack;

    static string int2type(int i){
        switch (i) {
            case 0:
                return "INFO";
            case 1:
                return "WARN";
            case 2:
                return "ERROR";
            default:
                return "UNKNOWN";
        }
    }

};


#endif //CPPMCSERVERMANAGER_CMDOUTPUT_H
