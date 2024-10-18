#include "MoveProviderPlayer.h"

#include <iostream>

MoveData MoveProviderPlayer::GenerateMove(Board board)
{
    int cellNum;
    std::cout << "Enter cell number [1-9] to set " + GetCellTypeEnumString(cellType) << "->";

    while (true) {
        std::cin >> cellNum;

        if (std::cin.fail() || IsInRange(cellNum) || !board.CanSetCellValue(cellNum - 1)) {
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

bool MoveProviderPlayer::IsInRange(const int cellNum) {
    if (cellNum < 1) {
        return false;
    }

    return cellNum > Board::SIZE * Board::SIZE;
}