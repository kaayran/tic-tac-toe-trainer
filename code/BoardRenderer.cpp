#include "BoardRenderer.h"

#include <iostream>


void BoardRendererConsole::Render(Board board)
{
    const auto cells = board.GetCells();
    
    for (size_t row = 0; row < cells.size(); ++row) {
        for (size_t col = 0; col < cells[row].size(); ++col) {
            std::cout << GetCellSymbol(cells[row][col]);
            if (col < cells[row].size() - 1) std::cout << "   ";
        }
        if (row < cells.size() - 1) std::cout << std::endl;
    }
    
    std::cout << std::endl;
}

char BoardRendererConsole::GetCellSymbol(const BoardCell cell)
{
    switch (cell.value)
    {
    case 0:
        return '*';
    case 1:
        return 'X';
    case 2:
        return 'O';
    default:
        return '*';
    }
}
