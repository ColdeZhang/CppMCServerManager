cmake_minimum_required(VERSION 3.22)

add_executable(CppMCServerManager main.cpp module/VirtualShell.cpp module/VirtualShell.h module/ChildSession.cpp module/ChildSession.h main.h interface/CommonComponent.cpp interface/CommonComponent.h interface/control/CmdInput.cpp interface/control/CmdInput.h interface/control/CmdOutput.cpp interface/control/CmdOutput.h interface/CommonElement.cpp interface/CommonElement.h)

target_link_libraries(CppMCServerManager
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
        )
