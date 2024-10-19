#pragma once

#include "Board.h"
#include "CellType.h"
#include "MoveData.h"


class MoveProviderBase
{
protected:
    CellType cellType = CellType::TOE;

public:
    virtual ~MoveProviderBase() = default;

    virtual MoveData GenerateMove(Board board) { return {};}
};