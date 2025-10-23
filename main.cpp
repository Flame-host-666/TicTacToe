#include <iostream>
#include <sstream>
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

    void setPlayerNames() {
        std::cout << "Введите имя для игрока X: ";
        std::getline(std::cin, playerXName);
        if (playerXName.empty()) playerXName = "Игрок X";

        std::cout << "Введите имя для игрока O: ";
        std::getline(std::cin, playerOName);
        if (playerOName.empty()) playerOName = "Игрок O";

        std::cout << "\n" << playerXName << " играет за X\n";
        std::cout << playerOName << " играет за O\n\n";
    }

    std::string getCurrentPlayerName() {
        return (currentPlayer == 'X') ? playerXName : playerOName;
    }
};