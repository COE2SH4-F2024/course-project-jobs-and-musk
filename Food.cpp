#include "Food.h"

Food::Food()
{   
    foodPos.pos->x = 2;
    foodPos.pos->y = 3;

    foodPos.setObjPos(2,3,'X');
}

Food::~Food()
{

}
Food:: Food(const Food& other)
{   
    foodPos = other.foodPos;
}
Food& Food::operator=(const Food& other)
{
        foodPos = other.foodPos;
}

void Food::generateFood(objPosArrayList* playerPos)
{
    srand(time(NULL)); 



    while (true)
    {   
        bool flag = false;
        foodPos.pos -> x = (rand() % 28) + 1;
        foodPos.pos -> y = (rand() % 13) + 1;

        for(int i = 0; i < playerPos -> getSize(); i++)
        {

            if(foodPos.pos -> x == playerPos -> getElement(i).pos -> x && foodPos.pos -> y == playerPos -> getElement(i).pos -> y)
            {   
                flag = true;
                break;
            }

        }

        if (flag == false)
        {
            break;
        }
       

       
    }

}


objPos Food::getFoodPos() const
{
    return foodPos;
}