#include "MoveProviderBase.h"

#include <random>

#include "MoveProviderComputer.h"

MoveData::MoveData(const CellType type, const int row, const int col)
{
    cellType = type;
    boardRowIdx = row;
    boardColIdx = col;
}

MoveData::MoveData(const CellType type, const int boardIdx)
{
    cellType = type;
    boardRowIdx = boardIdx / Board::SIZE;
    boardColIdx = boardIdx % Board::SIZE;
}