#include "MoveProviderBase.h"

MoveData::MoveData(const CellType type, const int row, const int col)
{
    cellType = type;
    cellRowIdx = row;
    cellColIdx = col;
}

MoveData::MoveData(const CellType type, const int cellIdx)
{
    cellType = type;
    cellRowIdx = cellIdx / Board::SIZE;
    cellColIdx = cellIdx % Board::SIZE;
}