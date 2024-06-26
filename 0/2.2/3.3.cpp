// Завдання 3. Створити чергу з 10-ти цілих чисел, елементи якої введенні користувачем.
// Визначити мінімальний та максимальний елементи черги. Результат вивести в консоль.

#include <iostream>
#include <queue>
#include <limits>

using namespace std;
int main() {
    queue<int> myQueue;
    int n = 10;
    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 1; i <= n; i++) {
        int inputValue;
        cout << "Елемент " << i << ": ";
        cin >> inputValue;
        myQueue.push(inputValue);
        if(inputValue > max) max = inputValue;
        if(inputValue < min) min = inputValue;
    }

    cout << max << " - максимальне\n";
    cout << min << " - мінімальне\n";

    return 0;
}