#include "GameMechs.h"



GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    loseFlag = false;
    exitFlag = false;
    score = 0;
    input = 0;
    
    
    frameDisplay = new char* [boardSizeX];
    for(int i = 0; i < boardSizeX; i++)
    { 
        frameDisplay[i] = new char[boardSizeY];
    }

    for(int i = 0; i < boardSizeX; i++)
    { 
        for(int j = 0; j < boardSizeY; j++)
        {
            frameDisplay[i][j] = ' ';
        }
        
    }

    

    objPos temp;
    boundry = new objPosArrayList();
    for(int x = 0; x < 30; x++)
    {
        for (int y = 0; y < 15; y++)
        {
            if ((x == 0) || (y == 0))
            {
                temp.setObjPos(x,y,'#');
                boundry -> insertHead(temp);
            }
            else if ((x == 29) || (y == 14))
            {
                temp.setObjPos(x,y,'#');
                boundry -> insertHead(temp);
            }
        }
       
    }

}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    loseFlag = false;
    exitFlag = false;
    score = 0;
    input = 0;
    for(int i = 0; i < boardSizeX; i++)
    { 
        frameDisplay[i] = new char[boardSizeY];
    }

    for(int i = 0; i < boardSizeX; i++)
    { 
        for(int j = 0; j < boardSizeY; j++)
        {
            frameDisplay[i][j] = ' ';
        }
        
    }
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    for(int i = 0; i < boardSizeX; i++)
    { 
        delete[] frameDisplay[i];
    }

    delete[] frameDisplay;
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

int GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score +=1;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

void GameMechs::update_frame_display(Food foods, objPosArrayList* playerPos, objPosArrayList* border)
{
    cleanFrameDisplay();
    for(int i = 0; i < playerPos -> getSize(); i++)
    {
        frameDisplay[playerPos -> getElement(i).pos -> x][playerPos -> getElement(i).pos -> y] = playerPos->getElement(i).getSymbol();
    }
    
    for(int i = 0; i < border -> getSize(); i++)
    {
        frameDisplay[border -> getElement(i).pos -> x][border -> getElement(i).pos -> y] = border -> getElement(i).getSymbol();
    }

    frameDisplay[foods.getFoodPos().pos -> x][foods.getFoodPos().pos -> y] = foods.getFoodPos().getSymbol();
    
}


void GameMechs::cleanFrameDisplay()
{ 
   

    for(int i = 0; i < boardSizeX; i++)
    { 
        for(int j = 0; j < boardSizeY; j++)
        {
            frameDisplay[i][j] = ' ';
        }
        
    }
}

void GameMechs::printFrameDisplay()
{
    int x , y;
    for(y = 14; y >= 0; y--)
    {
        for(x = 0; x <= 29; x++)
        {   if (x == 29)
            {
                MacUILib_printf("%c\n", frameDisplay[x][y]);
            }
            else
            {
                MacUILib_printf("%c", frameDisplay[x][y]);
            }

        }
    }
}

objPosArrayList* GameMechs::getBoundry()  const
{
    return boundry;
}

void GameMechs:: setScore()
{
    score++;
}

void GameMechs:: printScore()
{
    MacUILib_printf("Your score is %d\n", score);

}

void GameMechs:: printEndGameMessage()
{   
    if(loseFlag == true)
    {
        MacUILib_printf("Sorry, You lost the game");
    }
  
    
}