cmake_minimum_required(VERSION 3.22)

add_executable(ChildSessionTest main.cpp ../../src/module/ChildSession.cpp ../../src/module/ChildSession.h)

target_link_libraries(CppMCServerManager
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
        )