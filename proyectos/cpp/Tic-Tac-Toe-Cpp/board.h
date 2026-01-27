#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    Board();

    void reset();
    void display() const;

    bool placeMark(int row, int col, char mark);
    bool isPositionValid(int row, int col) const;

    bool checkWin(char mark) const;
    bool checkDraw() const;

private:
    char grid[3][3];
};

#endif
