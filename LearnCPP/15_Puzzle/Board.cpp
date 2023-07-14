#include "Board.hpp"
#include "Direction.hpp"

Tile::Tile(int n)
    : m_value{n}
{}

std::ostream& operator<<(std::ostream& out, const Tile& t)
{
    out<<' ';
    if(t.m_value==0)
        out<<"  ";
    else if(t.m_value<10)
        out<<' '<<t.m_value;
    else
        out<<t.m_value;
    out<<' ';
    return out;
}

Board::Board()
    : m_emptyX{m_maxRow-1}
    , m_emptyY{m_maxCol-1}
{
    for(int i{}, k{1}; i<m_maxRow; ++i)
    {
        std::vector<Tile> vec;
        for(int j{}; j<m_maxCol; ++j, ++k)
            vec.push_back({k%16});
        m_board.push_back(vec);
    }
    randomize();
}

std::ostream& operator<<(std::ostream& out, const Board& board)
{
    board.printEmptyLines(board.m_emptyLines);
    for(int i{}; i<board.m_maxRow; ++i)
    {
        for(int j{}; j<board.m_maxCol; ++j)
            out<<board.m_board[i][j];
        out<<'\n';
    }
    return out;
}

void Board::printEmptyLines(int count) const
{
    for(int i{}; i<count; i++)
        std::cout<<'\n';
}

Point Point::getAdjacentPoint(Direction dir)
{
    switch(dir.getType())
    {
        case Direction::up:     return {m_x-1, m_y};
        case Direction::left:   return {m_x, m_y-1};
        case Direction::right:  return {m_x, m_y+1};
        case Direction::down:   return {m_x+1, m_y};
    }
    return *this;
}

bool Board::isPointValid(Point p) const
{
    if(p.m_x<0 || p.m_y<0 || p.m_x>=m_maxRow || p.m_y>=m_maxCol)
        return false;
    return true;
}

void Board::moveTile(Direction dir)
{
    Point p{m_emptyX, m_emptyY};
    Point mv{p.getAdjacentPoint(-dir)};
    if(!isPointValid(mv))
        return;
    std::swap(m_board[mv.m_x][mv.m_y], m_board[p.m_x][p.m_y]);
    m_emptyX = mv.m_x;
    m_emptyY = mv.m_y;
}

void Board::randomize()
{
    for(int i{};i<100;i++)
        moveTile(Direction::getRandomDirection());
}

bool Board::isSolved() const
{
    if(m_emptyX!=(m_maxRow-1) || m_emptyY!=(m_maxCol-1))
        return false;
    for(int i{}, k{1}; i<m_maxRow; ++i)
        for(int j{}; j<m_maxCol; ++j, ++k)
            if(m_board[i][j].getNum()!=k%16)
                return false;
    return true;
}