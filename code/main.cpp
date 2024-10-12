#include <iostream>

#include "Board.h"
#include "BoardRenderer.h"

int main(int argc, char* argv[])
{
    std::cout << "Hi! Welcome to Tic-Tac-Toe Trainer!\n";
    
    Board board;
    board.SetupBoard();
    
    BoardRendererConsole boardRenderer;
    boardRenderer.Render(board);

    board.TrySetCellValue(8, CellType::TIC);
    boardRenderer.Render(board);
    board.TrySetCellValue(8, CellType::TAC);
    boardRenderer.Render(board);
    board.TrySetCellValue(2, CellType::TIC);
    boardRenderer.Render(board);
    
    std::cin.get();
}
