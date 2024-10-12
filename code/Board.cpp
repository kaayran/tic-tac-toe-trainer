#include "Board.h"

void Board::SetupBoard()
{
    cells.clear();
    cells.resize(SIZE, std::vector<BoardCell>(SIZE));
}
