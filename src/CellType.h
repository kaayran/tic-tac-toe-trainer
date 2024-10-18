#pragma once

#include <string>

enum struct CellType
{
    TIC,
    TAC,
    TOE
};

std::string GetCellTypeEnumString(CellType type);