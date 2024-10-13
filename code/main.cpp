#include <iostream>

#include "Board.h"
#include "BoardRenderer.h"
#include "MoveProviderComputer.h"

int main(int argc, char* argv[])
{
    std::cout << "Hi! Welcome to Tic-Tac-Toe Trainer!\n";
    
    Board board;
    board.SetupBoard();
    
    BoardRendererConsole boardRenderer;
    boardRenderer.Render(board);

    bool isPlayerMove;
    char userInput;
    std::cout << "Will you go first and play for crosses?\nY/n? ";
    std::cin >> userInput;

    if (userInput == 'Y' || userInput == 'y')
        isPlayerMove = true;
    else
        isPlayerMove = false;
    
    MoveProviderComputer computerMoveProvider(isPlayerMove ? CellType::TIC : CellType::TAC);
    MoveProviderComputer playerMoveProvider(isPlayerMove ? CellType::TAC : CellType::TIC);
    
    while (true)
    {
        if (board.CheckWinner()){
            break;
        }

        if (board.CheckTie()){
            break;
        }
        
        if (isPlayerMove)
            board.TryMakeMove(playerMoveProvider.GenerateMove(board));
        else
            board.TryMakeMove(computerMoveProvider.GenerateMove(board));

        boardRenderer.Render(board);

        isPlayerMove = !isPlayerMove;
    }
    
    std::cin.get();
}
