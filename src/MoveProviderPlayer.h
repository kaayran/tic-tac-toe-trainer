#pragma once

#include "MoveProviderBase.h"
#include "CellType.h"
#include "MoveData.h"

class MoveProviderPlayer : public MoveProviderBase
{
public:
    MoveProviderPlayer(CellType type)
    {
        cellType = type;
    }
    
    MoveData GenerateMove(Board board) override;
};
