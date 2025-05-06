#include "sudoku.h"
#include <string>

void Sudoku::drawNumbers(SDL_Renderer* renderer) const {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            int val = board[i][j].value;
            if (val == 0) continue;

            SDL_Color color = (board[i][j].state == CellState::FIXED) ? FIXED_COLOR : USER_COLOR;
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

            SDL_Rect cellRect = {
                j * CELL_SIZE + 10,
                i * CELL_SIZE + 10,
                CELL_SIZE - 20,
                CELL_SIZE - 20
            };
            SDL_RenderFillRect(renderer, &cellRect);
        }
    }
}
