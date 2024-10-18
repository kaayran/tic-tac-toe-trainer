#pragma once

#include "MoveProviderBase.h"
#include "CellType.h"
#include "MoveData.h"

class MoveProviderPlayer : public MoveProviderBase {
public:
    MoveProviderPlayer(const CellType type) {
        cellType = type;
    }

    MoveData GenerateMove(Board board) override;

private:
    bool IsInRange(int cellNum);
};
