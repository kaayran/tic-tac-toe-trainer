#pragma once

#include <vector>

struct BoardCell
{
public:
    int value; // 0 - Empty, 1 - X, 2 - O
public:
    BoardCell()
    {
        value = 0;
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
    std::vector<std::vector<BoardCell>> GetCells() {return cells;}
};