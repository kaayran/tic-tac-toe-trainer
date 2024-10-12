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
    
    std::cin.get();
}
