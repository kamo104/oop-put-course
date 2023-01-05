#include <stdio.h>
#include <iostream>
#include <string>
#include <exception>
#include <cassert>

#include "FakeFootballGame.h"
#include "Game.h"


int main(){

    FakeFootballGame game;

    std::cout << game.result() << "\n";

    assert(game.result()=="3:2");
    
    std::cout << "wynik poprawny";
    return 0;
}