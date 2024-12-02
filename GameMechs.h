#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>
#include "Food.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "MacUILib.h"

using namespace std;

class Food;  // Forward Declaration

class GameMechs
{
    private:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP,};
        char input;
        enum Dir dirInput;
        char signalInput;
        bool exitFlag;
        bool loseFlag;
        int score;


        int boardSizeX;
        int boardSizeY;

        
        char** frameDisplay;

        objPos food;
        objPosArrayList* boundry;


    public:
       
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); // is this one needed at all? Why or why not?
        
        bool getExitFlagStatus() const; 
        void setExitTrue();
        bool getLoseFlagStatus() const;
        void setLoseFlag();
        void cleanFrameDisplay();

        int getInput() const;
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX() const;
        int getBoardSizeY() const;
        objPosArrayList* getBoundry() const;
        
        int getScore() const;
        void incrementScore();
        void update_frame_display(Food foods, objPosArrayList* playerPos, objPosArrayList* boundry);
        void printFrameDisplay();


        void setScore();
        void printScore();
        void printEndGameMessage();
        
        
        // More methods should be added here
};


#endif