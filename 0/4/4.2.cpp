// Створити нульовий масив із 10 цілочислених елементів. Та вивести
// його на екран. Створити хеш-функцію, що повертає індекс елемента за
// формулою h (x) = x%10. Створити функцію, яка записує значення до комірки
// масива з індексом, отриманим за допомогою хеш-функції. Занести до масиву
// настуані числа: {22; 45; 10; 1}. Вивести на екран отриманий масив. Після цього до
// масиву занести наступні елементи 55 та 76. Та знову вивести отриманий масив
// на екран.

// Модернізувати попередню програму таким чином, щоб запобігти
// виникнення колізії методом лінійної пробації. Використовуючи попередні значення
// із завдання 1, продемонструвати роботу програми.

#include <iostream>
using namespace std;


const int hashTableSize = 10;
int hashTable[10] = {0}; 

int hashFunction(int x) {
    return x % hashTableSize;
}

void print() {
    cout << "HashTable: ";
    for (int i = 0; i < hashTableSize; i++)
        cout << hashTable[i] << " ";
    cout << endl;
}

void add(int value) {
    for (int nevHash = hashFunction(value); nevHash < hashTableSize; nevHash++)
        if (hashTable[nevHash] == 0){
            hashTable[nevHash] = value;
            return; // додали після
        }
    for (int nevHash = 0; nevHash < hashFunction(value); nevHash++)
        if (hashTable[nevHash] == 0){
            hashTable[nevHash] = value;
            return; // додали перед
        }
    cout << "HashTable full, drop " << value << endl;
}

int main() {
    print();
    add(22);add(45);add(10);add(1);
    print();
    add(55);add(76);
    print();
    return 0;
}

/* Результат
HashTable: 0 0 0 0 0 0 0 0 0 0 
HashTable: 10 1 22 0 0 45 0 0 0 0    
HashTable: 10 1 22 0 0 45 55 76 0 0  
*/