// Завдання 1. Створити стек з 5-ти цілих чисел, елементи якого введенні користувачем.
// Після чого вивести всі значення з стеку в консоль.

#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> myStack;
    cout << "Введіть 5 цілих чисел для стеку: \n";
    for (int i = 0; i < 5; ++i) {
        int userInput;
        cout << "Елемент " << i + 1 << ": ";
        cin  >> userInput;
        myStack.push(userInput);
    }
    cout << "Значення зі стеку: \n";
    while (!myStack.empty()) {
        cout << myStack.top() << "\t";
        myStack.pop();
    }
    return 0;
}