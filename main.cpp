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
        playerXName = "����� X";
        playerOName = "����� O";
    }

    void setPlayerNames() {
        std::cout << "������� ��� ��� ������ X: ";
        std::getline(std::cin, playerXName);
        if (playerXName.empty()) playerXName = "����� X";

        std::cout << "������� ��� ��� ������ O: ";
        std::getline(std::cin, playerOName);
        if (playerOName.empty()) playerOName = "����� O";

        std::cout << "\n" << playerXName << " ������ �� X\n";
        std::cout << playerOName << " ������ �� O\n\n";
    }

    std::string getCurrentPlayerName() {
        return (currentPlayer == 'X') ? playerXName : playerOName;
    }
};