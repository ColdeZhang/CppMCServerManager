//
// Created by Deer on 2022/6/12.
//

#ifndef CPPMCSERVERMANAGER_CMDINPUT_H
#define CPPMCSERVERMANAGER_CMDINPUT_H

#include "../../main.h"
#include "../CommonComponent.h"

using namespace ftxui;
using namespace std;

class CmdInput : public CommonComponent{
public:
    CmdInput();

private:
    std::string command;
    Component input_box;
    Component send_button;
};


#endif //CPPMCSERVERMANAGER_CMDINPUT_H
