#pragma once
#include <vector>

enum class CELL_TYPE
{
    EMPTY,
    TIC, // X
    TAC // O
};

void DrawBoard(const std::vector<std::vector<char>>& board);

bool CanSetCell(const std::vector<std::vector<char>>& board, char rowIdx, char colIdx);
void SetCell(std::vector<std::vector<char>>& board, char rowIdx, char colIdx, CELL_TYPE type);
char GetCellTypeSymbol(CELL_TYPE type);
void TrySetCell(std::vector<std::vector<char>>& board, char rowIdx, char colIdx, CELL_TYPE type);