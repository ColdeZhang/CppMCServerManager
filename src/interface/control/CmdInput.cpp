//
// Created by Deer on 2022/6/12.
//

#include "CmdInput.h"

CmdInput::CmdInput() {
    input_box = Input(&command, "type something...") | bgcolor(Color::Black);
    send_button = Button("执行", [&]{
        std::cout << "send command: " << command << std::endl;
        command = "";
    }, ButtonOption::Animated(Color::Black, Color::White, Color::Yellow, Color::Green));

    this->body = Renderer(input_box, [&]{
        return hbox({
            hbox({
                text("> "),
                input_box->Render(),
            }) | border | flex,
            send_button->Render(),
        });
    });
}

