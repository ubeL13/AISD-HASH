#include <iostream>
#include "head.h" 

int main() {
    UnorderedMap<int, int> myMap(10);

    myMap.insert(5, 555);
    myMap.insert(2, 3);
    myMap.insert(3, 8);

    myMap.print();

    myMap.insert_or_assign(2, 16);
    
    myMap.insert_or_assign(4, 4);
    myMap.print();

    return 0;
}