#include <iostream>
#include "head.h" 
using namespace std;

int main() {
    UnorderedMap<int, int> myMap(10);

    myMap.insert(5, 555);
    myMap.insert(2, 3);
    myMap.insert(3, 8);

    myMap.print();

    myMap.insert_or_assign(2, 16);
    
    myMap.insert_or_assign(4, 4);
    myMap.print();

    bool f = myMap.contains(5);
    if (f == true) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    bool t = myMap.contains(555);
    if (t == true) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    
    int keyToCount = 2;
    int count = myMap.count(keyToCount);
    cout << "Count for key " << keyToCount << ": " << count << endl;

    int keyToErase = 1;
    bool erased = myMap.erase(keyToErase);
    if (erased) {
        cout << "Key " << keyToErase << " erased successfully." << endl;
    }
    else {
        cout << "Key " << keyToErase << " not found." << endl;
    }

    int* valueFound = myMap.search(keyToErase);
    if (valueFound) {
        cout << "Value found for erased key " << keyToErase << ": " << *valueFound << endl;
    }
    else {
        cout << "No value found for erased key " << keyToErase << endl;
    }

    cout << "Map content after operations:" << endl;
    myMap.print();


    return 0;
}