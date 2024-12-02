#ifndef FOOD_H
#define FOOD_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"


class Food
{
    private:

        objPos foodPos;

    
    public:

        Food();
        ~Food();

        objPos getFoodPos() const;
        Food& operator=(const Food& other);
        Food(const Food& other);

        void generateFood(objPosArrayList* playerPos);


};

#endif


