#include "CellType.h"

std::string GetCellTypeEnumString(const CellType type) {
    switch (type) {
        case CellType::TIC:
            return "X";
        case CellType::TAC:
            return "O";
        case CellType::TOE:
            return "Empty";
        default:
            return "Something wrong!";
    }
}
