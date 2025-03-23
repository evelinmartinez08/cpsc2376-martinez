#include "sudoku.h"

Sudoku::Sudoku() : movesLeft(81) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            board[i][j] = 0;
        }
    }
}

void Sudoku::play(int row, int col, int value) {
    if (isValidMove(row, col, value)) {
        board[row][col] = value;
        --movesLeft;
    } else {
        std::cout << "Invalid move. Try again." << std::endl;
    }
}

Sudoku::Status Sudoku::status() const {
    if (checkSolved()) {
        return SOLVED;
    } else if (movesLeft == 0) {
        return INVALID_MOVE;
    } else {
        return ONGOING;
    }
}

void Sudoku::display() const {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool Sudoku::isValidMove(int row, int col, int value) const {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == value) {
            return false;
        }
    }
    for (int i = 0; i < 9; ++i) {
        if (board[i][col] == value) {
            return false;
        }
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; ++i) {
        for (int j = startCol; j < startCol + 3; ++j) {
            if (board[i][j] == value) {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::checkSolved() const {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == 0 || !isValidMove(i, j, board[i][j])) {
                return false;
            }
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Sudoku& game) {
    game.display();
    return os;
}