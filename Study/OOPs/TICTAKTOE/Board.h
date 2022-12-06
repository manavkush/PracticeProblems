#include<iostream>
#include<vector>

class Board {
        const int SIZE = 3;
        std::vector<std::vector<int>> grid;
    public:
        Board();
        void Display();
        void Move(int row, int col, int turn);
        bool Available(int row, int col);
        int getSize();
        std::vector<std::vector<int>> getGrid();
};