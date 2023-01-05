
#ifndef FAKE_FOOTBALL_GAME_H
#define FAKE_FOOTBALL_GAME_H

#include <string>

#include "Game.h"


class FakeFootballGame : public Game{
    public:
    std::string result(){
        return "3:1";
    }
    FakeFootballGame(){}
};


#endif