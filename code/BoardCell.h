#pragma once

#include "CellType.h"

struct BoardCell
{
public:
    CellType value;

public:
    BoardCell()
    {
        value = CellType::TOE;
    }

    bool IsEmpty() { return value == CellType::TOE; }
};
