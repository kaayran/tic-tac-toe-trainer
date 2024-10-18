#pragma once

#include "MoveProviderBase.h"
#include "CellType.h"
#include "MoveData.h"

class MoveProviderComputer : public MoveProviderBase
{
public:
    MoveProviderComputer(const CellType type)
    {
        cellType = type;
    }
    
    MoveData GenerateMove(Board board) override;
};
