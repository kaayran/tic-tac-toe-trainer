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

    bool IsEmpty() const { return value == CellType::TOE; }
};
