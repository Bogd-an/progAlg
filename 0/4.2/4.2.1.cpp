// Створити нульовий масив із a цілочислених елементів, де a = 20+N, N –номер варіанту
// за списком. Та вивести його на екран. Створити хеш-функцію, що повертає індекс елемента за
// формулою h (x) = x mod a. Створити функцію, яка записує значення до комірки масива з індексом,
// отриманим за допомогою хеш-функції. Занести до масиву наступні числа: {23; 75; 11; 15; 85; 7; 56}.
// Вивести на екран отриманий масив. Після цього до масиву занести наступні елементи 55 та 76. Та
// знову вивести отриманий масив на екран. Отриману програму, модернізувати за допомогою
// методу лінійного зондування. Використовуючи попередні значення із завдання 1, продемонструвати
// роботу програми.

#include <iostream>
using namespace std;

const int hashTableSize = 20 + 12;

int hashTable[hashTableSize] = {0}; 

int hashFunction(int x) {
    return x % hashTableSize;
}

void add(int value) {
    int hash = hashFunction(value);
    for (int nevHash = hash; nevHash < hashTableSize; nevHash+=2)
        if (hashTable[nevHash] == 0){
            hashTable[nevHash] = value; 
            return; // додали після
        }
    for (int nevHash = 0; nevHash < hash; nevHash+=2)
        if (hashTable[nevHash] == 0){
            hashTable[nevHash] = value;
            return; // додали перед
        }
    cout << "HashTable full, drop " << value << endl;
}

void print() {
    cout << "HashTable: ";
    for (int i = 0; i < hashTableSize; i++)
        cout << hashTable[i] << (hashTable[i]>10?" ":"  ");
    cout << endl;
}

int main() {
    print(); 
    const int values[] = {23, 75, 11, 15, 85, 7, 56};
    for (int i = 0; i < sizeof(values)/sizeof(int); i++)
        add(values[i]);
    print(); 
    add(55); add(76); print();
    return 0;
}

/* Результат
HashTable: 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
HashTable: 0  0  0  0  0  0  0  7  0  0  0  75 11 0  0  15 0  0  0  0  0  85 0  23 56 0  0  0  0  0  0  0
HashTable: 0  0  0  0  0  0  0  7  0  0  0  75 11 76 0  15 0  0  0  0  0  85 0  23 56 55 0  0  0  0  0  0
*/