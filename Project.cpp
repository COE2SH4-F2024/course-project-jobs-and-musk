#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include <stdlib.h>
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

Food food;


GameMechs game;

objPosArrayList* boundry;


Player player = Player(&game, &food);
objPosArrayList* playerPosList;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

void printarray(void);

void update_food(void);
void update_player(void);


int main(void)
{

    Initialize();
    // !game.getLoseFlagStatus() && !game.getExitFlagStatus()
    int count = 0;
    while(!game.getLoseFlagStatus() && !game.getExitFlagStatus())  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}






void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    boundry = new objPosArrayList;
    objPos temp;
    for(int x = 0; x < 30; x++)
    {
        for (int y = 0; y < 15; y++)
        {
            if ((x == 0) || (y == 0))
            {
                temp.setObjPos(x,y,'#');
                boundry ->insertHead(temp);
            }
            else if ((x == 29) || (y == 14))
            {
                temp.setObjPos(x,y,'#');
                boundry -> insertHead(temp);
            }
        }
       
    }
    
}

void GetInput(void)
{
    if(MacUILib_hasChar())
    {
        game.setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    player.updatePlayerDir();
    player.movePlayer();
    if(game.getInput() == 'e')
    {
        game.setExitTrue();
    }
    // update_food();

    game.clearInput();
    

}



void DrawScreen(void)
{
    MacUILib_clearScreen();
    game.cleanFrameDisplay();
    game.update_frame_display(food,player.getPlayerPos(),game.getBoundry());    
    game.printFrameDisplay();
    game.printScore();
    MacUILib_printf("char is %c",game.getBoundry()->getElement(2).getSymbol());


    MacUILib_printf("\n==========Debugging Message==========\n");
    MacUILib_printf("Current direction is: %c\n", player.getPlayerDir());
    MacUILib_printf("Player Position (%d,%d)", player.getPlayerPos()->getElement(0).getObjPos().x, (player.getPlayerPos())->getElement(0).getObjPos().y);

}



void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}





void CleanUp(void)
{   

    MacUILib_clearScreen();
    game.printEndGameMessage();
    delete boundry;
    MacUILib_uninit();

}




