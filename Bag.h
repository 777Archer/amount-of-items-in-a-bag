//David Archer
//Amount of Items in a Bag

#ifndef BAG_H
#define BAG_H

template <class ItemType>
class ArrayBag
{

private:
    static const int DEFAULT_SIZE = 100;
    ItemType items[DEFAULT_SIZE];
    int itemCount;  
    int maxItems;
    int getIndexOf(const ItemType& target) const;

public:
    ArrayBag(); 
    ArrayBag(ItemType* arr, int size);
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const;
    int getFrequencyOf(const ItemType& anEntry) const;
    ArrayBag<ItemType> unionBag(ArrayBag<ItemType>& other);
    ArrayBag<ItemType> intersectionBag(ArrayBag<ItemType>& other);
    ArrayBag<ItemType> differenceBag(ArrayBag<ItemType>& other);
    void Print();
};
#endif