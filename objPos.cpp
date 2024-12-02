#include "objPos.h"

objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule

objPos::objPos(const objPos& this_obj)
{
    pos = new Pos;
    pos -> x = this_obj.pos -> x;
    pos -> y = this_obj.pos -> y;
    symbol = this_obj.symbol;

}

objPos::~objPos()
{
    delete pos;
}

objPos& objPos::operator=(const objPos& this_obj)
{
    pos -> x = this_obj.pos -> x;
    pos -> y = this_obj.pos -> y;
    return *this;
}



void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

Pos objPos::getObjPos() const
{
    Pos returnPos;
    returnPos.x = pos->x;
    returnPos.y = pos->y;
    
    
    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}

void objPos::setObjPosX(int x)
{
    pos -> x = x;
}

void objPos::setObjPosY(int y)
{
    pos -> y = y;
}