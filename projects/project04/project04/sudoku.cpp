#include "sudoku.h"
#include <string>

const int GRID_SIZE = 9;
const int CELL_SIZE = 60;
const SDL_Color FIXED_COLOR = { 0, 0, 0, 255 };
const SDL_Color USER_COLOR = { 0, 0, 255, 255 };

Sudoku::Sudoku() {
    board.resize(GRID_SIZE, std::vector<Cell>(GRID_SIZE, { 0, CellState::EMPTY }));
    board[0][0] = { 5, CellState::FIXED };
    board[1][1] = { 3, CellState::FIXED };
    board[2][2] = { 7, CellState::FIXED };
}

void Sudoku::play(int row, int col, int value) {
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE)
        return;
    if (board[row][col].state == CellState::FIXED)
        return;
    if (value < 1 || value > 9)
        return;
    if (!isValidMove(row, col, value))
        return;
    board[row][col].value = value;
    board[row][col].state = CellState::USER;
}

GameStatus Sudoku::status() const {
    return isBoardFull() ? GameStatus::WIN : GameStatus::ONGOING;
}

bool Sudoku::isValidMove(int row, int col, int value) const {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i].value == value || board[i][col].value == value)
            return false;
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; ++i)
        for (int j = startCol; j < startCol + 3; ++j)
            if (board[i][j].value == value)
                return false;
    return true;
}

bool Sudoku::isBoardFull() const {
    for (const auto& row : board)
        for (const auto& cell : row)
            if (cell.value == 0)
                return false;
    return true;
}

void Sudoku::draw(SDL_Renderer* renderer) const {
    drawGrid(renderer);
}

void Sudoku::drawGrid(SDL_Renderer* renderer) const {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 0; i <= GRID_SIZE; ++i) {
        int thickness = (i % 3 == 0) ? 3 : 1;
        SDL_Rect hLine = { 0, i * CELL_SIZE, GRID_SIZE * CELL_SIZE, thickness };
        SDL_RenderFillRect(renderer, &hLine);
        SDL_Rect vLine = { i * CELL_SIZE, 0, thickness, GRID_SIZE * CELL_SIZE };
        SDL_RenderFillRect(renderer, &vLine);
    }
}

void Sudoku::reset() {
    for (auto& row : board)
        for (auto& cell : row)
            if (cell.state == CellState::USER) {
                cell.value = 0;
                cell.state = CellState::EMPTY;
            }
}