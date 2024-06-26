// Завдання 3. Створити стек з 10-ти цілих чисел, елементи якого введенні користувачем.
// Останні 3 елементи перемножити між собою. Від отриманого результату послідовно
// відняти решту елементів стеку. Результат вивести в консоль.
#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<int> myStack;
    cout << "Введіть 10 цілих чисел для стеку:\n";
    for (int i = 0; i < 10; ++i) {
        int userInput;
        cout << "Елемент " << i + 1 << ": ";
        cin >> userInput;
        myStack.push(userInput);
    }
    int product = 1;
    while (!myStack.empty()) {
        if(myStack.size() > 10 - 3)
            product *= myStack.top();
        else
            product -= myStack.top();
        myStack.pop();
    }
    cout << "Результат: " << product << endl;
    return 0;
}
