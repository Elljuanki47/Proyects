#include <iostream>
#include "board.h"

Board::Board() {
    reset();
}

void Board::reset() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = ' ';
        }
    }
}

void Board::display() const {
    std::cout << "\n";
    for (int i = 0; i < 3; i++) {
        std::cout << " ";
        for (int j = 0; j < 3; j++) {
            std::cout << grid[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}

bool Board::isPositionValid(int row, int col) const {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        return false;
    }
    return grid[row][col] == ' ';
}

bool Board::placeMark(int row, int col, char mark) {
    if (!isPositionValid(row, col)) {
        return false;
    }
    grid[row][col] = mark;
    return true;
}

bool Board::checkWin(char mark) const {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == mark && grid[i][1] == mark && grid[i][2] == mark) {
            return true;
        }
    }

    // Columns
    for (int j = 0; j < 3; j++) {
        if (grid[0][j] == mark && grid[1][j] == mark && grid[2][j] == mark) {
            return true;
        }
    }

    // Diagonals
    if (grid[0][0] == mark && grid[1][1] == mark && grid[2][2] == mark) {
        return true;
    }
    if (grid[0][2] == mark && grid[1][1] == mark && grid[2][0] == mark) {
        return true;
    }

    return false;
}

bool Board::checkDraw() const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
