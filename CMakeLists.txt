cmake_minimum_required(VERSION 3.10)

project(TicTacToeTrainer)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../build)

add_executable(TicTacToeTrainer
        src/main.cpp
        src/Board.cpp
        src/BoardCell.cpp
        src/BoardRenderer.cpp
        src/CellType.cpp
        src/MoveData.cpp
        src/MoveProviderBase.cpp
        src/MoveProviderComputer.cpp
        src/MoveProviderPlayer.cpp
        src/MoveProviderComputerPredictor.cpp
        src/MoveProviderComputerPredictor.h
)

target_include_directories(TicTacToeTrainer PRIVATE src)