#include <iostream>
#include <vector>

class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;
    bool gameOver;
    int movesCount;
    std::string playerXName;
    std::string playerOName;
public:
    TicTacToe() {
        initializeGame();
    }

    void initializeGame() {
        board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
        currentPlayer = 'X';
        gameOver = false;
        movesCount = 0;
        playerXName = "Игрок X";
        playerOName = "Игрок O";
    }
};