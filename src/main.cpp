#include "main.h"
#include "interface/control/CmdInput.h"
#include "interface/control/CmdOutput.h"
#include "module/ChildSession.h"

int main() {
    std::cout << "  [ Project    ] : " << PROJ_NAME <<std::endl;
    std::cout << "  [ Cmake time ] : " << CMAKE_TIME <<std::endl;
    std::cout << "  [ Version    ] : " << PROJ_VERSION <<std::endl;
    std::string compile = COMPILE_VERSION;
    std::cout << "  [ Compile ID ] : " << compile <<std::endl;

    using namespace ftxui;


    shared_ptr<CmdOutput> cmdField = make_shared<CmdOutput>();

    std::thread r_thread([=](){
        shared_ptr<ChildSession> session = make_shared<ChildSession>();
        std::string file = "./run.sh";
        session->Start(file);
        std::string res;
        while (session->Get(res))
            cmdField->PushContent(res);
    });

    std::string reset_position;
    while (1){
        auto screen = Screen::Create(Dimension::Full(),Dimension::Full());
        Render(screen, cmdField->Render());
        std::cout << reset_position;
        screen.Print();
        reset_position = screen.ResetPosition();

        std::this_thread::sleep_for(0.5s);
    }
//    auto screen = ScreenInteractive::Fullscreen();
//    screen.Loop(cmdField->Render());
//    r_thread.join();

    return EXIT_SUCCESS;
}
