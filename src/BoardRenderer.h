﻿#pragma once

#include "Board.h"

class BoardRendererBase
{
public:
    virtual ~BoardRendererBase() = default;
    
    virtual void Render(const Board& board) {}
};

class BoardRendererConsole : public BoardRendererBase
{
public:
    void Render(const Board& board) override;

private:
    char GetCellSymbol(BoardCell cell);
};
