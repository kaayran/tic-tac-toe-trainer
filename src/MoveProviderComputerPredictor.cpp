#include "MoveProviderComputerPredictor.h"

#include <iostream>
#include <limits>

MoveData MoveProviderComputerPredictor::GenerateMove(const Board board) {
    std::vector<int> emptyCells;
    board.GetEmptyCells(emptyCells);

    std::vector<std::pair<MoveData, int>> moves;
    int bestScore = std::numeric_limits<int>::min();

    for (const int emptyCell: emptyCells) {
        Board boardCopy(board);

        MoveData moveData(cellType, emptyCell);
        boardCopy.TryMakeMove(moveData);

        int score = MinMax(boardCopy, 0, false,
            std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

        if (score >= bestScore) {
            bestScore = score;
            moves.push_back(std::make_pair(moveData, score));
        }
    }

    std::vector<MoveData> bestMoves;
    for (auto movePair : moves) {
        if (movePair.second >= bestScore) {
            bestMoves.push_back(movePair.first);
        }
    }

    return bestMoves[rand() % bestMoves.size()];
}

int MoveProviderComputerPredictor::MinMax(const Board &board, const int depth, const int isMax, int alpha, int beta) {
    if (board.CheckWinner()) {
        if (board.GetWinner() == cellType) {
            return (Board::SIZE * Board::SIZE + 1) - depth;
        }

        if (board.GetWinner() == GetCellTypeOther(cellType)) {
            return depth - (Board::SIZE * Board::SIZE + 1);
        }
    }

    std::vector<int> emptyCellsIdxs;
    board.GetEmptyCells(emptyCellsIdxs);
    if (emptyCellsIdxs.empty()) {
        return 0;
    }

    int bestScore;

    if (isMax) {
        bestScore = std::numeric_limits<int>::min();
        for (const int cellIdx: emptyCellsIdxs) {
            Board currBoardCopy(board);
            const MoveData moveData(cellType, cellIdx);
            currBoardCopy.TryMakeMove(moveData);

            int score = MinMax(currBoardCopy, depth + 1, false, alpha, beta);

            bestScore = std::max(bestScore, score);

            alpha = std::max(alpha, score);

            if (beta <= alpha) break;
        }
    } else {
        bestScore = std::numeric_limits<int>::max();
        for (const int cellIdx: emptyCellsIdxs) {
            Board currBoardCopy(board);
            const MoveData moveData(GetCellTypeOther(cellType), cellIdx);
            currBoardCopy.TryMakeMove(moveData);

            int score = MinMax(currBoardCopy, depth + 1, true, alpha, beta);

            bestScore = std::min(bestScore, score);

            beta = std::min(beta, score);

            if (beta <= alpha) break;
        }
    }

    return bestScore;
}
