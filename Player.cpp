#include "Player.h"


Player::Player(GameMechs* thisGMRef,Food* foodref)
{
    mainGameMechsRef = thisGMRef;
    food = foodref;
    myDir = STOP;
    commandDir = STOP; 
    playerPosList = new objPosArrayList();

    objPos headPos, headPos1, headPos2,headPos3;

    // headPos.setObjPosX(thisGMRef->getBoardSizeX()/2);
    // headPos.setObjPosY(thisGMRef->getBoardSizeY()/2);
    headPos.setObjPos(15,7,'*');
    // headPos1.setObjPos(15,8,'*');
    // headPos2.setObjPos(15,9,'*');
    // headPos3.setObjPos(15,10,'*');


    playerPosList->insertHead(headPos);
    // playerPosList->insertHead(headPos1);
    // playerPosList->insertHead(headPos2);
    // playerPosList->insertHead(headPos3);

    

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    // returnPos = (*playerPosList).getHeadElement();
    return playerPosList;
    // return returnPos;

}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic

    switch(mainGameMechsRef -> getInput())
    {
        case 'w':
        commandDir = UP;
        break;

        case 's':
        commandDir = DOWN;
        break;

        case 'a':
        commandDir = LEFT;
        break;

        case 'd':
        commandDir = RIGHT;
        break;

    
        // default:
        // commandDir = STOP;
        // break;
    

        
    }
    if ((myDir == DOWN || myDir == UP) && (commandDir == UP || commandDir == DOWN))
    {   
        switch(myDir)
        {
            case 's':
            myDir = DOWN;
            break;

            case 'w':
            myDir = UP;
            break;
        }

    }
    else if ((myDir == LEFT || myDir == RIGHT) && (commandDir == LEFT || commandDir == RIGHT))
    {   
        switch(myDir)
        {
            case 'a':
            myDir = LEFT;
            break;

            case 'd':
            myDir = RIGHT;
            break;
        }
 
    }
    
    else
    {   
        myDir = commandDir;
    //     switch(myDir)
    //     {
    //         case 's':
    //         myDir = DOWN;
    //         break;

    //         case 'w':
    //         myDir = UP;
    //         break;
            
    //         case 'a':
    //         myDir = LEFT;
    //         break;

    //         case 'd':
    //         myDir = RIGHT;
    //         break;
    //     }
     }
}             


void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    objPos newHead;
    int x, y;
    x = (*playerPosList).getHeadElement().pos -> x;
    y = (*playerPosList).getHeadElement().pos -> y;
    switch(myDir)
    {
        case LEFT:
            if ((*playerPosList).getHeadElement().pos -> x == 1)
            {
                x = mainGameMechsRef->getBoardSizeX()-2;
            }
            else
            {
                x = ((*playerPosList).getHeadElement().pos ->x) - 1;
            }
            break;


        case RIGHT:

            if (((*playerPosList).getHeadElement().pos) -> x == mainGameMechsRef->getBoardSizeX()-2)
            {
                x = 1;
            }
            else
            {
                x = (*playerPosList).getHeadElement().pos ->x + 1;
            }

            break;


        case UP:
            
            if ((*playerPosList).getHeadElement().pos ->y == mainGameMechsRef->getBoardSizeY()-2)
            {
                y = 1;
            }
            else
            {
                y = (*playerPosList).getHeadElement().pos ->y + 1;
            }

            break;

        case DOWN:

            if ((*playerPosList).getHeadElement().pos ->y == 1)
            {
                y = mainGameMechsRef->getBoardSizeY()-2;
            }
            else
            {
                y = (*playerPosList).getHeadElement().pos ->y - 1;
            }

            break;

        // case STOP:
            
        //     break;
    


    }
    
    newHead.setObjPos(x,y,'*');
    objPos* temp;
    temp = &newHead;

    
    if(playerPosList -> getSize() >= 2)
    {  for(int i = 0; i < playerPosList -> getSize(); i++)
        {
            if(playerPosList -> getElement(i).pos -> x == x && playerPosList -> getElement(i).pos -> y == y)
            {   
                mainGameMechsRef -> setLoseFlag();
                return;
            }

            // if(playerPosList -> getElement(i).isPosEqual(temp))
            // {   
            //     mainGameMechsRef -> setLoseFlag();
            //     return;
            // }
        }
    }
    if(food -> getFoodPos().pos -> x == x && food -> getFoodPos().pos -> y == y )
    {
        (*playerPosList).insertHead(newHead);
        mainGameMechsRef->setScore();
        food -> generateFood(playerPosList);
    }
    else
    {
        (*playerPosList).insertHead(newHead);
        (*playerPosList).removeTail();
    }



}

char Player::getPlayerDir()
{
    switch(myDir)
    {
        case LEFT:
            return 'a';

        case RIGHT:
            return 'd';
        
        case UP:
            return 'w';
        
        case DOWN:
            return 's';
    }
}

