// Завдання 1. Створити чергу з 5-ти цілих чисел, елементи якої введенні користувачем.
// Після чого вивести всі значення з черги в консоль.

#include <iostream>
#include <queue>

using namespace std;
int main() {
    queue<int> myQueue;
    int n = 5;

    for (int i = 1; i <= n; i++) {
        int inputValue;
        cout << "Елемент " << i << ": ";
        cin >> inputValue;
        myQueue.push(inputValue);
    }

    cout << "Значення в черзі: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }

    return 0;
}
