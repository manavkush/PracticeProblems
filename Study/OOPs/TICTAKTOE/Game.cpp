#include<iostream>
#include"Game.h"

Game::Game() {
    board = new Board();
    turn = 0;
}

void Game::StartGame() {
    std::cout<<"Starting the Game:\n";
    board->Display();
    bool done = 0;
    do {
        done = MakeMove();
    } while(!done);
}

bool Game::MakeMove() {
    int row, col;
    std::cout<<"Player "<<turn+1<<"'s turn\n";
    std::cout<<"Enter the row: ";
    std::cin>>row;
    std::cout<<"Enter the col: ";
    std::cin>>col;

    if(board->Available(row, col)==false) {
        std::cout<<"\nCell already filled. Make the move again\n";
        board->Display();
        return MakeMove();
    } else {
        board->Move(row, col, turn);
        if(turn==1) {
            turn = 0;
        } else {
            turn = 1;
        }
    }
    
    board->Display();
    int winner = GameDone();
    bool done = 0;

    if(winner==0) {
        std::cout<<"Player 1 is winner\n";
        done = 1;
    } else if(winner == 1) {
        std::cout<<"Player 2 is winner\n";
        done = 1;
    } else if(winner==-1) {
        std::cout<<"Game is Drawn\n";
        done = 1;
    }
    return done;
}

int Game::GameDone() {
    int SIZE = board->getSize();
    std::vector<std::vector<int>> grid = board->getGrid();
    int winner = -1;
    
    for(int row=0;row<SIZE;row++) {
        for(int col=0; col<SIZE; col++) {
            if(grid[row][col]==-1)
                winner = 2;
        }
    }

    if((grid[0][0] == grid[0][1]) and (grid[0][1] == grid[0][2]) and grid[0][1]!=-1) {
        winner = grid[0][1];
    } else if(grid[2][0] == grid[2][1] and grid[2][1] == grid[2][2] and grid[2][1]!=-1) {
        winner = grid[2][1];
    } else if(grid[0][0] == grid[1][0] and grid[1][0] == grid[2][0] and grid[2][0]!=-1) {
        winner = grid[1][0];
    } else if(grid[0][2]==grid[1][2] and grid[1][2]==grid[2][2] and grid[2][2]!=-1) {
        winner = grid[0][2];
    } else {
        if(grid[1][1]!=-1) {
            if(grid[0][1]==grid[2][1] and grid[0][1]==grid[1][1]) {
                winner = grid[1][1];
            } else if(grid[1][0]==grid[1][1] and grid[1][1]==grid[1][2]) {
                winner = grid[1][1];
            } else if(grid[0][0]==grid[1][1] and grid[1][1]==grid[2][2]) {
                winner = grid[1][1];
            } else if(grid[0][2]==grid[1][1] and grid[2][0]==grid[1][1]) {
                winner = grid[0][1];
            }
        }
    }
    return winner;
}
