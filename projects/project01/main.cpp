#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <limits>

const int SIZE = 4;

enum class GameState { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
enum class Player { PLAYER_1, PLAYER_2 };
enum class Move { UP, DOWN, LEFT, RIGHT, INVALID };

using Board = std::vector<std::vector<int>>;

void makeBoard(Board &board);
void printBoard(const Board &board);
GameState gameStatus(const Board &board);
Move getMove();
bool applyMove(Board &board, Move move);
void spawnTile(Board &board);
bool canMove(const Board &board);
void shiftAndMerge(std::vector<int> &line);

void play() {
    Board board(SIZE, std::vector<int>(SIZE, 0));
    makeBoard(board);
    Player currentPlayer = Player::PLAYER_1;
    
    while (true) {
        printBoard(board);
        std::cout << "Player " << (currentPlayer == Player::PLAYER_1 ? "1" : "2") << "'s turn. Enter move (W/A/S/D): ";
        
        Move move = getMove();
        if (move == Move::INVALID) {
            std::cout << "Invalid input. Please try again.\n";
            continue;
        }
        
        if (applyMove(board, move)) {
            spawnTile(board);
            GameState state = gameStatus(board);
            if (state != GameState::ONGOING) {
                printBoard(board);
                if (state == GameState::PLAYER_1_WINS) std::cout << "Player 1 wins!\n";
                else if (state == GameState::PLAYER_2_WINS) std::cout << "Player 2 wins!\n";
                else std::cout << "It's a draw!\n";
                break;
            }
            currentPlayer = (currentPlayer == Player::PLAYER_1) ? Player::PLAYER_2 : Player::PLAYER_1;
        } else {
            std::cout << "Move is not possible. Please try again.\n";
        }
    }
}

void makeBoard(Board &board) {
    std::srand(std::time(nullptr));
    spawnTile(board);
    spawnTile(board);
}

void printBoard(const Board &board) {
    std::cout << "\n";
    for (const auto &row : board) {
        for (int cell : row) {
            std::cout << std::setw(5) << (cell ? std::to_string(cell) : ".") << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

Move getMove() {
    char input;
    std::cin >> input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
    input = std::tolower(input);
    switch (input) {
        case 'w': return Move::UP;
        case 's': return Move::DOWN;
        case 'a': return Move::LEFT;
        case 'd': return Move::RIGHT;
        default: return Move::INVALID;
    }
}

bool applyMove(Board &board, Move move) {
    Board temp = board;
    
    if (move == Move::UP || move == Move::DOWN) {
        for (int col = 0; col < SIZE; col++) {
            std::vector<int> line;
            for (int row = 0; row < SIZE; row++)
                line.push_back(board[row][col]);
            
            if (move == Move::DOWN) std::reverse(line.begin(), line.end());
            shiftAndMerge(line);
            if (move == Move::DOWN) std::reverse(line.begin(), line.end());
            
            for (int row = 0; row < SIZE; row++)
                board[row][col] = line[row];
        }
    } else {
        for (int row = 0; row < SIZE; row++) {
            std::vector<int> line = board[row];
            if (move == Move::RIGHT) std::reverse(line.begin(), line.end());
            shiftAndMerge(line);
            if (move == Move::RIGHT) std::reverse(line.begin(), line.end());
            board[row] = line;
        }
    }
    return board != temp;
}

void shiftAndMerge(std::vector<int> &line) {
    std::vector<int> temp;
    for (int num : line) if (num) temp.push_back(num);
    for (size_t i = 0; i + 1 < temp.size(); i++) {
        if (temp[i] == temp[i + 1]) {
            temp[i] *= 2;
            temp[i + 1] = 0;
        }
    }
    temp.erase(std::remove(temp.begin(), temp.end(), 0), temp.end());
    while (temp.size() < SIZE) temp.push_back(0);
    line = temp;
}

void spawnTile(Board &board) {
    std::vector<std::pair<int, int>> emptyTiles;
    for (int r = 0; r < SIZE; r++)
        for (int c = 0; c < SIZE; c++)
            if (board[r][c] == 0)
                emptyTiles.emplace_back(r, c);
    
    if (!emptyTiles.empty()) {
        std::pair<int, int> tile = emptyTiles[std::rand() % emptyTiles.size()];
        int r = tile.first;
        int c = tile.second;
        board[r][c] = (std::rand() % 10 == 0) ? 4 : 2;
    }
}

GameState gameStatus(const Board &board) {
    for (const auto &row : board)
        for (int cell : row)
            if (cell == 2048)
                return GameState::PLAYER_1_WINS;
    
    if (canMove(board))
        return GameState::ONGOING;
    
    return GameState::DRAW;
}

bool canMove(const Board &board) {
    for (int r = 0; r < SIZE; r++)
        for (int c = 0; c < SIZE; c++)
            if (board[r][c] == 0 || 
                (c < SIZE - 1 && board[r][c] == board[r][c + 1]) ||
                (r < SIZE - 1 && board[r][c] == board[r + 1][c]))
                return true;
    return false;
}

int main() {
    while (true) {
        play();
        std::cout << "Would you like to play again? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice != 'y' && choice != 'Y') break;
    }
    return 0;
}