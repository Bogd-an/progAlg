// Завдання 2. Створити стек з довільною кількістю цілих чисел, кількість елементів та їх
// значення повинні бути введені користувачем. Просумувати отримані елементи. Результат
// вивести на екран.

#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<int> myStack;
    int myStackLen;
    cout << "Введіть кількість елементів для стеку: ";
    cin >> myStackLen;
    cout << "Введіть цілі числа для стеку:\n";
    for (int i = 0; i < myStackLen; ++i) {
        int userInput;
        cout << "Елемент " << i + 1 << ": ";
        cin >> userInput;
        myStack.push(userInput);
    }
    int sum = 0;
    while (!myStack.empty()) {
        sum += myStack.top();
        myStack.pop();
    }
    cout << "Сума елементів у стеці: " << sum << endl;
    return 0;
}
