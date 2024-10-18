#include "Board.h"

void Board::SetupBoard() {
    cells.clear();
    cells.resize(SIZE, std::vector<BoardCell>(SIZE));
}

void Board::SetCellValue(const int row, const int col, const CellType value) {
    BoardCell &cell = cells[row][col];
    cell.value = value;
}

std::vector<int> Board::GetEmptyCells() {
    std::vector<int> emptyCells;

    for (size_t row = 0; row < cells.size(); ++row) {
        for (size_t col = 0; col < cells[row].size(); ++col) {
            if (!cells[row][col].IsEmpty()) continue;
            emptyCells.push_back(row * SIZE + col);
        }
    }

    return emptyCells;
}

bool Board::TryMakeMove(const MoveData moveData) {
    if (!CanSetCellValue(moveData.cellRowIdx, moveData.cellColIdx)) {
        return false;
    }

    SetCellValue(moveData.cellRowIdx, moveData.cellColIdx, moveData.cellType);

    return true;
}

bool Board::CanSetCellValue(const int cellIdx) const {
    const int row = cellIdx / SIZE;
    const int col = cellIdx % SIZE;

    return CanSetCellValue(row, col);
}

bool Board::CanSetCellValue(const int row, const int col) const {
    const BoardCell &cell = cells[row][col];
    return cell.value == CellType::TOE;
}

bool Board::CheckRow(int const row) {
    const CellType last = cells[row][0].value;
    if (last == CellType::TOE) {
        return false;
    }

    for (size_t col = 1; col < SIZE; ++col) {
        if (cells[row][col].value != last) {
            return false;
        }
    }

    return true;
}

bool Board::CheckColumn(int col) {
    const CellType last = cells[0][col].value;
    if (last == CellType::TOE) {
        return false;
    }

    for (size_t row = 1; row < SIZE; ++row) {
        if (cells[row][col].value != last) {
            return false;
        }
    }

    return true;
}

bool Board::CheckMainDiagonal() {
    CellType last = cells[0][0].value;
    if (last == CellType::TOE) {
        return false;
    }

    for (int i = 1; i < SIZE; ++i) {
        if (cells[i][i].value != last)
            return false;
    }

    return true;
}

bool Board::CheckAntiDiagonal() {
    const CellType last = cells[0][SIZE - 1].value;
    if (last == CellType::TOE) {
        return false;
    }

    for (int i = 1; i < SIZE; ++i) {
        if (cells[i][SIZE - i - 1].value != last)
            return false;
    }

    return true;
}

bool Board::CheckWinner() {
    for (int i = 0; i < SIZE; ++i) {
        if (CheckRow(i) || CheckColumn(i)) {
            return true;
        }
    }

    if (CheckMainDiagonal() || CheckAntiDiagonal()) {
        return true;
    }

    return false;
}

bool Board::CheckTie() {
    return GetEmptyCells().empty();
}
