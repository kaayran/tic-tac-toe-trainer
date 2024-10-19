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

CellType GetCellTypeOther(CellType self) {
    switch (self) {
        case CellType::TIC:
            return CellType::TAC;
        case CellType::TAC:
            return CellType::TIC;
        case CellType::TOE:
            return CellType::TOE;
        default:
            return CellType::TOE;
    }
}
