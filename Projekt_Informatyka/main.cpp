#include <iostream>
#include <time.h>
#include "BaseGame.h"


int main() 
{
    srand(time(NULL));
    BaseGame game;
    game.start();
    return 0;
}

