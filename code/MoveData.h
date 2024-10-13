#pragma once
#include "CellType.h"

struct MoveData
{
public:
    CellType cellType;
    int boardRowIdx;
    int boardColIdx;
    
public:
    MoveData() = default;
    MoveData(CellType cellType, int row, int col);
    MoveData(CellType cellType, int boardIdx);
};
