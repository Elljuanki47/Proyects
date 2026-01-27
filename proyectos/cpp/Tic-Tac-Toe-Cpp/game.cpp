#include <iostream>
#include "game.h"

Game::Game() : currentPlayer('X') {
    board.reset();
}

void Game::run() {
    bool playAgain = true;

    while (playAgain) {
        board.reset();
        currentPlayer = 'X';

        while (!isGameOver()) {
            board.display();
            playTurn();
            if (!isGameOver()) {
                switchPlayer();
            }
        }

        board.display();

        if (board.checkWin(currentPlayer)) {
            std::cout << "Player " << currentPlayer << " wins!\n";
        } else {
            std::cout << "It's a draw!\n";
        }

        std::cout << "Play again? (y/n): ";
        char choice;
        std::cin >> choice;

        playAgain = (choice == 'y' || choice == 'Y');
    }
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void Game::playTurn() {
    int row, col;
    bool validMove = false;

    while (!validMove) {
        std::cout << "Player " << currentPlayer
                  << ", enter row (1-3) and column (1-3): ";
        std::cin >> row >> col;

        // Convert to 0-based index
        row--;
        col--;

        if (board.placeMark(row, col, currentPlayer)) {
            validMove = true;
        } else {
            std::cout << "Invalid move. Try again.\n";
        }
    }
}

bool Game::isGameOver() const {
    return board.checkWin(currentPlayer) || board.checkDraw();
}
