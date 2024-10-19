#include <iostream>
#include <MoveProviderPlayer.h>

#include "Board.h"
#include "BoardRenderer.h"
#include "MoveProviderComputer.h"
#include "MoveProviderComputerPredictor.h"

int main(int argc, char* argv[])
{
    std::cout << "Hi! Welcome to Tic-Tac-Toe Trainer!\n";

    Board board;
    board.SetupBoard();

    BoardRendererConsole boardRenderer;
    boardRenderer.Render(board);

    bool isPlayerMove;
    char userInput;
    std::cout << "Will you go first and play for crosses? Y/n?:";
    std::cin >> userInput;

    if (userInput == 'Y' || userInput == 'y')
        isPlayerMove = true;
    else
        isPlayerMove = false;

    MoveProviderPlayer playerMoveProvider(isPlayerMove ? CellType::TIC : CellType::TAC);
    MoveProviderComputerPredictor computerMoveProvider(isPlayerMove ? CellType::TAC : CellType::TIC);

    while (true)
    {
        if (board.IsGameEnded())
        {
            std::cout << "Winner is - " << GetCellTypeEnumString(board.GetWinner());
            break;
        }

        if (board.CheckTie()) {
            std::cout << "Tie wins!\n";
            break;
        }

        bool isValidMove;
        if (isPlayerMove)
            isValidMove = board.TryMakeMove(playerMoveProvider.GenerateMove(board));
        else
            isValidMove = board.TryMakeMove(computerMoveProvider.GenerateMove(board));

        boardRenderer.Render(board);

        if (isValidMove) {
            isPlayerMove = !isPlayerMove;
        }
    }

    std::cin.get();
}
