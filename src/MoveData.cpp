#include "MoveData.h"

#include <Board.h>

MoveData::MoveData(const CellType inCellType, const int row, const int col) {
    cellType = inCellType;
    cellRowIdx = row;
    cellColIdx = col;
}

MoveData::MoveData(const CellType inCellType, const int cellIdx) {
    cellType = inCellType;
    cellRowIdx = cellIdx / Board::SIZE;
    cellColIdx = cellIdx % Board::SIZE;
}
