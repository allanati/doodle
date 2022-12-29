#include <SFML/Graphics.hpp>
#include <time.h>
#include "Game.hpp"

int main()
{

    an::Game game;

    game.SetResolution(400, 533);
    game.SetCaption("Test game");

    game.Setup();

    game.Run();

    return 0;
}

