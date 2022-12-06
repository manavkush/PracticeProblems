#include<iostream>
#include"Board.h"

Board::Board() {
    grid.assign(SIZE, std::vector<int> (SIZE, -1));
}

void Board::Move(int row, int col, int turn) {
    grid[row][col] = turn;
}

int Board::getSize() {
    return SIZE;
}

void Board::Display() {
    std::cout<<"\n";
    for(int row = 0; row<SIZE; row++) {
        for(int col = 0; col<SIZE; col++) {
            if(grid[row][col]==0) {
                std::cout<<" 0 ";
            } else if(grid[row][col]==1) {
                std::cout<<" X ";
            } else {
                std::cout<<" - ";
            }
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

bool Board::Available(int row, int col) {
    if(grid[row][col]==-1) {
        return true;
    } else {
        return false;
    }
}

std::vector<std::vector<int>> Board::getGrid() {
    return grid;
}
