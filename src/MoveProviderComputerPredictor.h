#pragma once

#include <MoveProviderBase.h>

class MoveProviderComputerPredictor : public MoveProviderBase {
public:
    MoveProviderComputerPredictor(const CellType type) {
        cellType = type;
    }

    MoveData GenerateMove(Board board) override;

private:
    int MinMax(const Board &board, int depth, int isMax, int alpha, int beta);
};
