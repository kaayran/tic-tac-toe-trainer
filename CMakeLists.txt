cmake_minimum_required(VERSION 3.10)

project(TicTacToeTrainer)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../build)

add_executable(TicTacToeTrainer
    code/main.cpp
)

target_include_directories(TicTacToeTrainer PRIVATE code)