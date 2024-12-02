#ifndef OBJPOS_H
#define OBJPOS_H

// Not really a C++ thing
typedef struct 
{
    int x;
    int y;
} Pos;

class objPos
{
    public:
        Pos* pos;        
        

        objPos();
        objPos(int xPos, int yPos, char sym);
        objPos(const objPos& this_obj);
        ~objPos();
        objPos& operator=(const objPos& this_obj);

        
        // Respect the rule of six / minimum four
        // [TODO] Implement the missing special member functions to meet the minimum four rule
        
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  
        void setObjPosX(int x);
        void setObjPosY(int y);

        Pos getObjPos() const;
        char getSymbol() const;
        char getSymbolIfPosEqual(const objPos* refPos) const;
        
        bool isPosEqual(const objPos* refPos) const;

    private:
        char symbol;
};

#endif