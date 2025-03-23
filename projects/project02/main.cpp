#include <iostream>
#include "sudoku.h"

int main() {
    Sudoku game; //constructs a new game
    int row, col, value;

    std::cout << "Sudoku Game Started!" << std::endl;

    //loops until the game is solved
    while (game.status() == Sudoku::ONGOING) {
        std::cout << game;
        std::cout << "Enter row (0-8), column (0-8), and value (1-9): ";
        std::cin >> row >> col >> value;

        // plays the move
        game.play(row, col, value);
    }

    if (game.status() == Sudoku::SOLVED) {
        std::cout << "Congratulations! You solved the puzzle!" << std::endl;
    } else {
        std::cout << "No more valid moves left!" << std::endl;
    }

    return 0;
}
