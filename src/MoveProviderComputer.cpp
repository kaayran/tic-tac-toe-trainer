#include "MoveProviderComputer.h"

#include <random>

MoveData MoveProviderComputer::GenerateMove(Board board)
{
    std::vector<int> cells;
    board.GetEmptyCells(cells);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribution(0, cells.size() - 1);
    
    const int randomIdx = distribution(gen);

    return MoveData{cellType, cells[randomIdx]};
}
