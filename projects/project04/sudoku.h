#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>
#include <SDL2/SDL.h>

enum class CellState { EMPTY, FIXED, USER };
enum class GameStatus { ONGOING, WIN };

struct Cell {
    int value;
    CellState state;
};

class Sudoku {
public:
    Sudoku();
    void play(int row, int col, int value);
    GameStatus status() const;
    void draw(SDL_Renderer* renderer) const;
    void reset();

private:
    std::vector<std::vector<Cell>> board;
    bool isValidMove(int row, int col, int value) const;
    bool isBoardFull() const;
    void drawGrid(SDL_Renderer* renderer) const;
};

#endif

