//
// Created by Deer on 2022/6/14.
//

#include "CmdOutput.h"

CmdOutput::CmdOutput() = default;

void CmdOutput::PushContent(string &new_content) {
    ProcessNewContent(new_content);
    // 如果超出设置的最大长度则删除超出部分
    while (message_stack.size() > max_display_lines)
        message_stack.pop_front();
}

void CmdOutput::SetMaxSize(int &max_lines) {
    max_display_lines = max_lines * 1024 * 1024;
}

void CmdOutput::ClearContent() {
    content.clear();
}

void CmdOutput::ProcessNewContent(string &new_content) {
    vector<string> _msg;
    unsigned long _pos = 0;
    while (new_content.find('\n', _pos) != string::npos) {
        _msg.push_back(new_content.substr(_pos, new_content.find('\n', _pos) - _pos));
        _pos = new_content.find('\n', _pos) + 1;
    }
    for (auto &_m : _msg) {
        message_stack.push_back(paragraph(_m));
    }

    return;

/*
    // 寻找入栈消息中的所有消息头，并利用map特性自动排序
    map<unsigned long, single_message> content_index; // 消息顺序
    for (int i = 0; i < 3; i++){
        unsigned long pos = 0;
        while (new_content.find(int2type(i)) != string::npos){
            pos++;
            pos = new_content.find(int2type(i), pos);
            single_message message;
            message.head_type = int2type(i);
            message.head_begin_quote = new_content.rfind('[', pos);
            message.head_end_quote = new_content.find(']', pos);
            message.msg_head = new_content.substr(message.head_begin_quote, message.head_end_quote);
            content_index[pos] = message;
            if (pos == new_content.find_last_of(int2type(i)))
                break;
        }
    }
    // map转换为vector，设置每条消息的终止位
    vector<single_message> message_stack_vector;
    for (auto &item : content_index){
        item.second.body_end_position = new_content.size() - 1;
        message_stack_vector.push_back(item.second);
    }
    for (int i = 0; i < int(message_stack_vector.size()) - 1; i++)
        message_stack_vector[i].body_end_position = message_stack_vector[i+1].head_begin_quote - 1;
    // 将消息转换为UI原素（head和body分别放在不同的元素）并为head上色
    for (auto &item : message_stack_vector){
        Element msg_head = text(item.msg_head);
        Element msg_body = paragraph(new_content.substr(item.head_end_quote + 1, item.body_end_position - 1));
        if (item.head_type == "INFO") {
            message_stack.push_back(hbox({
                msg_head | color(Color::Green),
                msg_body,
            }));
        }
        else if (item.head_type == "WARN") {
            message_stack.push_back(hbox({
                msg_head | color(Color::Yellow),
                msg_body,
            }));
        }
        else if (item.head_type == "ERROR") {
            message_stack.push_back(hbox({
                msg_head | color(Color::Red),
                msg_body,
            }));
        }
        else {
            message_stack.push_back(hbox({
                msg_head,
                msg_body,
            }));
        }
    }
*/
}

Element CmdOutput::Render() {
    vector<Element> _messages;
    for (auto &item : message_stack)
        _messages.push_back(item);
    //return Renderer([this](){
        return vbox(_messages) | border | flex_grow;
    //});
}




