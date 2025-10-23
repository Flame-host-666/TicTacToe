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

    void displayBoard() {
        std::cout << "\n";
        std::cout << "    0   1   2\n";
        std::cout << "  ╔═══╦═══╦═══╗\n";

        for (int i = 0; i < 3; i++) {
            std::cout << i << " ║ ";
            for (int j = 0; j < 3; j++) {
 
                if (board[i][j] == 'X') {
                    std::cout << "X";
                }
                else if (board[i][j] == 'O') {
                    std::cout << "O";
                }
                else {
                    std::cout << " ";
                }
                std::cout << " ║ ";
            }
            std::cout << std::endl;

            if (i < 2) {
                std::cout << "  ╠═══╬═══╬═══╣\n";
            }
        }
        std::cout << "  ╚═══╩═══╩═══╝\n\n";
    }

    void displayInstructions() {
        std::cout << "\n=== ИНСТРУКЦИЯ ===\n";
        std::cout << "• Для хода введите два числа через пробел (строка столбец)\n";
        std::cout << "• Числа должны быть от 0 до 2\n";
        std::cout << "• Пример: '0 0' - верхний левый угол\n";
        std::cout << "• Пример: '1 1' - центр поля\n";
        std::cout << "• Пример: '2 2' - нижний правый угол\n";
        std::cout << "==================\n\n";
    }
};