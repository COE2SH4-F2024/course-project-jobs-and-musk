#include "Food.h"

Food::Food()
{   
    foodPoslist = new objPosArrayList();
    objPos temp;
    temp.setObjPos(3,7,'X');
    foodPoslist -> insertHead(temp);
    foodNum = 5;
    foodBin = new objPosArrayList;



}

Food::~Food()
{
    delete foodPoslist;
    delete foodBin;
}
Food:: Food(const Food& other)
{   
    foodBin = new objPosArrayList;
    foodPoslist = new objPosArrayList;
    *foodPoslist = *other.foodPoslist;
    foodNum = other.foodNum;
    *foodBin = *(other.foodBin);
}
Food& Food::operator=(const Food& other)
{   
    *foodBin = *(other.foodBin);
    *foodPoslist = *other.foodPoslist;
    foodNum = other.foodNum;
}

void Food::generateFood(objPosArrayList* playerPos)
{
    srand(time(NULL)); 
    int i;
    objPos foodPos;

    for(i = 0; i < foodNum; i++)
    {   
        while (true)
        {   
            bool flag = false;
            switch(i)
            {
                case 0:
                foodPos.setObjPos(((rand() % 28) + 1),((rand() % 13) + 1),'a');
                break;

                case 1:
                foodPos.setObjPos(((rand() % 28) + 1),((rand() % 13) + 1),'b');
                break;

                case 2:
                foodPos.setObjPos(((rand() % 28) + 1),((rand() % 13) + 1),'c');
                break;

                case 3:
                foodPos.setObjPos(((rand() % 28) + 1),((rand() % 13) + 1),'d');
                break;

                case 4:
                foodPos.setObjPos(((rand() % 28) + 1),((rand() % 13) + 1),'e');
                break;

            }
            


            for(int i1 = 0; i1 < playerPos -> getSize(); i1++)
            {

                if(foodPos.pos -> x == playerPos -> getElement(i1).pos -> x && foodPos.pos -> y == playerPos -> getElement(i1).pos -> y)
                {   
                    flag = true;
                    break;
                }

            }
            
            for(int i1 = 0; i1 < i; i1++)
            {

                if(foodPos.pos -> x == foodBin -> getElement(i1).pos -> x && foodPos.pos -> y == foodBin -> getElement(i1).pos -> y)
                {   
                    flag = true;
                    break;
                }

            }


            if (flag == false)
            {
                foodBin -> setElement(i,foodPos);
                break;
            }
        
        
        
        }
    }
    int index = 0, temp = 0;
    bool flag;
    for(int i3 = 0; i3 < 3;i3++)
    {   flag = true;
        while(flag)
        {   if(i3 >= 1)
            {   
                index = (rand() % 5);
                bool flag2 = true;
                for(int temp1 = 0; temp1 < i3; temp1++)
                {   if(index == foodIndex[temp1])
                    {
                        flag2 = false;
                    }
                }

                if(flag2 == true)
                {   foodPoslist -> setElement(i3, (foodBin->getElement(index)));
                    foodIndex[i3] = index;
                    flag = false;
                }


            }
            else
            {
                index = (rand() % 5);
                foodPoslist -> setElement(i3,foodBin->getElement(index));
                foodIndex[i3] = index;
                flag = false;
            }
        }

    }
}


objPosArrayList* Food::getFoodPos() const
{
    return foodPoslist;
}

int Food::getFoodsNum() const
{
    return foodNum;
}

int* Food::getFoodIndex()
{
    return foodIndex;
}