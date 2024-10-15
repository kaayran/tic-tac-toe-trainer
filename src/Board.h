#pragma once

#include <vector>

#include "BoardCell.h"
#include "MoveData.h"


class Board
{
public:
    static constexpr int SIZE = 3;

private:
    std::vector<std::vector<BoardCell>> cells;

public:
    void SetupBoard();
    bool CheckWinner() { return false; }
    bool CheckTie() { return false; }
    std::vector<std::vector<BoardCell>> GetCells() { return cells; }
    void SetCellValue(int row, int col, CellType value);
    std::vector<int> GetEmptyCells();
    bool TryMakeMove(MoveData moveData);

private:
    bool CanSetCellValue(int cellIdx) const;
    bool CanSetCellValue(int row, int col) const;
};
