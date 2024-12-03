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
Player player = Player(&game, &food);


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
    food.generateFood(player.getPlayerPos());
    
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
    player.detectFood();
    if(game.getInput() == 'e')
    {
        game.setExitTrue();
    }


    game.clearInput();
    

}



void DrawScreen(void)
{ 
    MacUILib_clearScreen();
    game.cleanFrameDisplay();
    game.update_frame_display(food,player.getPlayerPos(),game.getBoundry());    
    game.printFrameDisplay();
    game.printScore();
    MacUILib_printf("Instruction\n");
    MacUILib_printf("If you eat 'a', you will get 1 score and your length will plus 1\n");
    MacUILib_printf("If you eat 'b', you will get 2 score and your length will plus 2\n");
    MacUILib_printf("If you eat 'c', you will get 5 score and your length will plus 5\n");
    MacUILib_printf("If you eat 'd', you will get 0 score and your length will minus 2\n");
    MacUILib_printf("If you eat 'e', you will get 5 score and your length will plus 1\n");
    MacUILib_printf("\n==========Debugging Message==========\n");
    MacUILib_printf("Current direction is: %c\n", player.getPlayerDir());
    MacUILib_printf("Player Position (%d,%d)", player.getPlayerPos()->getElement(0).getObjPos().x, (player.getPlayerPos())->getElement(0).getObjPos().y);
    
    
}



void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST);
}





void CleanUp(void)
{   

    MacUILib_clearScreen();
    game.printEndGameMessage();
    MacUILib_uninit();

}




