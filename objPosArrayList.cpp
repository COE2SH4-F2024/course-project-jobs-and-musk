#include "objPosArrayList.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.
objPosArrayList::objPosArrayList()
{
    arrayCapacity = 250;
    aList = new objPos[250];
    listSize = 0;
}

objPosArrayList::objPosArrayList(const objPosArrayList& this_array)
{
    aList = new objPos[250];
    for(int i = 0; i < 250;i++)
    {
        aList[i] = this_array.aList[i];
    }
    listSize = this_array.listSize;
    arrayCapacity = 250;

}

objPosArrayList& objPosArrayList::operator=(const objPosArrayList& this_array)
{
    for(int i = 0; i < 250;i++)
    {
        aList[i] = this_array.aList[i];
    }
    listSize = this_array.listSize;
    arrayCapacity = 250;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    for(int i = listSize-1; i >= 0; i--)
    {
        objPos temp;
        temp = aList[i];
        aList[i+1] = temp;
    }

    aList[0] = thisPos;
    listSize++;

}

void objPosArrayList::insertTail(objPos thisPos)
{
    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead()
{
    for(int i = 0; i < listSize - 1; i++)
    {
        aList[i] = aList[i+1];
    }
    listSize--;
}

void objPosArrayList::removeTail()
{
    listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index];
}

void objPosArrayList::setElement(int i,objPos temp)
{
    aList[i] = temp;
}