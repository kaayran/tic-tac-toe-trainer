#include "Board.h"

void Board::SetupBoard()
{
    cells.clear();
    cells.resize(SIZE, std::vector<BoardCell>(SIZE));
}

void Board::SetCellValue(const int row, const int col, const CellType value)
{
    BoardCell& cell = cells[row][col];
    cell.value = value;
}

std::vector<int> Board::GetEmptyCells()
{
    std::vector<int> emptyCells;

    for (size_t row = 0; row < cells.size(); ++row)
    {
        for (size_t col = 0; col < cells[row].size(); ++col)
        {
            if (!cells[row][col].IsEmpty()) continue;
            emptyCells.push_back(row * SIZE + col);
        }
    }

    return emptyCells;
}

bool Board::TryMakeMove(const MoveData moveData)
{
    if (!CanSetCellValue(moveData.boardRowIdx, moveData.boardColIdx))
    {
        return false;
    }

    SetCellValue(moveData.boardRowIdx, moveData.boardColIdx, moveData.cellType);

    return true;
}

bool Board::CanSetCellValue(const int cellIdx) const
{
    const int row = cellIdx / SIZE;
    const int col = cellIdx % SIZE;

    return CanSetCellValue(row, col);
}

bool Board::CanSetCellValue(const int row, const int col) const
{
    const BoardCell& cell = cells[row][col];
    return cell.value == CellType::TOE;
}
