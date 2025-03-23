#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>

class Sudoku {
public:
    enum Status { ONGOING, SOLVED, INVALID_MOVE };

    Sudoku();
    void play(int row, int col, int value);
    Status status() const;
    void display() const;

    friend std::ostream& operator<<(std::ostream& os, const Sudoku& game);

private:
    int board[9][9];
    int movesLeft;
    bool isValidMove(int row, int col, int value) const;
    bool checkSolved() const;
};

#endif
