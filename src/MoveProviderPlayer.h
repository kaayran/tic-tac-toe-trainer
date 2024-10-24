#pragma once

#include "MoveProviderBase.h"
#include "CellType.h"
#include "MoveData.h"

class MoveProviderPlayer : public MoveProviderBase {
public:
    MoveProviderPlayer(const CellType type) {
        cellType = type;
    }

    MoveData GenerateMove(const Board &board) override;
};
