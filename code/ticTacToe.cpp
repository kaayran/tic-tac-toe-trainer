#include "ticTacToe.h"

#include <iostream>
#include <vector>

void DrawBoard(const std::vector<std::vector<char>>& board)
{
    const int size = board.size();
    
    std::cout << std::endl;
    
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            std::cout << board[row][col];
            if (col < size - 1) std::cout << "   ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool CanSetCell(const std::vector<std::vector<char>>& board, const char rowIdx, const char colIdx)
{
    if (board[rowIdx][colIdx] == GetCellTypeSymbol(CELL_TYPE::EMPTY)){
        return true;
    }
    
    return false;
}

void SetCell(std::vector<std::vector<char>>& board, const char rowIdx, const char colIdx, const CELL_TYPE type)
{
    board[rowIdx][colIdx] = GetCellTypeSymbol(type);
}

char GetCellTypeSymbol(const CELL_TYPE type)
{
    switch (type) {
    case CELL_TYPE::EMPTY:
        return '*';
    case CELL_TYPE::TIC:
        return 'X';
    case CELL_TYPE::TAC:
        return 'O';
    default:
        return '*';
    }
}

void TrySetCell(std::vector<std::vector<char>>& board, const char rowIdx, const char colIdx, const CELL_TYPE type)
{
    if (CanSetCell(board, rowIdx, colIdx)){
        SetCell(board, rowIdx, colIdx, type);
    }
}
