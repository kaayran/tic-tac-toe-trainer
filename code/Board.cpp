#include "Board.h"

void Board::SetupBoard()
{
    cells.clear();
    cells.resize(SIZE, std::vector<BoardCell>(SIZE));
}

bool Board::TrySetCellValue(const int cellIdx, const CellType value)
{
    const int row = cellIdx / SIZE;
    const int col = cellIdx % SIZE;
    
    if (!CanSetCellValue(row, col)){
        return false;
    }
    
    BoardCell& cell = cells[row][col];
    cell.value = value;
    
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
