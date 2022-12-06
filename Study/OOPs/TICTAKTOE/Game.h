#include<iostream>
#include"Board.h"
class Game {
        Board *board;
        int turn;
    public:
        Game();
        bool MakeMove();
        int GameDone();
        void StartGame();
};