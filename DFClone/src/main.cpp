#include <iostream>

#include "DF/Game.hpp"
#include "Framework/Error.hpp"
#include "Framework/Global.hpp"
#include "Framework/Window.hpp"
#include "Framework/WindowConfiguration.hpp"

int main()
{
    try
    {
        Framework::GlobalInit();

        Framework::WindowConfiguration windowConfiguration{800, 600, "Dwarf Fortress Clone"};
        Framework::Window              window(windowConfiguration);

        std::unique_ptr<DF::Game> game = DF::Game::CreateFirstDebug();

        window.SetScreen(std::move(game));
        window.MainLoop();
    }
    catch (const Framework::Error& e)
    {
        std::cerr << "Error: " << e.GetMessage();

        if (e.GetAdditionalMessage())
        {
            std::cerr << ". " << *e.GetAdditionalMessage();
        }

        std::cerr << std::endl;

        Framework::GlobalDeInit();
        return 1;
    }

    Framework::GlobalDeInit();
    return 0;
}
