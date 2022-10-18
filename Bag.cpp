//David Archer
//Amount of Items in a Bag

#include "Bag.h"
#include "BagTest.cpp"

using namespace std;

int main(void) 
{
    ArrayBag<char> bag1;
    bag1.add('a'); bag1.add('b'); bag1.add('c');

    ArrayBag<char> bag2;
    bag2.add('b'); bag2.add('b'); bag2.add('d'); bag2.add('e');

    cout << "The bag contains items:\n";
    (bag1).Print();
    cout << endl;

    cout << "The bag contains items:\n";
    (bag2).Print();
    cout << endl;

    cout << "Intersection of two bags. \nThe bag contains item:\n";
    bag1.intersectionBag(bag2).Print();
    cout << endl;

    system("PAUSE");
    return 0;
}