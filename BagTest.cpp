//David Archer
//Amount of Items in a Bag

#include <iostream>
#include <cmath>
#include <vector>
#include "Bag.h"

using namespace std;

template <class ItemType>
ArrayBag<ItemType>::ArrayBag()
    : itemCount(0),
    maxItems(DEFAULT_SIZE)
{}


template <class ItemType>
ArrayBag<ItemType>::ArrayBag(ItemType* arr, int size)
    : itemCount(0),
    maxItems(DEFAULT_SIZE)
{

    for(int num1 = 0; num1 < size; ++num1)
    {
        add(arr[num1]);
    }
}

template <class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const 
{
    return itemCount;
}  

template <class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
    return itemCount == 0;
}  

template <class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry) 
{
    bool hasRoomToAdd = (itemCount < maxItems);
    if(hasRoomToAdd) 
    {

        int num1 = itemCount;
        while (num1 > 0 && items[num1 - 1] > newEntry)
        {
            items[num1] = items[num1 - 1];
            --num1;
        }

        items[num1] = newEntry;
        ++itemCount;
    } 

    return hasRoomToAdd;
} 


template <class ItemType>
void ArrayBag<ItemType>::Print() 
{
    int curIndex = 0;
    while(curIndex < itemCount) 
    {
        cout << items[curIndex] << " ";
        curIndex++;
    }
    cout << endl;
}

template <class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry) 
{
    int locatedIndex = getIndexOf(anEntry);
    bool canRemoveItem = !isEmpty() && (locatedIndex > -1);

    if(canRemoveItem) 
    {
        --itemCount;
        items[locatedIndex] = items[itemCount];
    }  
    return canRemoveItem;
}  


template <class ItemType>
void ArrayBag<ItemType>::clear() 
{
    itemCount = 0;
}  

template <class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const 
{
    int frequency = 0;
    int curIndex = 0;

    while(curIndex < itemCount)
    {
        if(items[curIndex] == anEntry) 
        {
            ++frequency;
        } 
        ++curIndex;
    } 

    return frequency;
} 

template <class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
    return getIndexOf(anEntry) > -1;
} 

template <class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const 
{
    bool found = false;
    int result = -1;
    int searchIndex = 0;

    while(!found && (searchIndex < itemCount)) 
    {
        if(items[searchIndex] == target) 
        {
            found = true;
            result = searchIndex;
        }
        else 
        {
            searchIndex++;
        }
    } 

    return result;
} 

template <class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::unionBag(ArrayBag<ItemType>& other) 
{
    ArrayBag<ItemType> result;

    int curIndex = 0;
    while(curIndex < itemCount) 
    {
        result.add(items[curIndex]);
        ++curIndex;
    }
    curIndex = 0;
    while(curIndex < other.itemCount) 
    {
        result.add(other.items[curIndex]);
        ++curIndex;
    }
    return result;
}
template <class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::intersectionBag(ArrayBag<ItemType>& other) 
{
    ArrayBag<ItemType> result;

    int curIndex = 0;
    while(curIndex < itemCount) 
    {
        if(other.contains(items[curIndex]))
        {
            result.add(items[curIndex]);
        }
        ++curIndex;
    }
    return result;
}

template <class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::differenceBag(ArrayBag<ItemType>& other)
{
    ArrayBag<ItemType> result;

    int curIndex = 0;
    while(curIndex < itemCount) 
    {
        if(!other.contains(items[curIndex])) 
        {
            result.add(items[curIndex]);
        }
        ++curIndex;
    }
    return result;
}