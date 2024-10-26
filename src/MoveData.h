#pragma once
#include "CellType.h"

struct MoveData
{
    CellType cellType;
    int cellRowIdx;
    int cellColIdx;

    MoveData() = default;
    MoveData(CellType inCellType, int row, int col);
    MoveData(CellType inCellType, int cellIdx);
};
