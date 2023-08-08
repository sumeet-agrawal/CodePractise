#ifndef BOARD_GAME_15_PUZZLE
#define  BOARD_GAME_15_PUZZLE

#include <iostream>
#include <vector>

class Direction;
struct Point
{
    int m_x{};
    int m_y{};
    Point getAdjacentPoint(Direction);
    bool operator==(const Point& p) { return m_x==p.m_x && m_y==p.m_y;}
    bool operator!=(const Point& p) { return !(*this==p);}
};

class Tile
{
public:
    Tile(int);
    friend std::ostream& operator<<(std::ostream&, const Tile&);
    bool isEmpty() const { return m_value == 0;}
    int getNum() const { return m_value;}
private:
    int m_value{};
};

class Board
{
public:
    Board();
    friend std::ostream& operator<<(std::ostream&, const Board&);
    void printEmptyLines(int) const;
    void moveTile(Direction);
    bool isPointValid(Point) const;
    bool isSolved() const;
private:
    void randomize();
    const int m_maxRow{4};
    const int m_maxCol{4};
    const int m_emptyLines{50};
    std::vector<std::vector<Tile>> m_board{};
    int m_emptyX{};
    int m_emptyY{};
};

#endif