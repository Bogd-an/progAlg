// Завдання 2. Створити чергу з довільною кількістю цілих чисел, кількість елементів та їх
// значення повинні бути введені користувачем. Парні елементи черги збільшити вдвічі.
// Результат вивести на екран.

#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> myQueue;
    int n;

    cout << "Кількість елементів черги: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int inputValue;
        cout << "Елемент " << i << ": ";
        cin >> inputValue;
        if (i % 2 == 0) inputValue *= 2;
        myQueue.push(inputValue);
    }

    cout << "Значення в черзі: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }

    return 0;
}
// Приклад роботи:
// Кількість елементів черги: 5
// Елемент 1: 1
// Елемент 2: 2
// Елемент 3: 3
// Елемент 4: 4
// Елемент 5: 5
// Значення в черзі: 1 4 3 8 5 
