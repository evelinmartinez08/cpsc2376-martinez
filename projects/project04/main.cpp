#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include "sudoku.h"
#include <iostream>

const int WINDOW_WIDTH = 540;
const int WINDOW_HEIGHT = 540;
const int CELL_SIZE = 60;

int wmain(int argc, wchar_t* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    TTF_Font* font = TTF_OpenFont("arial.ttf", 36);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Sudoku", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Sudoku game;
    bool running = true;
    int selectedRow = -1, selectedCol = -1;

    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                running = false;
            else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_ESCAPE)
                    running = false;
                else if (e.key.keysym.sym == SDLK_r)
                    game.reset();
                else if (selectedRow != -1 && selectedCol != -1) {
                    int value = 0;
                    switch (e.key.keysym.sym) {
                    case SDLK_1: value = 1; break;
                    case SDLK_2: value = 2; break;
                    case SDLK_3: value = 3; break;
                    case SDLK_4: value = 4; break;
                    case SDLK_5: value = 5; break;
                    case SDLK_6: value = 6; break;
                    case SDLK_7: value = 7; break;
                    case SDLK_8: value = 8; break;
                    case SDLK_9: value = 9; break;
                    default: break;
                    }
                    if (value != 0)
                        game.play(selectedRow, selectedCol, value);
                }
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                selectedRow = y / CELL_SIZE;
                selectedCol = x / CELL_SIZE;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        game.draw(renderer, font);
        SDL_RenderPresent(renderer);

        if (game.status() == GameStatus::WIN) {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Sudoku", "You Win!", window);
            game.reset();
        }
    }

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
