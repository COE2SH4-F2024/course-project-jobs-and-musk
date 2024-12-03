#include "Player.h"


Player::Player(GameMechs* thisGMRef,Food* foodref)
{
    mainGameMechsRef = thisGMRef;
    food = foodref;
    myDir = STOP;
    commandDir = STOP; 
    playerPosList = new objPosArrayList();

    objPos headPos;
    headPos.setObjPos(15,7,'*');
    playerPosList->insertHead(headPos);
    
}


Player::~Player()
{
    delete playerPosList;
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
    }
}             


objPos Player::movePlayer()
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
    return newHead;

    
    

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

void Player::detectFood()
{
    if(playerPosList -> getSize() >= 2)
    {  for(int i = 0; i < playerPosList -> getSize(); i++)
        {
            if(playerPosList -> getElement(i).pos -> x == movePlayer().pos -> x && playerPosList -> getElement(i).pos -> y == movePlayer().pos ->y)
            {   
                mainGameMechsRef -> setLoseFlag();
                return;
            }
        }
    }

    




    for(int i = 0; i < 3; i++)
    {
        if(food -> getFoodPos()-> getElement(i).pos -> x == movePlayer().pos -> x && food -> getFoodPos()-> getElement(i).pos -> y == movePlayer().pos -> y )
        {
            switch(food->getFoodPos()->getElement(i).getSymbol())
            {
                case 'a':
                    (*playerPosList).insertHead(movePlayer());
                    mainGameMechsRef->setScore(1);
                    food -> generateFood(playerPosList);
                    return;

                case 'b':
                    (*playerPosList).insertHead(movePlayer());
                    (*playerPosList).insertHead(movePlayer());
                    mainGameMechsRef->setScore(2);
                    food -> generateFood(playerPosList);
                    return;

                case 'c':
                    (*playerPosList).insertHead(movePlayer());
                    (*playerPosList).insertHead(movePlayer());
                    (*playerPosList).insertHead(movePlayer());
                    (*playerPosList).insertHead(movePlayer());
                    (*playerPosList).insertHead(movePlayer());
                    food -> generateFood(playerPosList);
                    mainGameMechsRef->setScore(5);
                    return;
                    
                case 'd':
                    if(playerPosList -> getSize() < 3)
                    {
                        for(int i1 = 0; i1 < (playerPosList -> getSize())-1; i1++)
                        {
                            playerPosList -> removeTail();
                            
                        }
                        playerPosList -> insertHead(movePlayer());
                        playerPosList -> removeTail();
                        food -> generateFood(playerPosList);
                        return;
                    }
                    else
                    {
                        (*playerPosList).removeTail();
                        (*playerPosList).removeTail();
                        food -> generateFood(playerPosList);
                        return;
                    }

                case 'e':
                    (*playerPosList).insertHead(movePlayer());
                    mainGameMechsRef->setScore(5);
                    food -> generateFood(playerPosList);
                    return;


            }
            
          
        }
           

    }
    (*playerPosList).insertHead(movePlayer());
    (*playerPosList).removeTail();
}