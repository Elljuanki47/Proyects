#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game {
public:
    Game();
    void run();

private:
    Board board;
    char currentPlayer;

    void switchPlayer();
    void playTurn();
    bool isGameOver() const;
};

#endif
