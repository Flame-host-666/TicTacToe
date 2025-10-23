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

    bool isValidMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            std::cout << "❌ Ошибка: координаты должны быть от 0 до 2!\n";
            return false;
        }

        if (board[row][col] != ' ') {
            std::cout << "❌ Ошибка: эта клетка уже занята!\n";
            return false;
        }

        return true;
    }

    bool makeMove(int row, int col) {
        if (!isValidMove(row, col)) {
            return false;
        }

        board[row][col] = currentPlayer;
        movesCount++;

        std::cout << "✅ " << getCurrentPlayerName() << " поставил " << currentPlayer << " в (" << row << "," << col << ")\n";
        return true;
    }

    bool checkWin() {
        char symbol = currentPlayer;

        for (int i = 0; i < 3; i++) {
            if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
                return true;
            }
        }

        for (int j = 0; j < 3; j++) {
            if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
                return true;
            }
        }

        if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
            return true;
        }
        if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
            return true;
        }

        return false;
    }

    bool checkDraw() {
        return movesCount == 9 && !checkWin();
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        std::cout << "\n🎮 Теперь ходит " << getCurrentPlayerName() << " (" << currentPlayer << ")\n";
    }

    bool getPlayerInput(int& row, int& col) {
        std::string input;
        std::cout << "➡️  " << getCurrentPlayerName() << " (" << currentPlayer << "), ваш ход: ";

        if (!std::getline(std::cin, input)) {
            return false;
        }

        std::stringstream ss(input);

        if (!(ss >> row >> col)) {
            std::cout << "❌ Ошибка: введите два числа через пробел!\n";
            return false;
        }

        std::string extra;
        if (ss >> extra) {
            std::cout << "❌ Ошибка: введите только два числа!\n";
            return false;
        }

        return true;
    }

    void displayGameResult() {
        std::cout << "\n";
        std::cout << "═══════════════════════════════════\n";

        if (checkWin()) {
            std::cout << "🎉 ПОБЕДА! " << getCurrentPlayerName() << " (" << currentPlayer << ") выиграл!\n";
        }
        else if (checkDraw()) {
            std::cout << "🤝 НИЧЬЯ! Все клетки заполнены.\n";
        }

        std::cout << "═══════════════════════════════════\n";
    }
};