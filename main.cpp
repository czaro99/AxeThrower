#include "Game.h"

using namespace sf;
using namespace std;

int main()
{
    Game game;
    srand(time(NULL));

    while (game.getWindowIsOpen()) {

        game.updateDeltaTime();

        game.update();

        game.render();


    }


    return 0;

}
