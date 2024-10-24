#include "MoveProviderPlayer.h"

#include <iostream>

MoveData MoveProviderPlayer::GenerateMove(const Board &board)
{
    int cellNum;
    std::cout << "Enter cell number [1-9] to set " + GetCellTypeEnumString(cellType) << "->";

    auto isInRangeFunc = [&](const int inCellNum) {
        if (inCellNum < 1) {
            return false;
        }

        return inCellNum > Board::SIZE * Board::SIZE;
    };
    
    while (true) {
        std::cin >> cellNum;

        if (std::cin.fail() || isInRangeFunc(cellNum) || !board.CanSetCellValue(cellNum - 1)) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please enter a valid cell number ->";
            continue;
        }

        break;
    }

    const MoveData moveData(cellType, cellNum - 1);
    return moveData;
}