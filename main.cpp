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

    cout << "���������� ���-�������:" << endl;
    hashMap.print();

    int valueToCheck = 500;
    int valueToCheck2 = 455;
    if (hashMap.contains(valueToCheck)) {
        cout << "�������� " << valueToCheck << " ������� � ���-�������." << endl;
    }
    else {
        cout << "�������� " << valueToCheck << " �� ������� � ���-�������." << endl;
    }
    if (hashMap.contains(valueToCheck2)) {
        cout << "�������� " << valueToCheck2 << " ������� � ���-�������." << endl;
    }
    else {
        cout << "�������� " << valueToCheck2 << " �� ������� � ���-�������." << endl;
    }

    int keyToSearch = 50;
    int* foundValue = hashMap.search(keyToSearch);
    if (foundValue) {
        cout << "�� ����� " << keyToSearch << " ������� ��������: " << *foundValue << endl;
    }
    else {
        cout << "���� " << keyToSearch << " �� ������ � ���-�������." << endl;
    }

    int keyToSearch1 = 60;
    int* foundValue1 = hashMap.search(keyToSearch1);
    if (foundValue1) {
        cout << "�� ����� " << keyToSearch1 << " ������� ��������: " << *foundValue1 << endl;
    }
    else {
        cout << "���� " << keyToSearch1 << " �� ������ � ���-�������." << endl;
    }
    int keyToSearch2 = 70;
    int* foundValue2 = hashMap.search(keyToSearch2);
    if (foundValue2) {
        cout << "�� ����� " << keyToSearch2 << " ������� ��������: " << *foundValue2 << endl;
    }
    else {
        cout << "���� " << keyToSearch2 << " �� ������ � ���-�������." << endl;
    }

    if (hashMap.erase(keyToSearch)) {
        cout << "������� � ������ " << keyToSearch << " ������." << endl;
    }
    else {
        cout << "�� ������� ������� ������� � ������ " << keyToSearch << "." << endl;
    }

    cout << "���������� ���-������� ����� ��������:" << endl;
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

