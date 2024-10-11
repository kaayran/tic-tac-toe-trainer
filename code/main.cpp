#include <iostream>
#include <vector>

#include "ticTacToe.h"

int main(int argc, char* argv[])
{
    std::cout << "Hi! Welcome to Tic-Tac-Toe Trainer!\n";

    constexpr int BOARD_SIZE = 3;
    std::vector<std::vector<char>> board(BOARD_SIZE, std::vector<char>(BOARD_SIZE, '*'));
    
    DrawBoard(board);
    TrySetCell(board, 0, 0, CELL_TYPE::TAC);
    TrySetCell(board, 1, 1, CELL_TYPE::TIC);
    DrawBoard(board);
    
    std::cin.get();
}
