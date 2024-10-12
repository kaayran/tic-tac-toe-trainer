#pragma once

#include <vector>

enum class CellType
{
    TIC,    // X
    TAC,    // O
    TOE     // Empty
};

struct BoardCell
{
public:
    CellType value;
public:
    BoardCell()
    {
        value = CellType::TOE;
    }
};

class Board
{
public:
    static constexpr int SIZE = 3;

private:
    std::vector<std::vector<BoardCell>> cells;

public:
    void SetupBoard();
    bool CheckWinner();
    bool CheckTie();
    std::vector<std::vector<BoardCell>> GetCells() { return cells; }
    bool TrySetCellValue(int cellIdx, CellType value);
private:
    bool CanSetCellValue(int cellIdx) const;
    bool CanSetCellValue(int row, int col) const;
};
