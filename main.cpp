#include <iostream>
#include <clocale>
#include <string>
#include "head.h" 
#include <vector> 
using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
    const size_t tableSize = 10;
    const size_t numElements = 10;
    const int keyMin = 1;
    const int keyMax = 100;
    const int valueMin = 500;
    const int valueMax = 600;


    UnorderedMap<int, int> hashMap(tableSize, numElements, keyMin, keyMax, valueMin, valueMax);

    hashMap.insert(50, 555);
    hashMap.insert(70, 455);
    hashMap.insert(80, 155);

    hashMap.insert_or_assign(80, 255);
    hashMap.insert_or_assign(25, 435);

    cout << "Содержимое хэш-таблицы:" << endl;
    hashMap.print();

    int valueToCheck = 500;
    int valueToCheck2 = 455;
    if (hashMap.contains(valueToCheck)) {
        cout << "Значение " << valueToCheck << " найдено в хэш-таблице." << endl;
    }
    else {
        cout << "Значение " << valueToCheck << " не найдено в хэш-таблице." << endl;
    }
    if (hashMap.contains(valueToCheck2)) {
        cout << "Значение " << valueToCheck2 << " найдено в хэш-таблице." << endl;
    }
    else {
        cout << "Значение " << valueToCheck2 << " не найдено в хэш-таблице." << endl;
    }

    int keyToSearch = 50;
    int* foundValue = hashMap.search(keyToSearch);
    if (foundValue) {
        cout << "По ключу " << keyToSearch << " найдено значение: " << *foundValue << endl;
    }
    else {
        cout << "Ключ " << keyToSearch << " не найден в хэш-таблице." << endl;
    }

    int keyToSearch1 = 60;
    int* foundValue1 = hashMap.search(keyToSearch1);
    if (foundValue1) {
        cout << "По ключу " << keyToSearch1 << " найдено значение: " << *foundValue1 << endl;
    }
    else {
        cout << "Ключ " << keyToSearch1 << " не найден в хэш-таблице." << endl;
    }
    int keyToSearch2 = 70;
    int* foundValue2 = hashMap.search(keyToSearch2);
    if (foundValue2) {
        cout << "По ключу " << keyToSearch2 << " найдено значение: " << *foundValue2 << endl;
    }
    else {
        cout << "Ключ " << keyToSearch2 << " не найден в хэш-таблице." << endl;
    }

    if (hashMap.erase(keyToSearch)) {
        cout << "Элемент с ключом " << keyToSearch << " удален." << endl;
    }
    else {
        cout << "Не удалось удалить элемент с ключом " << keyToSearch << "." << endl;
    }

    cout << "Содержимое хэш-таблицы после удаления:" << endl;
    hashMap.print();
    /*cout << "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111" << endl;
    std::vector<int> vec = generateRandomVector();
    for (int i = 0; i < size(vec); i++) {
        cout << vec[i] << endl;
    }
    UnorderedMap<int, int> table = count_numbers(vec);
    print_numbers_count(table);*/
    return 0;

}

