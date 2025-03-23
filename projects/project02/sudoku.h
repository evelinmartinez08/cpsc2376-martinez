#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>

class Sudoku {
public:
    enum Status { ONGOING, SOLVED, INVALID_MOVE };

    Sudoku(); //constructor to start the game
    void play(int row, int col, int value); // executes the move for the current player
    Status status() const; // checks status of the game
    void display() const; // displays the current board

    // friend cunction to allow printing the game using the std::cout
    friend std::ostream& operator<<(std::ostream& os, const Sudoku& game);

private:
    int board[9][9]; // 9x9 board
    int movesLeft; // keeps track of the moves left
    bool isValidMove(int row, int col, int value) const; // checks if the move is valid
    bool checkSolved() const; // checks if the puzzle is solved
};

#endif
