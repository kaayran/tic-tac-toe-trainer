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
    CellType winner;

public:
    Board() = default;

    Board(const Board& other) {
        cells = other.cells;
        winner = other.winner;
    };

    const std::vector<std::vector<BoardCell>>& GetCells() const { return cells; }

    bool CanSetCellValue(int cellIdx) const;
    bool CanSetCellValue(int row, int col) const;

    void SetupBoard();
    bool IsGameEnded() const;
    bool CheckTie() const;
    bool CheckWinner() const;
    CellType GetWinner() const;
    void SetCellValue(int row, int col, CellType value);
    void GetEmptyCells(std::vector<int>& emptyCells) const;
    bool TryMakeMove(MoveData moveData);

private:
    bool CheckRow(int row) const;
    bool CheckColumn(int col) const;
    bool CheckMainDiagonal() const;
    bool CheckAntiDiagonal() const;
};
