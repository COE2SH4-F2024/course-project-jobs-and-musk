#ifndef FOOD_H
#define FOOD_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"


class Food
{
    private:

        objPosArrayList* foodPoslist;
        int foodNum;

    
    public:

        Food();
        ~Food();

        objPosArrayList* getFoodPos() const;
        Food& operator=(const Food& other);
        Food(const Food& other);
        int getFoodsNum() const;
        objPosArrayList* foodBin;
        int foodIndex[3];
        int* getFoodIndex();
        



        void generateFood(objPosArrayList* playerPos);


};

#endif


