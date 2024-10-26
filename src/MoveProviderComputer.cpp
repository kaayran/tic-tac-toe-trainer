#include "MoveProviderComputer.h"

#include <random>

MoveData MoveProviderComputer::GenerateMove(const Board &board)
{
    const auto& cells = board.GetEmptyCells();

    std::random_device rd;
    std::mt19937 gen(rd());
    const std::vector<int>::size_type cellsSize = cells.size();
    std::uniform_int_distribution<std::vector<int>::size_type> distribution(0, cellsSize - 1);
    
    const std::vector<int>::size_type randomIdx = distribution(gen);

    return MoveData{cellType, cells[randomIdx]};
}
